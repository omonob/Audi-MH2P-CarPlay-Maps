# MH2P CarPlay 仪表投屏：底层运行逻辑

[English](RUNTIME_INTERNALS.en.md) · [项目说明](../README.md) · [完整版来源](UPSTREAM_AND_FULL_EDITION.md)

说明更新：**2026-11-07，Asia/Shanghai**。历史资料标签：2026-10-24；完整样本离线分析：2026-11-01；无卡片通用 V1 适配：2026-11-04。

## 1. 本文解释的是哪一套实现

本文把已有 MH2P 样本的**视频、显示控制、导航数据、卡片呈现**四部分分开说明。大量实现基础和研究材料来自 [audijiJQ / AUDIJI](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps) 的程序，不能视作本项目从零原创。本文为独立撰写的技术解释，不附加发布完整第三方源码。

主要证据是已有二进制的反汇编／反编译和 Java class 分析；不是本轮实车跟踪，也不是原作者完整源码。以下必须区分：

- **历史完整样本**：包含卡片渲染与平台呈现，可用于解释完整链路。
- **本仓库 V1**：沿用同一研究基础，但明确排除了卡片绘制链，只保留视频与导航数据接口。
- **原作者新公开 ZIP**：本轮只核对结构、CRC 和 SHA256；未执行或恢复其最新运行库。不能把历史样本的函数、偏移和行为直接写成新包已验证事实。

涉及窗口、尺寸和显示 ID 的数值都限定于被分析的 MH2P 样本。不得复制到 MHI2、MHI2Q 或其他 MH2P 固件后直接使用。

## 2. 先看完整系统的四条关系

```text
iPhone 的 CarPlay 会话
  ├─ Type111 独立视频 → AltScreen hook → OEM Screen 接收/解码 → DInt 62 ─┐
  └─ 导航元数据 → RGI 数据 hook → 状态发布 → Java maneuver/BAP/Komo ─┐ │
                                                                   │ │
历史完整样本：navigation + nav_dint hook → EGL/KDK 导航提示 → DInt 20 ┘ │
                                                                     │
Java DisplayManager / DSI：保留 OEM context，组合地图33、副屏62、提示20 ─┘
  → OEM 显示服务与仪表输出
```

这不是“中控画面截一张图，再复制到仪表”。手机为 Type111 副屏产生独立视频；导航箭头和文字还可以走平台数据／卡片链。仅有视频、仅有箭头、窗口创建成功但画面黑屏，都是可能出现的不同状态。

## 3. 各组件分别做什么

| 组件 | 责任 | 不应误认为 |
| --- | --- | --- |
| `dio_manager` 及启动 shim | 在目标进程启动时接入动态库，再运行本机原 decoder 入口 | 一个独立重写的完整解码器 |
| `libcarplay_altscreen_hook.so` | 副屏能力、独立会话／TCP 交接、时间同步接入、DInt 窗口适配 | 中控截图器或已证实的软件 H.264 解码器 |
| `libcarplay_rgi_hook.so` | 导航能力／消息处理和状态发布 | 可以因为删除卡片而整库删除的绘图库 |
| `CarPlayDSIManager` / `CarPlayClusterIntegration` | 会话状态、显示生命周期、导航服务集成、状态读取 | 原厂视频解码器 |
| `CarPlayManeuverMapper` | 手机机动类型、角度和方向到平台 descriptor 的转换 | 单一箭头图片资源 |
| `DisplayManager` / DSI | 仪表 context、displayable 组合、确认与原地图恢复 | 把逻辑编号直接当物理屏幕端口 |
| 历史完整样本的 `navigation_dint_launcher`、`libnav_dint_hook.so` | 在 navigation 进程内接入 DInt／EGL 的导航提示呈现 | Type111 视频收包或 H.264 解码 |
| plate／pos／layout 控制 | 卡片底板、形状、位置及布局选择 | 手机副屏视频分辨率本身 |

## 4. 开机加载：Java 和 Native 两边都需要

