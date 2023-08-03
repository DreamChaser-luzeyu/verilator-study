# 关于
此仓库中的内容为学习Verilator的资料合集与项目模板。仓库中将包含各种学习资料、项目模板、配置指南以及学习心得。

根据“一生一芯”的项目要求，在学习期间，“一生一芯”项目相关的代码会作为子模块存储在私有仓库中，待本期“一生一芯”项目结束后公开。

# 快速入门
- 如果你希望快速得到一个Verilator项目模板，请参考[项目说明](proj_list.md)

# Git命令提示
- 新增子模块
  ```bash
  git submodule add <仓库Git地址> <本地子模块路径>
  ```
- 克隆含有子模块的仓库
  ```bash
  git clone --recursive <仓库地址>
  ```
- 首次拉取子模块
  ```bash
  git submodule update --init --recursive
  ```
- 更新子模块
  ```bash
  git pull --recurse-submodules
  # or
  git submodule update --recursive --remote
  ```  
- 修改nvboard远程仓库origin为fork出的仓库
  ```bash
  git remote set-url origin https://github.com/DreamChaser-luzeyu/nvboard.git
  ```
- 新增nvboard远程仓库upstream为官方的仓库
  ```bash
  git remote add upstream https://github.com/NJU-ProjectN/nvboard.git
  ```
# 杂项
- 为什么仓库名叫ysys而不是ysyx？
  - ~~因为不小心打错了，不好改~~
  - 可以理解为“一生一世”的拼音首字母，鞭策自己要终身学习
- VS Code开始报奇怪的头文件相关错误？
  - 检查包含路径配置，如果配置正确，尝试重启VS Code，似乎是bug
# 其他README
- [仓库说明](repo_README.md)
  - 说明当前仓库中的子模块
- [工具软件](tools.md)
  - 实用的软件
- [资料整合](info_collection.md)
  - 学习可能所需的各种资料
- [重要知识点](study_bookmark.md) 
  - 至关重要的思想、概念
- [项目说明](proj_list.md)
  - 仓库中的各个项目功能或目的说明
- [配置文档](config_doc.md)
  - 包含项目运行相关指导
- [开发文档](dev_doc.md)
  - 包含项目开发中与编码相关的指导
- [代码规范](code_style.md)