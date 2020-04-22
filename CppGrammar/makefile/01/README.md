target:建构条件（prerequisites）
    建构命令

未指定目标，缺省执行第一个目标
.ONESHELL (\折行)

clean：
    rm -f *.o
make clean

.PHONY:clean(明确指定ckean是伪目标)

伪目标：
    all
    clean
    install
    print
    tar
    dist
    TAGS
    check test
    
*.c
?.c 任意一个字符
lib[abc].c 第四个字符为a、b、c
lib[0-9].c 第四个字符为0-9
lib[^abc].c 第四个字符不是a、b、c

var name = value;
var name := value;
var name ?= value;
var name += value;
${name}
$$HOME shell的变量

内置变量
    ${cc}当前使用的编译器
    ${make}当前使用的make
自动变量
    $@ 当前目标
    $< 当前目标的首个先决条件
    $? 比目标更新的所有先决条件
    $^ 所有先决条件
    $(@D)和$(@F):$@  $@的目录名和文件名
    $(<D)和$(<F):$<>  $<的目录名和文件名
