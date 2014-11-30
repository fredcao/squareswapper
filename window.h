#ifndef __WINDOW_H__
#define __WINDOW_H__
#include <X11/Xlib.h>
#include <iostream>
#include <string>

class Xwindow {

	Display *d;
	Window w;
	int s;
	GC gc;
	unsigned long colours[10];

	public:

	Xwindow(int width = 800, int height = 800);	// Constructor; displays the window
	~Xwindow();					// Destructor: destroys the window

	enum { White = 0, Red, Green, Blue, Black, Tan };

	// Draws a rectangle
	void drawRectangle(int x, int y, int width, int height, int colour, bool locked, int type);

	// Draws a string
	void drawString(int x, int y, std::string msg);

};

#endif
