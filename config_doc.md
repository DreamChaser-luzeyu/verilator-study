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

# 软件包依赖
## nvboard
```bash
sudo apt install libsdl2-dev libsdl2-image-dev
```