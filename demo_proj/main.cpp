#include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
#include "VAccumulator.h"

vluint64_t Sim_Time_GV = 0; // initial 仿真时间

double sc_time_stamp() {
    return Sim_Time_GV;
}

int main(int argc, char **argv) {

    Verilated::commandArgs(argc, argv);
    // 用于导出vcd波形
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    VAccumulator *top = new VAccumulator("top"); // 调用VAccumulator.h里面的IO struct

    top->trace(tfp, 0);
    tfp->open("wave.vcd"); // 打开vcd

    // 设置仿真时间段
    while (sc_time_stamp() < 20 && !Verilated::gotFinish()) {
        top->IO_Addend_0 = Sim_Time_GV + 0; // 激励控制
        top->IO_Addend_1 = Sim_Time_GV + 1;
        top->IO_Addend_2 = Sim_Time_GV + 2;
        top->IO_Addend_3 = Sim_Time_GV + 3;
        // 进行一个时钟周期的模拟
        top->eval(); 
        // 输出仿真结果
        printf("%d + %d + %d + %d = %d\n", 
               top->IO_Addend_0, 
               top->IO_Addend_1, 
               top->IO_Addend_2, 
               top->IO_Addend_3, 
               top->IO_Result); 
        // 存储波形文件
        tfp->dump(Sim_Time_GV);
        Sim_Time_GV++;                                                                                                                // 推动仿真时间
    }

    top->final();
    tfp->close();
    
    delete top;

    return 0;
}