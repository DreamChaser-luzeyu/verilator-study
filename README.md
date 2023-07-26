# 关于
待补充
# Git命令提示
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
  #or
  git submodule update --recursive --remote
  ```  



# 代码规范
## Verilog
- 模块名称遵守大驼峰命名规范
- 模块输入输出应写明`input/output`，`reg/wire`，以及总线宽度
- 输入输出信号命名应以`IO`开头
- 中间结果以小驼峰与下划线相结合命名
示例如下：
```Verilog
module Accumulator(
    input  wire[7:0] IO_Addend_0,
    input  wire[7:0] IO_Addend_1,
    input  wire[7:0] IO_Addend_2,
    input  wire[7:0] IO_Addend_3,
    output wire[9:0] IO_Result
);

wire [8:0] sumAddend_0_1 = IO_Addend_0 + IO_Addend_1; 
wire [8:0] sumAddend_2_3 = IO_Addend_2 + IO_Addend_3;
assign IO_Result = sumAddend_0_1 + sumAddend_2_3; 

endmodule
```
# 杂项
- 为什么仓库名叫ysys而不是ysyx？
  - 因为不小心打错了，不好改
- VS Code开始报奇怪的头文件相关错误？
  - 检查包含路径配置，如果配置正确，尝试重启VS Code，似乎是bug
# 其他README
- [仓库说明](repo_README.md)
  - 说明当前仓库中的子模块
- [资料整合](info_collection.md)
  - 学习可能所需的各种资料
- [项目说明](proj_list.md)
  - 仓库中的各个项目功能或目的说明
- [配置文档](config_doc.md)
  - 包含项目运行相关指导
- [开发文档](dev_doc.md)