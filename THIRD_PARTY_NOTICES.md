# 第三方来源、版权与反编译声明

## MH2P 实现来源致谢（2026-11-07 补充）

本项目的实现基础和大量研究资料源自 audijiJQ / AUDIJI 的 MH2P 程序。Type111 副屏接入、导航消息处理以及原完整样本的箭头／导航卡片等实现不能归为本项目从零原创。Java 阅读材料为反编译结果，Native 材料为反编译伪代码／反汇编，不冒充原作者交付的完整原始工程。

- 原作者：[audijiJQ](https://github.com/audijiJQ)。
- 原作者公开项目：[AUDI_MH2P_Altscreen_Carplay-maps](https://github.com/audijiJQ/AUDI_MH2P_Altscreen_Carplay-maps)。
- 本轮核对的上游提交：`117ae13c1197099d20c3d40b80a2af9aaab99e97`。
- 完整包下载、SHA256、功能范围和授权状态见 [UPSTREAM_AND_FULL_EDITION.md](docs/UPSTREAM_AND_FULL_EDITION.md)。本次只增加独立撰写的说明和来源链接，不镜像该 ZIP，不追加完整反编译源码。

本仓库与上游的发布时间先后只说明各自发布记录，不能据此给第三方内容增加复制、修改或再分发许可。没有用时间顺序推定统一许可，也没有把安装脚本的 MIT 标注扩展到全部模块。参见 [GitHub 关于仓库许可的说明](https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/customizing-your-repository/licensing-a-repository)。

## 既有版权与角色边界

原包安装源码标注 `Copyright (c) 2026 audijiJQ` 和 `SPDX-License-Identifier: MIT`。原安装脚本的第三方版权及适用许可声明保留在此，不列入本项目联合署名表；保留这些声明不表示原包作者参与、支持或认可本项目。

本轮独立适配／测试与资料整理由 omonob 维护。本轮源码材料并不自动表示全部模块已获得相同的再分发或开源授权；没有把安装脚本的 MIT 标注扩展到其他 ELF、Java、原厂框架和反编译结果。

LuKa（[@luka-dev](https://github.com/luka-dev)）列为**受邀联合开发者**：当前仓库写入邀请待本人接受。该联合署名记录协作邀请，不表示其已经完成本仓库的开发、审查或实车验证，也不改变原作者和第三方权利。后续实际贡献按提交与 PR 更新，详见 [AUTHORS.md](AUTHORS.md)。

Native C 是从已有二进制恢复的研究伪代码，不是原作者可直接重编译的源码；Java 是修改后 class 的反编译结果。真实 ASM 工具源码与 shell 安装源码分别说明。原厂实现及其权利归原权利人，本项目不代表 Audi、Apple、QNX 或其认证／授权。

维护者已明确决定将仓库及 V1 测试包公开；该可见性决定不改变各模块原有权利边界，也不构成额外授权证据。仍须逐模块核对原作者授权、OEM 部分及第三方工具许可；没有明确依据的模块不能标成自主原创或统一 MIT 开源。ASM、Vineflower、Unicorn 等工具本体不作为本候选运行安装载荷分发。

本候选不分发原设备挑战、身份数据、配对秘密、私钥或原厂 CarPlay 授权凭据，不代替目标车辆原有合法授权。
