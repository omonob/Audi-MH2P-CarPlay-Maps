# 实现链路与功能边界

资料标签 2026-10-24；本候选适配说明整理于 2026-11-04。下述调用链来自已有包的静态分析，不是本候选的实车执行跟踪。

## 1. 原生副屏，不是主屏截图搬运

```text
iPhone 的 CarPlay Type 111 副屏
  → 原厂 AirPlay／iAP2 会话与独立视频传输
  → libcarplay_altscreen_hook.so 接入原厂屏幕会话接口
  → OEM StartSession／ProcessFrames 与原厂解码／显示后端
  → DInt 窗口请求与 Java／DSI 显示组合
  → 仪表手机副屏
```

没有证据表明本 hook 自行完成 H.264→RGB 软件解码或把中控屏截图逐帧复制到仪表。原厂同 train 的 AirPlay／DInt 后端没有随研究包提供，因此不能把 MHI2Q 的 Qualcomm OMX 实现写成 MH2P 的内部事实，也不能把 hook 反编译代码当成完整原厂解码器。

已有静态资料中，DInt 请求窗口 59 映射到显示组合中的 62；33 是原厂地图层。它们不是跨平台常量，不能照搬到 MHI2／MHI2Q。窗口注册、`registered`、DSI 组合确认、KDK ready 和真实可见首帧必须分别验证。

## 2. 导航数据与小卡片呈现分开

```text
CarPlay／iAP2 导航消息
  → libcarplay_rgi_hook.so 解析与状态发布
  → /tmp/cluster_cp.state 等原有接口
  → Java 导航集成、CombiBAPServiceNavi、Komo 与 ETA 接口
```

保留道路／城市、机动与转向、下一机动距离及单位、剩余距离／时间、车道、环岛、ETA、导航开始／停止及缩放接口。字段保留不等于所有手机地图 App 都会发送全部字段，也不等于仪表已显示了这些数据。

本变体沿用已经完成的无卡片 Java 改造，保留 `publishPhoneEta`、`pushKomoNavInfo`、`startRouteGuidance`、`stopRouteGuidance`、`releaseNavOnPhoneClaim`、`handleScreenOwnerChange` 和 `pollNativeSessionGeneration` 等原有实现。新通用适配没有改这些 class 的任何字节。

排除项包括 `libnav_dint_hook.so`、navigation 的 DInt／EGL 启动包装器、`ctl.bundle`、plate／pos 和 RGI 卡片布局素材。Java 的卡片握手／图形提示类 `$10`、`$11` 已排除；KDK 图形入口仅有无操作兼容桩；显示组合过滤卡片 20，但保留手机副屏 62 和其他既有元素。导航数据发布与卡片 presentation 状态解耦，不能删掉整套 RGI 消息处理来“去卡片”。

## 3. 启动与地图切换

新安装器把独立 JAR 加入原有 HMI boot classpath 的前部，并安装一个可阅读的 `dio_manager` 启动 shim。原生 decoder 本体保存为本机专用的 `dio_manager.mh2p-test-stock`，shim 最终 `exec` 它并转交原参数。新库只在原有 mode 值为 `altscreen` 时加载；加载顺序是 AltScreen hook、RGI 数据 hook，再接原环境已有的预加载内容。

沿用原启动器已经使用的环境值：`CP_RGI_ENABLE=1`、`CP_RGI_INJECT=1`、`CP_RGI_START_API=1`、`CP_RGI_START_DEPLOY=0`。其中最后一项不能改为启动卡片部署。原厂地图／手机副屏切换和 BACK 长按处理继续使用现有 Java／DSI 逻辑；不能把“切换接口存在”写成“手机导航时原厂罗盘问题已解决”。

## 4. 通用测试适配到底改了什么

| 层 | 新候选变更 | 保留的界限 |
| --- | --- | --- |
| SD 安装 | 外置明文 payload；原更新入口所需的可逆 XOR 封装仍保留 | 不修改原签名 Meta 和更新脚本，不宣称新 payload 获得原厂签名 |
| Java | `DeviceBinding.isAuthorized()` 为测试候选常量返回；移除四个绑定片段类 | 其余 67 个 class 逐字节不变；不改变导航、显示、按键或计时 |
| Native | 两个库各自测试绑定入口改为 Thumb 返回 1，并清零各 128 字节绑定记录 | 其他字节不变；不改原厂 AirPlay 配对安全接口或视频处理 |
| 系统安装 | 备份本机入口、安装自有目录与 JAR、修改一个 classpath 入口 | 不安装工程挑战服务／autorunner，不关闭 SSH 或网卡，不修改导航程序、历史记录或服务管理器 |

取消本项目的设备锁不是启用原车未授权功能的证明。测试车应已经具备合法、正常可用的原厂 CarPlay 和相应导航／仪表能力。本包不提供原厂授权、配对凭据或第三方账号材料。

## 5. 性能及无线声明

`maxFPS=60` 或 59 Hz 字段只是协商／配置，不能替代真实 FPS、丢帧、带宽或可见画面的采样。这一轮没有实车性能测量，也没有声称新增无线接收器、USB／无线双覆盖或全部 iPhone 兼容。