Native hook 必须加载在实际调用原厂接收／显示接口的目标进程里；把 `.so` 放到磁盘上并不代表它已经参与处理。Java 侧也必须真的从 classpath 加载候选 class，才能协同显示组合和导航数据。

现有无卡片 V1 安装器把独立 JAR 放到专用位置，并在既有 HMI boot classpath 前部增加入口。`dio_manager` shim 保留原参数，最后 `exec` 本机备份的原 decoder；只有既有模式值为 `altscreen` 时，才接入 AltScreen 和 RGI 数据 hook，再保留原有 preload 内容。其配置包括 `CP_RGI_ENABLE=1`、`CP_RGI_INJECT=1`、`CP_RGI_START_API=1`、`CP_RGI_START_DEPLOY=0`，最后一项并不启动卡片部署。

历史完整包还涉及 navigation 启动包装、卡片 hook、布局控制等依赖，不能只把 V1 的最后一个变量改成 1 就声称恢复完整功能。旧原安装器还具有关闭维护网口／SSH 等副作用；不能把旧脚本作为新包的安全迁移方案直接复用。见[安装与恢复](INSTALL_AND_RECOVERY.md)。

## 5. 手机为什么会产生仪表画面

在能力查询阶段，hook 对 `AirPlayCopyServerInfo`、平台属性等入口进行适配，追加独立副屏描述。历史样本声明的是 1920×600、物理尺寸 293×92、`maxFPS=60` 和副屏标识，并有多个 viewArea／safeArea 配置。

这些字段告诉手机“有这样一块显示区域，可按这些约束排版”，而不是由车机把中控图像压缩到仪表。像素宽高、物理尺寸、安全区和当前布局承担不同职责。它们不等于接收端已经建好窗口，也不证明手机开始送帧。

样本存在运行期 viewArea 更新。修改绘图区可能让手机重新排版，但不能用该能力替代接收、解码或显示组合。卡片位置文件则属于另一个平台呈现坐标层；不能混用这两组参数。

## 6. SETUP 与独立视频通道

历史 hook 先调用原 `AirPlayReceiverSessionSetup`，再处理满足条件的 `type=111` 副屏分支，读取有效的 `streamConnectionID`。它建立**独立的 Screen 对象**，而不是覆盖主屏对象。

主要调用顺序为：

```text
原 SessionSetup
  → 副屏 Screen_Create / Screen_Setup
  → 复用当前配对会话进行密钥派生并设置 Screen 安全上下文
  → 建立独立 TCP listener，响应副屏 dataPort
  → 手机连接 → SocketAccept → NetSocket_CreateWithNative
  → 等待同一主会话的 StartSession 成功
  → 设置时间同步 → StartSession → UpdateState(1) → ProcessFrames
```

历史分支使用 `PairingSessionDeriveKey` 和 `Screen_SetChaChaSecurityInfo`。这描述手机媒体会话的安全机制，不是安装包挑战码，也不是绕过 OEM CarPlay 授权。没有在文档中分发配对密钥、设备身份或原厂授权材料。

不能从这个分支直接推定所有 USB／无线路径都已兼容。实际手机、固件、配对和传输组合必须分别记录。新上游 ZIP 的绑定变化也不等于改变了手机媒体安全机制。

## 7. 为什么要等主会话、传时间同步对象

副屏启动依赖同一 Session 的原主会话状态和 context。样本用条件变量等待主屏 `StartSession`，并用线程局部标记区分原主屏调用和副屏调用，避免互相误判。

时间同步通过原厂 AirTunesClock 相关回调提供同步 NTP 时间及 ticks。随意用本地系统时间替换，不能保证媒体时序一致。`StartSession` 返回成功只是接口层成功，不是主屏或副屏第一帧已显示。

`ProcessFrames` 得到的是副屏对象、原厂 NetSocket 和会话参数，**不是把某一张 RGB 图交进去**。在已分析的 hook 范围内，持续接收和帧处理被交给 OEM 实现。TCP fd 的所有权在封装后转交，停止侧另外保留用于唤醒的 fd；不能让两条路径重复关闭同一资源。

## 8. 解码、CPU 和 GPU：已知与未知

