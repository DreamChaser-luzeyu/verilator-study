# 带有Makefile和CMakeLists.txt的项目
可以直接使用CLion打开，为了能够正常使用代码跳转及补全，要以CMake项目的方式打开。打开项目后可以手动增加Makefile Target。

如果使用CLion开发，可以配合Verilog插件使用。

也可以使用VS Code打开，使用Terminal->Run Task来执行make。

# 无Makefile的项目
## VSCode Tasks
确保.vscode目录中包含tasks.json配置文件。
依次运行：
- Terminal->Run Task->Verilator Template: Generate C/C++ Code
- Terminal->Run Task->Verilator Template: Compile C/C++ Code
- Terminal->Run Task->Verilator Template: Run Simulation
- Terminal->Run Task->Verilator Template: Show Wave

如不成功，尝试手动运行。
此部分可能更新不及时。
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