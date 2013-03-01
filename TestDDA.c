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

#include "LineDrawing.h"
#include <math.h>
void onDraw(cairo_t *cr)	//drawing david's star to test DDA algorithm
{
	set_RGB(0,0,0);	//set color black
	
	lineDDA(cr,60,10,10,97);	//triangle straight
	lineDDA(cr,10,97,110,97);
	lineDDA(cr,110,97,60,10);
	
	lineDDA(cr,10,30,110,30); //triangle upside down
	lineDDA(cr,10,30,60,117);
	lineDDA(cr,60,117,110,30);
	
}

int main(int argc, char **argv)
{
	setDraw(&onDraw);
	window_set_width_height(120,127);
	initWindow(argc,argv);
	return 0;
}