可确认的是本 hook 调用原厂 `AirPlayReceiverSessionScreen_*` 接口，委托 OEM 接收／解码／显示后端。没有发现该 hook 自己逐帧做 H.264→RGB 软件解码再搬运中控截图的实现。

但研究材料缺少同版本 MH2P 原厂后端的完整实现，因此尚不能在这里证实具体解码引擎、OMX 组件名、CPU/GPU 分工、零拷贝、buffer 数量和最终硬件扫描路径。**不能把 MHI2Q 的 Qualcomm OMX/NV12/RGB 快照链路写成 MH2P 的事实。**“复用原厂解码”也不等于所有环节零 CPU 开销。

卡片 hook 接入 EGL 呈现阶段，并不说明它解码视频；图形 API 的出现也不能单独证明端到端硬件加速或零拷贝。

## 9. DInt 与 Java/DSI：有视频窗口还不够

样本拦截 `dint_create_window`：只在匹配副屏归属或严格几何条件的情况下，把原请求 59 映射为 displayable 62；其他窗口保持原编号。成功后发布窗口状态，Java 再请求仪表显示管理器把该元素放入当前 context。

| 编号空间 | 样本含义 |
| --- | --- |
| Type110 / Type111 | 媒体协议中的主屏／副屏流类型，不是 DInt 窗口号 |
| 59 → 62 | 目标副屏的 DInt 窗口／displayable 适配 |
| 33 | 被保留的原厂地图 displayable |
| 20 | 完整样本中平台 KDK／RGI 导航提示 displayable |
| external terminal 1 → internal display 4 | 本版 Java／DSI 的仪表映射，和 59/62 不是同一编号体系 |

`DisplayManager` 基于当前原厂 context 保留其他元素，加入 62；完整样本如存在 20，则调整组合顺序以配合卡片。它调用 `showDisplayables` 并等待匹配 sessionID 的 `showDisplayablesResult`，核对实际返回列表，不把请求发出当作显示确认。

地图选择使用原厂地图 33 和手机副屏 62 的组合／透明度控制。它不是停止 CarPlay 接收器，也不是选择某个物理显示器。源码里出现过的调用还要核对分支是否可达；例如存在位置设置代码，不等于运行时一定执行。

## 10. 控制文件、代次和状态机

Java 通过 `/tmp/cluster_ctl` 写入带请求编号的控制状态，Native 通过 `/tmp/cluster_mirror.state` 回报。请求与确认要对应同一 req；进程／stream generation 用于区分本轮和旧会话，防止读取上一轮残留后误判成功。

```text
会话可用 → 请求 rendering → starting → registered
  → 请求 DSI 组合 → 匹配组合确认 → 短时健康检查 → 持续显示
会话退出／显示关闭／代次变更
  → 停止旧请求 → 确认 idle/released → 恢复原 context
```

| 观察 | 可以说明 | 还不能说明 |
| --- | --- | --- |
| 副屏端口已返回 | SETUP 提供了通道 | 手机已连入或送帧 |
| `registered` | 副屏 DInt 窗口已创建 | 视频首帧可见 |
| DSI 确认列表含 62 | 显示管理器接受该组合 | 内容非黑、帧在更新 |
| `/tmp/carplay_kdk.ready` | 导航／KDK 提示链的准备信号 | Type111 视频解码成功 |
| `maxFPS=60` | 申报／请求上限 | 实测 60 FPS、60 Hz 或带宽 |

不能拿另一代会话的 ACK 或缓存文件代替本轮注册／退出证据。

## 11. 导航信息怎样变成箭头

`libcarplay_rgi_hook.so` 在导航相关的 iAP2／AirPlay 消息与 transport 入口处理能力和状态，解析后发布 `/tmp/cluster_cp.state`。Java 读取状态，再送入平台导航服务。处理范围包括道路／城市、转向道路、机动类型、方向／角度、下一机动距离及单位、目的地剩余距离和时间、ETA、车道、环岛及导航启停。

