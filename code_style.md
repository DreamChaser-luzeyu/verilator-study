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