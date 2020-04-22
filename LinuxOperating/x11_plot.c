#include <X11/Xlib.h>
// gcc -o main x11_plot.c -lX11
int main()
{
    Display * dsp = XOpenDisplay(NULL);
    int screenNum = DefaultScreen(dsp);
    unsigned long white = WhitePixel(dsp, screenNum);
    unsigned long black = BlackPixel(dsp, screenNum);
    Window win = XCreateSimpleWindow(dsp, DefaultRootWindow(dsp), 0, 0, 1024, 800, 0, black, white);
    XSelectInput(dsp, win, ExposureMask | KeyPressMask);
    GC gc = XCreateGC(dsp, win, 0, NULL);
    XMapWindow(dsp, win);
    XFlush(dsp);
 
    XEvent event;
    do
    {
        XNextEvent(dsp, &event);
        switch (event.type)
        {
            case Expose:
            for (int i = 0; i < 300; ++i)
            {
                XDrawPoint(dsp, win, gc, 400+i, 400);
            }
            break;
        default:
            break;
        }
    } while (event.type != MapNotify);
 
    return 0;
}