**箭头不是只有一个开关或一张位图。** 历史 Java 的 `CarPlayManeuverMapper` 把手机机动类型等输入转换为平台需要的 maneuver 与方向；`CarPlayClusterIntegration` 构造平台 descriptor 并更新 `CombiBAPServiceNavi`。Komo／原厂导航集成另行发布街道、距离和导航状态。

```text
手机机动类型 + 转向角度／方向 + 环岛信息
  → maneuver 映射
  → 平台 maneuver descriptor + 距离／单位 + 道路文字
  → CombiBAP / Komo / 导航服务
  → 平台箭头、文字、车道与卡片呈现
```

这条路径还涉及 `updateLaneGuidance`、`publishPhoneEta`、`pushKomoNavInfo`、导航开始／停止和状态清理。接到一个转向符号并不代表 ETA、车道和环岛出口都正确；各字段也取决于手机地图 App 实际提供的内容。

BAP／Komo 在本文中指已看到的服务接口；没有据此宣称 hook 直接向某条物理 CAN/MOST 总线发送原始报文。反编译中出现接口，也不等于本轮已在仪表上验证其输出。

## 12. 卡片到底由谁画，为什么不等于手机视频

在**这个 MH2P 历史完整样本**里，导航数据经 Java 和原厂导航服务交给平台提示链；`libnav_dint_hook.so` 加载进 navigation 进程，在 DInt／EGL 生命周期和合适的 `eglSwapBuffers` 阶段配合绘制／清理 RGI 叠加，发布 KDK ready，displayable 20 再与地图／视频层协同。

因此，这个卡片路径不能写成“所有内容都是 iPhone 随视频一起画好”。手机负责视频和导航状态来源；平台的 descriptor、服务、提示层和 hook 参与本样本的卡片呈现。其他平台用手机 viewArea 声明产生的卡片，是另一个实现，不应混为一谈。

完整依赖包括导航数据 hook、Java maneuver／导航集成、原厂 BAP／Komo 服务、navigation 包装与 hook、DInt/EGL、卡片底板／布局及显示组合。只恢复某一个 `.so`，可能出现有数据无提示、黑底板、卡片被遮挡或旧层残留。

本仓库旧 V1 的去卡片改造保留数据接口，但排除了卡片绘制库、包装器、plate／pos、Java presentation 等部分。因此旧 V1 不会因为本次增加说明文档就出现完整卡片。

## 13. 布局、尺寸和位置是不同层

历史样本的控制材料包含 `sport_big`、`sport_small`、`classic_big`、`classic_small` 的 plate／pos 和布局切换脚本。它们配合当前仪表空间安排卡片，并不是四份不同的视频解码器。

- Type111 声明的像素／物理尺寸影响手机副屏排版。
- viewArea／safeArea 约束手机绘图区。
- plate 控制平台卡片底板、形状及相关绘制参数。
- pos 控制提示位置；历史脚本说明位置在下一次 route push 生效，而底板按帧重读。
- DSI context 和层顺序决定卡片／地图是否被仪表布局遮挡。

这些参数必须结合目标固件、实际布局和截图验证。历史布局脚本的即时／延迟生效描述不能直接当作新上游包的运行承诺；也不能复制 MU1003 的全屏／经典映射来代替 MH2P 验证。

## 14. 按键、地图选择与缩放

历史样本存在约 2 秒的 BACK 长按处理，用于切换原厂地图 33 与手机副屏 62，并保持副屏会话。短按回传及长按消费需按当前状态处理，避免一次按键重复动作。

滚轮在副屏被选中时，通过导航缩放接口／控制路径转发 `changeMapZoomLevel`。它不是重编码视频，也不是默认控制手机的全部 UI。

**现有地图切换不等于中控镜像。** 将中控主画面复制到仪表需要独立的主屏输出接入、对象归属、显示路由、输入／生命周期验证；后续长按镜像计划不能仅靠把已有 BACK 功能改个名字来完成。

## 15. 停止、重连与原厂地图恢复

样本停止路径先标记本轮退出、唤醒条件等待和阻塞接收，再收束 worker、停止／释放 Screen 对象，并清理本轮窗口状态。新一轮不能复用仍在处理中的旧 Screen 指针、fd、请求编号或显示确认。

