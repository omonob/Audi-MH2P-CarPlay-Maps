# 完整版来源、下载与致谢 / Upstream full edition

核对日期 / Checked: **2026-11-07, Asia/Shanghai**。本页是来源记录与独立说明，不是新安装版本。

## 1. 原作者与下载入口

本项目的实现基础及大量研究资料来自 **audijiJQ / AUDIJI** 的 MH2P 程序，包括 Type111 副屏、导航消息处理，以及历史完整样本中的箭头映射、导航卡片和相关显示配合。原作者及各模块适用的版权、许可应保留，不能把这些实现写成我们从零原创。Java 阅读材料为反编译结果，Native C-like 材料为反编译伪代码，不是原作者完整原始工程。

- [原作者主页 / Author](https://github.com/audijiJQ)
- [原作者公开仓库 / Public upstream repository](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps)
- [核对的固定提交 / Reviewed commit](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps/tree/117ae13c1197099d20c3d40b80a2af9aaab99e97)
- [完整安装 ZIP 官方下载 / Official full installation ZIP](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps/raw/117ae13c1197099d20c3d40b80a2af9aaab99e97/AUDI_Altscreen_Sport_Public.zip)
- [原作者说明 / Author's instructions](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps/blob/117ae13c1197099d20c3d40b80a2af9aaab99e97/README.md)

完整 ZIP：`AUDI_Altscreen_Sport_Public.zip`

```text
Bytes: 1249288
SHA256: a62292f82fab79780c775f55127dbe3402bdb0eb752a8ef62027b8a1294074f4
```

本轮只克隆公开仓库、计算哈希并检查 ZIP 的 51 个条目与 CRC。没有执行 ZIP 内程序、自动升级脚本或卸载工具，没有新解密、重编译或连接车机。因此不能凭本页认定其已通过我们对某台车的安装、画面、冷启动或兼容性验收。

## 2. 三份材料不是同一个版本

| 内容 | 卡片／箭头范围 | 证据和发布状态 |
| --- | --- | --- |
| 本仓库 `v1.0.0-test.1` | 保留导航数据和 maneuver 接口；不带卡片绘制链 | 已有无卡片测试附件；本次不修改、不替换 |
| 2026-11-01 历史完整研究样本 | 有导航数据、maneuver 映射、BAP／Komo、navigation 卡片渲染和布局控制 | 已有本地反编译研究；不等于新上游 ZIP 的源码或当前完整测试版 |
| 原作者本次公开的完整 ZIP | 作者说明为带 RGI 卡片的完整通用安装版本，并提供迁移／修复工具 | 以原作者说明为准；本轮只验证 ZIP 结构、CRC、SHA256，不代表独立实车验证 |

上游称新包解决了冷启动超时／卡滞并取消单设备绑定；这些是作者对其新包的说明，**不能反向写成本仓库旧 V1 已修复**。本页未从加密／压缩载荷中恢复新运行库，因此也不宣称本地历史样本与新包逐文件一致。

用户所说的“箭头都要有”，技术上需要保留消息解析、机动类型与方向映射、距离单位、道路文字、车道／环岛信息、BAP／Komo、平台呈现和布局等整条依赖，不是加一张箭头图片。详细链路见[中文](RUNTIME_INTERNALS.zh-CN.md)／[English](RUNTIME_INTERNALS.en.md)。

## 3. 本轮发布边界

本次上传的是我们独立撰写的中英文项目说明、架构解释、来源索引和计划说明，以及这些仓库文件的哈希更新。没有新上传上游 ZIP、完整 Java 反编译、Native 伪代码或卡片运行库，没有修改旧 Release、tag、附件、源码／安装载荷、仓库可见性或协作者权限。

核对时上游根目录只有安装 ZIP、README 和公开说明，ZIP 中也未发现以 LICENSE／COPYING／NOTICE 命名的许可文件。免费公开使用声明不能直接当作整包源码修改和再分发许可；发布时间先后也不改变这个边界。原安装脚本 MIT 声明的适用范围仍限于有依据的文件。获得明确许可后，应按许可范围单独准备完整候选、隐私检查和验证记录，不能覆盖旧 V1 或声称已获得整包原始源码。

参考：[GitHub 仓库许可说明](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/customizing-your-repository/licensing-a-repository)。来源致谢不表示原作者联合维护、审核、背书或已许可本仓库所有内容。

## 4. English summary

Much of this project's implementation basis and research material originates from **audijiJQ / AUDIJI's MH2P program**. The original author's official full package is linked above at a fixed commit, with the locally verified size and SHA256. Copyright and applicable notices must be retained.

The existing V1 assets in this repository are still the **no-card TEST candidate**. The historical full research sample is not the source of the new upstream ZIP. The upstream author describes the new ZIP as a universal, card-capable package with cold-start fixes; these claims have not been independently vehicle-validated in this update.

This documentation update adds explanations and source links only. It does **not** mirror the new ZIP or add the unreleased full decompilation. No repository-wide source license was found in the reviewed upstream tree or named license entries in the ZIP. Public availability and publication order are not a substitute for applicable redistribution permission. A script-specific MIT notice must not be expanded to all components.

Native analysis is decompiled pseudocode, not original compilable C/C++; Java material is decompiled class output, not a complete original source project. Planned center-screen mirroring, settings menus and Apple-ecosystem surround/audio research are not shipped or certified features.
