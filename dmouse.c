#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

static Display *disp;
static Window root;

int main(void)
{
	struct timespec delay;
	disp = XOpenDisplay(0);
	root = XRootWindow(disp, 0);

	delay.tv_sec = 0;
	delay.tv_nsec = 500000000L;  /* Half a second in nano's */

	XSelectInput(disp, root, KeyReleaseMask);

	for(;;nanosleep(&delay, NULL))
	{
		printf("z\n");
		XWarpPointer(disp, None, RootWindow(disp, DefaultScreen(disp)), 0, 0, 0, 0, 10, 10);
		XFlush(disp);
	}
}
