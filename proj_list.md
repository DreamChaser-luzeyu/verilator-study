# 项目列表
- [“一生一芯”课程项目列表](ysyx/proj_list.md)
- `demo_proj` 
  - Verilator示例项目，无其他依赖，无Makefile，由VSCode Task管理
  - 目的在于熟悉Verilator的基本命令以及Verilator仿真的工作流
- `nvboard_demo_full_proj` 
  - Verilator+nvboard示例项目，未对nvboard官方example做任何修改，包含VGA、PS/2、流水灯
- `nvboard_demo_minimal_proj` [项目说明](nvboard_demo_minimal_proj/README.md)
  - Verilator+nvboard示例项目，仅包含流水灯以及七段数码管
  - 将nvboard上的RST按钮与Verilog模块中的rst信号绑定
  - 改进了Makefile，无需配置`NVBOARD_HOME`环境变量即可正常make
  - 编写了CMakeList.txt，支持直接使用CLion打开项目
- `qemu` [项目说明](qemu/README.md)
  - 个人fork的QEMU官方源码
  