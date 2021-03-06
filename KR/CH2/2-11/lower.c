/*
 * lower.c
 * 
 * Copyright 2019 graf <g@raspberrypi>
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


#include <stdio.h>

int lower(int c);
int lower2(int c);

int main(int argc, char **argv)
{
	puts("top of routine...");
	/*
	int t = lower2('T');
	puts("before function call");
	printf("pass T into lower: %c\n", t);
	puts("after function call"); */
	return 0;
}

int lower2(int c) 
{
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : (c);
}

int lower(int c) 
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}
