# 代码规范
## Verilog
- 模块名称遵守大驼峰命名规范
- 模块输入输出应写明`input/output`，`reg/wire`，以及总线宽度
- 输入输出信号命名应以`IO`开头
- 中间结果以小驼峰与下划线相结合命名
- 同一文档包含多个模块定义时，各个模块定义应缩进（我还是更喜欢带缩进）
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

## C/C++
- 数量的命名以`nr_`开头（惯例操作，number的缩写）
- 类型的命名（使用`typedef`定义的）以`_t`结尾
- 对于其他项目中不符合规范的命名，应使用`typedef`进行修正
- 面向对象部分使用驼峰命名，类使用大驼峰，对象使用小驼峰
- 函数实现间应有空格
- 局部变量使用下划线命名，局部对象使用小驼峰命名
- 全局变量/对象使用大驼峰命名，结尾带有`_GV`
- 回调函数应以`_on`开头
