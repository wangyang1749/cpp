编译动态链接库
    主要是 -shared
    要想生成def以及使用动态库的lib文件
    -Wl,--output-def,libadd.def,--out-implib,libadd.a
    g++ -shared .\DllAdd.cpp -o DllAdd.dll -Wl,--output-def,DllAdd.def,--out-implib,DllAdd.lib
    （注意以上命令在cmd可以使用）
使用动态链接库
    g++ .\DllMain.cpp -static-libgcc .\DllAdd.lib
编译静态链接库
    g++ -c .\LibAdd.cpp
    ar cr LibAdd.lib .\LibAdd.o
使用静态链接库
    g++ .\LibMain.cpp  -static-libgcc .\LibAdd.lib


根据dll生成lib
    dumpbin /exports "D:\Program Files\VideoLAN\VLC\libvlc.dll" > "D:\Program Files\VideoLAN\VLC\libvlc.def"
    lib /def:"D:\Program Files\VideoLAN\VLC\libvlc.def" /out:"D:\Program Files\VideoLAN\VLC\libvlc.lib" /machine:x86
