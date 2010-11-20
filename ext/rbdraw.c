#include <stdio.h>

#include "rbdraw.h"

void Init_rbdraw() {
  VALUE mDraw = rb_define_module("Draw");
  /* Display */
    cDisplay = rb_define_class_under(mDraw, "Display", rb_cObject);
      rb_define_singleton_method(cDisplay, "new", display_new, -1);
      rb_define_method(cDisplay, "initialize", display_init, 4);
      rb_define_method(cDisplay, "close", display_close, 0);
        rb_define_attr(cDisplay, "name", 1, 0);
	rb_define_attr(cDisplay, "screen_num", 1, 0);
	rb_define_attr(cDisplay, "width", 1, 0);
	rb_define_attr(cDisplay, "height", 1, 0);
  /* Window */
    cWindow = rb_define_class_under(mDraw, "Window", rb_cObject);
      rb_define_singleton_method(cWindow, "new", window_new, -1);
      rb_define_method(cWindow, "initialize", window_init, 2);
      rb_define_method(cWindow, "show", window_show, 0);
      rb_define_method(cWindow, "hide", window_hide, 0);
      rb_define_method(cWindow, "create_graphics", create_graphics, 0);
        rb_define_attr(cWindow, "width", 1, 1);
	rb_define_attr(cWindow, "height", 1, 1);
  /* Graphics */
    cGraphics = rb_define_class_under(mDraw, "Graphics", rb_cObject);
      rb_define_singleton_method(cGraphics, "new", graphics_new, -1);


  XInitThreads();
}

/* Class Heirarchy --
    -- Draw:Module
        -- Display: Class
            -- new(name = 'null') -- XOpenDisplay
            -- close -- XCloseDisplay
            -- int height -- DisplayHeight
            -- int width -- DisplayWidth
        -- Window: Class
            -- new (display = Display.default) -- XCreateSimpleWindow
            -- Graphics create_graphics -- XDefaultGC
            -- close -- XDestroyWindow
        -- Graphics: Class -- GC
            -- new() -- raise error
*/

