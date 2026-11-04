# Audi MH2P CarPlay Maps — 通用包 V1 测试版

发布版本：`v1.0.0-test.1`（V1 测试版）。资料版本标签沿用 **2026-10-24**；交接、适配与本轮离线检查日期为 **2026-11-04**。真正发布时间以 GitHub Release 的时间记录为准。

V1 公开版沿用此前离线验证的功能载荷，内部构建标识仍为 `2026.10.24-universal-test.1`；安装日志中的该标识正常，不代表下载错包。这次不增加投屏功能修改，也没有新增实机验证结论。

这不是正式版，也不是已经证明兼容所有 MH2P 的安装包。**“通用”只指新候选不再需要原设备的挑战码、FAZIT 或 UID 绑定**，不代表跨处理器、跨固件或跨品牌通用。

本仓库按维护者 2026-11-04 的明确指令公开，所有人可查看和下载 V1 测试版。它是 MH2P 独立项目，不使用或更改 MHI2、MHI2Q 的奥迪仓库。公开可见不等于正式版、所有固件兼容或取得包内全部模块的统一开源许可。

## 保留与排除

- 保留 CarPlay 原生 Type 111 仪表副屏，以及原厂地图／手机副屏切换和原有 BACK 长按处理。
- 保留导航消息解析、道路、转向、距离、车道、ETA、BAP／Komo 和缩放接口。
- **不包含导航小卡片**：没有卡片绘制库、navigation 包装器、plate／pos 布局素材或 Java 卡片呈现实现。`libcarplay_rgi_hook.so` 是导航数据接口库，不因名字有 RGI 就删除。
- 不新增无线 CarPlay 接收器。USB／无线是否可用、实际首帧、罗盘状态转换和帧率，都需要本候选的实机验证。

## 安装候选

在 [V1 测试预发布](https://github.com/omonob/Audi-MH2P-CarPlay-Maps/releases/tag/v1.0.0-test.1) 下载 `MH2P_CarPlay_SD_Universal_V1_Test_NoCard_20261024.zip`，核对同批 `SHA256SUMS.txt`。解压后的 `Data` 和 `Meta` 必须直接位于 SD 根目录，不能再套一层文件夹。

安装仍由原包的 MH2P 更新入口发起，不要求绿色菜单或每设备挑战码。**只支持首次安装候选**：已有原安装、备份或试验残留会拒绝继续，不提供覆盖升级。初始兼容门限保守限制为 `M2P-*`／32 位 ARM／版本记录 MU `2678`；这只是输入清单的参考范围，尚未实机确认，更不是所有 MU2678 固件的兼容保证。其他版本先做接口与版本记录格式核验，不能强制绕过门限。

按原厂更新流程保持稳定供电并满足 BEM 更新条件；不能仅因更新界面完成就认定功能成功。安装脚本完成会写 `Done.txt`，其中仍明确标注 `FUNCTIONAL_VALIDATION=PENDING`；还需检查实际文件加载和仪表画面。详见 [安装与恢复](docs/INSTALL_AND_RECOVERY.md)。

## 本轮验证范围

- 原交接 44 项文件、两个原 ZIP 及内部校验通过；原冻结基线 429 项保持不变。
- 新 Java 68 个 class、613 个方法完成离线栈检查；67 个非绑定 class 与无卡片输入逐字节一致。
- 两个 Native 文件只改各自测试版绑定入口及绑定记录，其他字节不变；各完成 4 组真实 Thumb 指令模拟。
- 原签名入口用指令模拟回放三种介质路径，检查其输出与新安装器一致；另记录无介质分支。
- 安装器只在隔离主机文件夹和模拟维护命令下检查。**没有连接、写入或重启车机。**

历史原项目的用户测试反馈不自动转移为这个新通用候选的测试结论。原 `CODE=13` 根因尚未闭合；取消设备绑定容器不等于证明旧故障已解决。详细矩阵见 [验证状态](docs/VALIDATION.md)。

## 资料与语言

| 内容 | 性质 |
| --- | --- |
| `research/01_投屏Java/Source` | 本候选 class 的 Java 反编译结果，不是完整原厂 Java 源码工程 |
| `research/01_投屏Native`、`research/02_导航接口/Native` | ARM32 运行库和原基线反编译 C 伪代码、反汇编、调用资料；伪代码不是可直接重编译的原始 C／C++ 源码 |
| `src/UniversalVariant.java` | 实际可编译的 ASM 适配工具源码 |
| `src/install-universal.sh`、`src/dio_manager.sh` | 本轮可审阅的 ksh／POSIX shell 安装与启动代码 |
| `validation` | 本轮离线检查、修改边界与原更新入口文件的机器可读记录 |

运行链路、设备绑定变更、数据与图形分离见 [架构说明](docs/ARCHITECTURE.md)。二进制、伪代码与 Java 来源的区别见 [源码性质与构建](docs/SOURCE_AND_BUILD.md)。

## 作者与授权

本项目维护与联合开发署名：**[omonob](https://github.com/omonob)**、**[LuKa（@luka-dev）](https://github.com/luka-dev)**。当前项目整理与测试维护由 omonob 负责；LuKa 的协作邀请状态如下。

**联合开发邀请：[LuKa（@luka-dev）](https://github.com/luka-dev)**。已向其发出本仓库写入权限邀请，待本人接受；具体贡献按后续提交与 PR 如实记录。完整署名和角色见 [AUTHORS.md](AUTHORS.md)。

原安装脚本的 SPDX MIT 标注不能自动覆盖其他 ELF、Java、OEM 接口或反编译资料。本仓库没有宣称取得整个包的统一开源许可证；公开前仍需逐模块确认。见 [授权与来源](THIRD_PARTY_NOTICES.md)。

不得上传整个交接总包、内部维护区、设备挑战、身份数据、私有重建输入或许可证密钥。今后公开资料与安装候选仍应分别审核，见 [发布边界](docs/RELEASE_POLICY.md)。
