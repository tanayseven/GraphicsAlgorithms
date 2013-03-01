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

void onDraw(cairo_t *cr)
{
	set_RGB(0,0,0);
	set_pixel(cr,40,40);
	set_RGB(255,0,0);
	set_pixel(cr,50,50);
	set_RGB(0,255,0);
	set_pixel(cr,60,60);
	set_RGB(0,0,255);
	set_pixel(cr,70,70);
}

int main(int argc, char **argv)
{
	setDraw(&onDraw);
	window_set_width_height(500,500);
	initWindow(argc,argv);
	return 0;
}
