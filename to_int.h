//A program/header file to convert a string containing numbers to an integer 
 
//Copyright (C) 2013  Aaditya Bagga  aaditya_gnulinux@zoho.com 
  
/*This program is free software: you can redistribute it and/or modify 
 it under the terms of the GNU General Public License as published by 
 the Free Software Foundation, either version 3 of the License, or 
 any later version. 
 
 This program is distributed WITHOUT ANY WARRANTY; without even the implied warranty of 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 See the GNU General Public License for more details. 
	        
 You should have received a copy of the GNU General Public License 
 along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/ 

#include<string.h>
#include<math.h>
int to_int(char* string)
{
	unsigned int res=0;
	int l=strlen(string);
	int i;	//Counter variable
	for(i=l-1;i>=0;i--)
	{
		int d=(int)string[l-1-i]-48;	//Convert each character to int	
		res=res+d*pow(10,i);
	}
	return res;
}
