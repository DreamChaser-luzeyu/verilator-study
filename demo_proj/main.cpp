#include <stdio.h>
#include <stddef.h>

#include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
#include "VTop.h"

vluint64_t Sim_Time_GV = 0;
/**
 * Must implement, used by verilator 
 * Return current simulation time
 */
double sc_time_stamp() {
    return Sim_Time_GV;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    // --- 用于导出vcd波形
    Verilated::traceEverOn(true);
    VerilatedVcdC *tfp = new VerilatedVcdC;
    // ---
    // 构造顶模块，此处的“top”将作为更上一层的模块的名称
    VTop *top = new VTop("top"); // 调用VTop.h里面的IO struct
    // --- 开始跟踪波形
    top->trace(tfp, 0);
    tfp->open("wave.vcd"); // 打开vcd
    // ---
    // 设置仿真时间段
    while (Sim_Time_GV < 20 && !Verilated::gotFinish()) {
        // --- Write testbench here
        top->IO_Addend_0 = Sim_Time_GV + 0; // 激励控制
        top->IO_Addend_1 = Sim_Time_GV + 1;
        top->IO_Addend_2 = Sim_Time_GV + 2;
        top->IO_Addend_3 = Sim_Time_GV + 3;
        
        
        
        // ---
        // 计算模型，当输入改变时应调用
        top->eval(); 
        // --- Post-eval operations
        // 输出仿真结果
        printf("[CURR SIM TIME] %llu\n", Sim_Time_GV);
        printf("[TB SIM RESULT] %d + %d + %d + %d = %d\n", 
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