Java 同时处理 session／stream 代次和原 context 恢复；对退出后才到达的旧 `registered` 或确认，不能再次进入显示。恢复地图需要确认原组合和可见性，而不是只结束进程。

连接、静止页面、旋钮操作、返回原车、真正断开、再连接和冷启动是不同测试。进入原车界面可能只是释放／切换前台显示，并不代表手机会话和副屏都断开。不能因为仪表仍显示就断言中控输入或主视频仍健康。

## 16. 性能、音频和无线的边界

手机画面静止时帧数可能下降；协商上限、输入帧、解码完成、提交、合成刷新和屏幕扫描分别计数才有意义。带宽应分清媒体有效载荷、TCP／无线开销、平均／峰值，以及 Wi-Fi 链路速率；链路速率不是视频实际吞吐。

本轮未测 MH2P 实际 FPS、延迟、丢帧、峰值带宽或解码负载，也没有新增无线接收器。不能把 MHI2Q 无线试验、另一设备的 59 Hz 或原作者的新包声明换成本候选的结果。

音频不因 Type111 视频和导航数据接通就自动改变。未来 Apple 生态音频／环绕效果必须单独核实传输、格式、声道、授权接口、解码／渲染及硬件输出；蓝牙立体声、效果处理和真实多声道／空间音频不是同一件事。目前没有实现或认证承诺。

## 17. 排查时怎样定位到具体阶段

| 现象 | 应先核对 | 不要直接下的结论 |
| --- | --- | --- |
| 手机没有副屏流 | 能力响应、同一 session 的 SETUP、type/connectionID | 直接认定显示分辨率错误 |
| 有端口但没有视频 | TCP 连入、安全上下文、主屏启动门槛、ProcessFrames 生命周期 | 仅凭 listener 认定已连接 |
| 窗口已注册但黑屏 | 同代次帧活动、OEM 接收结果、DSI 列表与层可见性 | `registered` 等于播放成功 |
| 地图有，箭头无 | 导航消息、mapper、BAP/Komo、卡片是否在该变体中存在 | 删除 RGI 数据库或重新解码视频 |
| 箭头有，车道／ETA 不全 | App 字段、单位、导航状态和对应发布接口 | 一个符号成功等于全部导航正确 |
| 黑卡片或缺角 | 原 context、displayable20、底板与 EGL 状态、退出清理 | 无证据地修改视频 buffer |
| 重连首帧异常 | generation、旧请求／ACK、对象与 fd 退休、主屏门槛 | 反复清配对或复制其他平台偏移 |
| UI 退出但副屏在 | 前台资源／输入状态与会话状态分开检查 | 一律当作手机已断开 |

## 18. 验证与证据索引

本次新增文档不新增实车结果。旧 V1 的离线验证见[验证状态](VALIDATION.md)、`validation/JAVA_VARIANT.json`、`validation/NATIVE_PATCHES.json` 和其他既有记录。历史完整样本的代表输入为 AltScreen hook SHA256 `ab20bb0316c71971a6f591ef090dce1e13c1422c082ceb03209d22ebd9cda17a`，不是新上游 ZIP 的函数级验证。

可在已发布范围内阅读 `research` 的 Java／Native 分析，但它们不包含旧 V1 排除的完整卡片链。本文关于该完整链的描述来自既有本地研究，不表示对应第三方源码已作为本次附件发布。[来源记录](UPSTREAM_AND_FULL_EDITION.md)固定了新公开包的 URL、提交与哈希，便于避免混版本。

后续完整候选至少应分项验收：真实库／class 加载、主屏和副屏首帧、每种布局、所有卡片组合、各类机动与距离单位、车道与 ETA、停止／重连／冷启动、BACK／缩放、USB／无线分别验证、卸载与断电恢复。每次记录**确切载荷哈希、目标固件、手机/App、测试日期、可见画面与恢复结果**；禁止用静态接口、模拟执行或另一个平台的成功替代这些验收。
