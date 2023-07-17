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