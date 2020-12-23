/*
 * bios.hpp
 * 
 * Copyright 2020  <janrinze@hikey970.local>
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


#ifndef BIOS_HPP
#define BIOS_HPP

#include "file.h"

class bios
{
	public:
		int test(int me){
			return me;
		};
		void bios(int addr);
		void writechar(int c);
		void cls();
		void mode(int m);

		int open(String &name,File & f);
		int close(String &name,File & f);
		int read(File & f,int*d,int size);
		int write(File & f,int*d,int size);

	private:
		int address;
		/* add your private declarations */
};

#endif /* BIOS_HPP */ 
