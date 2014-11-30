#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <sstream>
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
  char color_vals[7][10]={"white", "red", "green", "blue", "black", "tan", "gray"};

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

//  cout << "x: " << x << " y: " << y << " width: " << width << " height: " << height << " colour: " << colour << "locked: " << locked << " type: " << type << endl;

  XSetForeground(d, gc, colours[colour]);
  XFillRectangle(d, w, gc, x, y, width, height);
  XSetForeground(d, gc, colours[Tan]);

  int copyWidth = width;
  int copyHeight = height;

  if (type == 1) {

//	cout << "Drawing Lateral" << endl;

	XFillRectangle(d, w, gc, x, y + height / 3 - 2, width, 5);

	XFillRectangle(d, w, gc, x, y + (height * 2) / 3 - 2, width, 5);

  }
  else if (type == 2) {

//	cout << "Drawing Upright" << endl;

	XFillRectangle(d, w, gc, x + width / 3 - 2, y, 5, height);
	
	XFillRectangle(d, w, gc, x + (width * 2) / 3 - 2, y, 5, height);

  }
  else if (type == 3) {

//	cout << "Drawing Unstable" << endl;

	copyHeight /= 2;
	copyWidth /= 2;

	XFillRectangle(d, w, gc, x + (copyWidth / 2) + 1, y + (copyHeight / 2) + 1, copyWidth, copyHeight);

  }
  else if (type == 4) {

//	cout << "Drawing Psychedelic" << endl;

	int len = 6;

	copyHeight /= 4;
	copyWidth /= 4;
	
	XFillRectangle(d, w, gc, x + copyWidth - 3, y + copyHeight - 3, len, len);
	XFillRectangle(d, w, gc, x + copyWidth * 2 - 3, y + copyHeight - 3, len, len);
	XFillRectangle(d, w, gc, x + copyWidth * 3 - 3, y + copyHeight - 3, len, len);

	copyHeight *= 2;

	XFillRectangle(d, w, gc, x + copyWidth - 3, y + copyHeight - 3, len, len);
	XFillRectangle(d, w, gc, x + copyWidth * 2 - 3, y + copyHeight - 3, len, len);
	XFillRectangle(d, w, gc, x + copyWidth * 3 - 3, y + copyHeight - 3, len ,len);

	copyHeight += copyHeight / 2;

	XFillRectangle(d, w, gc, x + copyWidth - 3, y + copyHeight - 3, len, len);
	XFillRectangle(d, w, gc, x + copyWidth * 2 - 3, y + copyHeight - 3, len, len);
	XFillRectangle(d, w, gc, x + copyWidth * 3 - 3, y + copyHeight - 3, len, len);

//	height += height / 3;
	
//	XFillRectangle(d, w, gc, x + width - 3, y + height - 3, len, len);

  }

  // Border

  
  XSetForeground(d, gc, colours[Black]);


		XFillRectangle(d, w, gc, x, y, width, 4);
	XFillRectangle(d, w, gc, x, y + height - 2, width, 4);

		XFillRectangle(d, w, gc, x, y, 4, height);
	XFillRectangle(d, w, gc, x + width - 2, y, 4, height);

  if (locked) {

	XDrawLine(d, w, gc, x, y, x + width, y + height);
	XDrawLine(d, w, gc, x, y + height, x + width, y);

 }


}

void Xwindow::drawString(int x, int y, int level, int score, int highscore, int movesLeft) {

  stringstream ss1;
  stringstream ss2;
  stringstream ss3;
  stringstream ss4;

  string str;
  string str1 = "SQUARESWAPPER 5000";
  string str2 = "BY FRED CAO AND KEVIN XUE";
  ss1 << level;
  ss1 >> str;
  string str3 = "LEVEL: " + str;
  ss2 << score;
  ss2 >> str;
  string str4 = "SCORE: " + str;
  ss3 << movesLeft;
  ss3 >> str;
  string str5 = "MOVESLEFT: " + str;
  ss4 << highscore;
  ss4 >> str;
  string str6 = "HIGHSCORE: " + str;

  XSetForeground(d, gc, colours[White]);  
  XDrawString(d, w, DefaultGC(d, s), x, 100, str1.c_str(), str1.length()); 
  XDrawString(d, w, DefaultGC(d, s), x, 150, str2.c_str(), str2.length());
  XDrawString(d, w, DefaultGC(d, s), x, 250, str3.c_str(), str3.length());
  XDrawString(d, w, DefaultGC(d, s), x, 300, str4.c_str(), str4.length());
  XDrawString(d, w, DefaultGC(d, s), x, 350, str5.c_str(), str5.length());
  XDrawString(d, w, DefaultGC(d, s), x, 400, str6.c_str(), str6.length());
  XDrawString(d, w, DefaultGC(d, s), x, 100, str1.c_str(), str1.length()); 
  XDrawString(d, w, DefaultGC(d, s), x, 150, str2.c_str(), str2.length());
  XDrawString(d, w, DefaultGC(d, s), x, 250, str3.c_str(), str3.length());
  XDrawString(d, w, DefaultGC(d, s), x, 300, str4.c_str(), str4.length());
  XDrawString(d, w, DefaultGC(d, s), x, 350, str5.c_str(), str5.length());
  XDrawString(d, w, DefaultGC(d, s), x, 400, str6.c_str(), str6.length());
}

