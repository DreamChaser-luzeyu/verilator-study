# 如何添加/删除源文件
说明：
- 用到nvboard的项目都带有makefile
## 对于带有makefile的项目
可以直接新增/删除源文件

# nvboard的简单介绍
nvboard本身已经给出了较为详细的文档[nvboard官方README](nvboard/README.md)，在此仅对官方文档中未说明的重要特性进行补充。


# nvboard约束文件
约束文件位于`<项目根目录>/constr/<顶层模块名>.nxdc`中。nvboard项目中的[Python脚本](nvboard/scripts/auto_pin_bind.py)会根据这一约束文件生成C++源文件，这个文件将被输出到`<项目根目录>/build/auto_bind.cpp`。这个文件会与项目一同编译。
[nvboard官方README](nvboard/README.md)

脚本解析约束文件的流程如下：
- 解析命令行参数、检查环境变量
  - 由Makefile进行配置，如果使用Makefile，则无需配置
- 解析BoardFile
  - BoardFile路径为`<nvboard源代码根目录>/board/N4`，[点我打开](nvboard/board/N4)
  - BoardFile定义了模拟的FPGA开发板的所有引脚的名称以及类型（`input`、`output`、`rt_input`、`rt_output`）
  - 在成功解析BoardFile之后，脚本将得知FPGA开发板的所有引脚的名称以及类型，并在解析约束文件时检查引脚名称是否合法
- 解析约束文件
  - 约束文件路径为`<项目根目录>/constr/<顶层模块名>.nxdc`，[点我打开示例](nvboard_demo_full_proj/constr/top.nxdc)
  - 约束文件定义了Verilog的顶层模块与FPGA开发板的引脚的对应关系


## 约束文件语法
### 语句
#### “单线”信号约束
“单线”信号约束由被空白字符分开的两部分组成，分别对应“信号”和“端子”。
- “信号”对应Verilog源代码中的模块声明部分声明的1bit信号
- “端子”对应BoardFile中定义的开发板引脚
示例如下：
```
#  信号          端子
VGA_VSYNC     VGA_VSYNC
VGA_HSYNC     VGA_HSYNC
VGA_BLANK_N   VGA_BLANK_N
```
#### “向量”（总线）信号约束
“向量”（总线）信号约束
“总线”信号约束由“总线信号”和“端子集合”两部分组成，由空白字符分开。
- “总线信号”对应Verilog源代码中的模块声明部分声明的总线信号
- “端子集合”由被括号包围、逗号分隔的一组“端子”组成，注意左括号左侧要有至少一个空格
示例如下：
```
# 总线信号        端子集合
sw         (SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0) 
```

#### 注释
可以使用`#`作为单行注释
```
# comment here
```
