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
#include "LineDrawing.h"
#include <stdlib.h>
#define ROUND(a) ((int) a+0.5)
void lineDDA(cairo_t *cr, int xA, int yA, int xB, int yB)
{
	int dX=xB-xA, dY=yB-yA,steps,k;
	float xIncrement, yIncrement, x=xA, y=yA;
	if(abs(dX) > abs(dY))
		steps = abs(dX);
	else
		steps = abs(dY);
	xIncrement = dX/(float)steps;
	yIncrement = dY/(float)steps;
	set_pixel(cr,ROUND(x),ROUND(y));
	for(k=0;k<steps;k++)
	{
		x+=xIncrement;
		y+=yIncrement;
		set_pixel(cr,ROUND(x),ROUND(y));
	}
}
