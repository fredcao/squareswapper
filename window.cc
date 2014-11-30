#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include "window.h"

using namespace std;

Xwindow::Xwindow(int width, int height) {

  d = XOpenDisplay(NULL);
  if (d == NULL) {
    cerr << "Cannot open display" << endl;
    exit(1);
  }
  s = DefaultScreen(d);
  w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, width, height, 1,
                          BlackPixel(d, s), WhitePixel(d, s));
  XSelectInput(d, w, ExposureMask | KeyPressMask);
  XMapRaised(d, w);

  Pixmap pix = XCreatePixmap(d,w,width,
        height,DefaultDepth(d,DefaultScreen(d)));
  gc = XCreateGC(d, pix, 0,(XGCValues *)0);

  XFlush(d);
  XFlush(d);

  // Set up colours.
  XColor xcolour;
  Colormap cmap;
  char color_vals[7][10]={"white", "red", "green", "blue", "black", "tan"};

  cmap=DefaultColormap(d,DefaultScreen(d));
  for(int i=0; i < 6; ++i) {
      XParseColor(d,cmap,color_vals[i],&xcolour);
      XAllocColor(d,cmap,&xcolour);
      colours[i]=xcolour.pixel;
  }

  XSetForeground(d,gc,colours[Black]);

  // Make window non-resizeable.
  XSizeHints hints;
  hints.flags = (USPosition | PSize | PMinSize | PMaxSize );
  hints.height = hints.base_height = hints.min_height = hints.max_height = height;
  hints.width = hints.base_width = hints.min_width = hints.max_width = width;
  XSetNormalHints(d, w, &hints);

  XSynchronize(d,True);

  usleep(1000);
}

Xwindow::~Xwindow() {
  XFreeGC(d, gc);
  XCloseDisplay(d);
}

void Xwindow::drawRectangle(int x, int y, int width, int height, int colour, bool locked, int type) {

  cout << "x: " << x << " y: " << y << " width: " << width << " height: " << height << " colour: " << colour << "locked: " << locked << " type: " << type << endl;

  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Black]);

	return;

  if (type == 1) {

	height /= 3;

	XDrawLine(d, w, gc, x, y + height - 10, x + width, y + height + 10);

	height *= 2;

	XDrawLine(d, w, gc, x, y + height - 10, x + width, y + height + 10);

  }
  else if (type == 2) {

	width /= 3;

	XDrawLine(d, w, gc, x + width - 10, y, x + width + 10, y + height);
	
	width *= 2;

	XDrawLine(d, w, gc, x + width - 10, y, x + width + 10, y + height);

  }
  else if (type == 3) {

	height /= 2;
	width /= 2;

	XFillRectangle(d, w, gc, x + (width / 2), y + (height / 2), width, height);

  }
  else if (type == 4) {

	int len = 6;

	height /= 4;
	width /= 4;
	
	XFillRectangle(d, w, gc, x + width - 3, y + height - 3, len, len);

	height *= 2;

	XFillRectangle(d, w, gc, x + width - 3, y + height - 3, len, len);

	height += height / 2;

	XFillRectangle(d, w, gc, x + width - 3, y + height - 3, len, len);

	height += height / 3;
	
	XFillRectangle(d, w, gc, x + width - 3, y + height - 3, len, len);

  }


  if (locked) {

	XDrawLine(d, w, gc, x, y, x + width, y + 5);
	XDrawLine(d, w, gc, x, y + height - 5, x + width, y + height);
	XDrawLine(d, w, gc, x, y, x + 5, y + height);
	XDrawLine(d, w, gc, x + width - 5, y, x + width, y + height);

	XDrawLine(d, w, gc, x, y, x + width, y + height);
	XDrawLine(d, w, gc, x, y + height, x + width, y);

 }

}

void Xwindow::drawString(int x, int y, string msg) {
  XDrawString(d, w, DefaultGC(d, s), x, y, msg.c_str(), msg.length());
}

