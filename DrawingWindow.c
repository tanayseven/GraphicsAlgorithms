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
 
#include "DrawingWindow.h"
  
//assigns a defined function to above draw function pointer
void setDraw(void *(_draw))
{
	draw = _draw;
}

//sets the main gtk window's width and height
void window_set_width_height(int _width, int _height)
{
	width = _width;
	height = _height;
}

//cairo does not have set_pixel function
//hence defination of set_pixel using rectangle function
void cairo_set_pixel(cairo_t *cr, int x, int y)
{
	cairo_rectangle (cr, x, y, 1, 1);
	cairo_fill (cr);
}

//draw event to draw onto the graphics buffer, automatically called
static gboolean draw_cb (GtkWidget *widget, cairo_t   *cr, gpointer   data)
{
  cairo_set_source_rgb(cr, 255, 0, 0);
  (*draw)(cr);  //the on draw which is defined by the user is defined here
  return FALSE;
}

//call exit the program once this window is closed
void destroy(GtkWidget *widget, gpointer data)
{
	//exit the gtk main loop
    gtk_main_quit();
}

void initWindow(int argc, char **argv)
{
	//set default width and height
	//if width and height not defined
	if(width != -1 && height != -1)
	{
		width = 500;
		height = 500;
	}
	
	//initialize GTK+
	gtk_init (&argc, &argv);
	
	//allocate a new window to the GtkWidget window
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    
    //set default window size
    gtk_window_set_default_size(GTK_WINDOW(window), width, height);
    
    //set default window title text
    gtk_window_set_title(GTK_WINDOW(window),"Hello World");
    
    //create a surface of format ARGB32 and height and width
    surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, width, height);
	
	//assign the surface to the cairo drawing context, cr_main
	cr_main = cairo_create (surface);
    
    //allocate a new drawing area to the GtkWidget drawing_area
    drawing_area = gtk_drawing_area_new();
    
    //connects draw_cb() function to signal "draw" for object drawing_area
    g_signal_connect (drawing_area, "draw",G_CALLBACK (draw_cb), 0);
    
    //connects destroy() function to signal "destroy" for object window
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), 0);
    
    //adds the GtkWidget drawing_area to the container window
    gtk_container_add(GTK_CONTAINER(window), drawing_area);
    
    //show the window widget and its child widget
    gtk_widget_show_all  (window);
    
    //call the execution of the gtk+ main loop
    gtk_main ();
}
