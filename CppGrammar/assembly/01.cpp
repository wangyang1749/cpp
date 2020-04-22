#include <windows.h>
#include <mmsystem.h>

//TODO需要拷贝这个库
#pragma comment(lib,"winmm.lib") // 告诉连接器与这个库连接，因为我们要播放多媒体声音
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup") // 设置连接器选项

int main(void)
{
	PlaySound("SystemStart", NULL, SND_ALIAS | SND_SYNC);
	Sleep(50);
	PlaySound("SystemStart", NULL, SND_ALIAS | SND_SYNC);
	Sleep(50);
	PlaySound("SystemStart", NULL, SND_ALIAS | SND_SYNC);
	Sleep(50);

	return 0;
}