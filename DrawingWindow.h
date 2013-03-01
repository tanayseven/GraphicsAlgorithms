/*
 * 
 * Copyright (C) 2013 Tanay PrabhuDesai <tanayseven@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

//this file is an abstraction layer for drawing canvas in a window
#ifndef DRAWING_WINDOW
#define DRAWING_WINDOW

#include <cairo.h>
#include <gtk/gtk.h>

//declare height and width
int width;
int height;

//declare the surface and context
cairo_surface_t *surface;
cairo_t *cr_main;

//declare the window and drawing area
GtkWidget *window;
GtkWidget *drawing_area;

//declaration of function pointer
//this function will be defined by the user in his code
void (*draw)(cairo_t*);

//assigns a defined function to above draw function pointer
void setDraw(void *(_draw));

//sets the main gtk window's width and height
void window_set_width_height(int _width, int _height);

//cairo does not have set_pixel function
//hence defination of set_pixel using rectangle function
void cairo_set_pixel(cairo_t *cr, int x, int y);

//draw event to draw onto the graphics buffer, automatically called
static gboolean draw_cb (GtkWidget *widget, cairo_t   *cr, gpointer   data);

void initWindow(int argc, char **argv);

#endif
