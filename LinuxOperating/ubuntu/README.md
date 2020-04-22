sudo apt-cache search  在线搜索软件
    
apt-get update  更新源
    /var/lib/apt/lists
    使用apt-get update命令会从/etc/apt/sources.list中下载软件列表，并保存到该目录
/var/lib/dpkg/available
文件的内容是软件包的描述信息, 该软件包括当前系统所使用的 ubunt 安装源中的所有软件包,其中包括当前系统中已安装的和未安装的软件包.


/var/cache/apt/archives
目录是在用 apt-get install 安装软件时，软件包的临时存放路径

/etc/apt/sources.list
存放的是软件源站点

普通安装：dpkg -i package_name.deb
移除式卸载：dpkg -r pkg1 pkg2 …;

查看已经安装的软件包
dpkg -l | grep gedit

查看软件包的依赖关系
sudo apt-cache depends build-essential

sudo apt-get install --only-upgrade <packagename>



