# 运行方式
## VSCode Tasks
确保.vscode目录中包含tasks.json配置文件。
依次运行：
- Terminal->Run Task->Verilator Template: Generate C/C++ Code
- Terminal->Run Task->Verilator Template: Compile C/C++ Code
- Terminal->Run Task->Verilator Template: Run Simulation
- Terminal->Run Task->Verilator Template: Show Wave
如不成功，尝试手动运行。
## 手动运行
### 生成目标文件夹
```bash
verilator -Wno-fatal Top.v main.cpp --top-module Top --cc --trace --exe
```
### 编译
```bash
make -C obj_dir -f VTop.mk VTop
```
### 运行
```bash
./obj_dir/VTop
```
### 查看波形
```bash
gtkwave wave.vcd
```
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

# 软件包依赖
## nvboard
```bash
sudo apt install libsdl2-dev libsdl2-image-dev
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
- [资料整合](info_collection.md)
- [项目说明](proj_list.md)