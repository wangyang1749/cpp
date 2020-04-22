# c++（opencv|opengl）/java/perl/python的vscode配置
## c++的vscode配置
### 基本代码的运行
* 添加Code Runner
```
"code-runner.executorMap": {
        "cpp": "cd $dir && g++  $fileName  -o  $workspaceRoot/build/$fileNameWithoutExt.exe && $workspaceRoot/build/$fileNameWithoutExt.exe",
        "c": "cd $dir && gcc  $fileName  -o $fileNameWithoutExt.exe && $fileNameWithoutExt.exe",
        "java": "cd $dir ; D:/'Program File'/jdk10/jdk-11.0.2/bin/java $fileName"
    },
```

* 快捷键搜索run code可以修改快捷键
* Supported customized parameters

```
$workspaceRoot: The path of the folder opened in VS Code
$dir: The directory of the code file being run
$dirWithoutTrailingSlash: The directory of the code file being run without a trailing slash
$fullFileName: The full name of the code file being run
$fileName: The base name of the code file being run, that is the file without the directory
$fileNameWithoutExt: The base name of the code file being run without its extension
$driveLetter: The drive letter of the code file being run (Windows only)
$pythonPath: The path of Python interpreter (set by Python: Select Interpreter command)
```

# Cmake
+ 基本操作
```
set(var hello) # 声明变量 hello
message(${var}) # 打印变量
message(${CMAKE_CURRENT_LIST_FILE}) # 打印当前文件夹

IF(TRUE)
    message("this is true")
ENDIF()

```
+ 多个文件
```
add_executable(main src/main.cpp src/loop.cpp)
```
