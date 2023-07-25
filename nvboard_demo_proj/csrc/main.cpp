#include <nvboard.h>
#include <Vtop.h>

// define this macro to stop editor warning
// Remove this after modifying top module name
// Or replace with the new module name
#define TOP_NAME Vtop

// TOP_NAME宏通过gcc的-D参数设置为Vtop(详见Makefile)
// 对于本项目，TOP_NAME可被替换为Vtop
static TOP_NAME dut;

void nvboard_bind_all_pins(Vtop* top);

static void single_cycle() {
  dut.clk = 0; dut.eval();
  dut.clk = 1; dut.eval();
}

static void reset(int n) {
  dut.rst = 1;
  while (n -- > 0) single_cycle();
  dut.rst = 0;
}

int main() {
  nvboard_bind_all_pins(&dut);
  nvboard_init();

  reset(10);

  while(1) {
    nvboard_update();
    single_cycle();
  }
}
