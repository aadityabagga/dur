/*A header file to convert a string containing numbers to an integer, and perform various other string related functions. 
 
Copyright (C) 2013  Aaditya Bagga  aaditya_gnulinux@zoho.com 
  
 This program is free software: you can redistribute it and/or modify 
 it under the terms of the GNU General Public License as published by 
 the Free Software Foundation, either version 3 of the License, or 
 any later version. 
 
 This program is distributed WITHOUT ANY WARRANTY;
 without even the implied warranty of 
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 See the GNU General Public License for more details. 
	        
 You should have received a copy of the GNU General Public License 
 along with this program.  If not, see <http://www.gnu.org/licenses/>. 
*/ 

/*Include Header guard*/
#ifndef ADD_H_GUARD
#define ADD_H_GUARD

#include <stdlib.h>

unsigned int length(char* string)
{
	unsigned int len=0;

	char c=*string;		/*The first character of the string*/
	while(c!='\0')
	{
		len=len+1;	/*len incremented on reading each character*/
		c=*(string+len);	/*now point to next character*/
	}
	
	return len;
}

unsigned int to_int(char* string)
{
	unsigned int res=0;	/*To store the int result*/

	int l=length(string);	/*Calucalate length of the string*/

	int i;	/*Counter variable*/
	for(i=l-1;i>=0;i--)
	{
		int d=(int)string[l-1-i]-48;   /*Convert each character to int*/
		res=10*res+d;
	}
	return res;
}

char* copy(char* str,int start,int end)
{
	
	int len=length(str);
	int limit=end-start+1;

	/*Error Checking*/

	if((start<0||start>len) || (end<start||end>=len))
	{
		return "err";
	}

	int i;
	
	char *outstr=(char*)malloc(end-start+1+1);	/*Allocate memory to the string being copied back*/
	/*First +1 used because index starts from 0, and 2nd +1 beacuse space required for \0  at the end*/

	int j=0;	/*Counter which will be used in storing the output string*/
	for(i=start;i<=end;i++)
	{
		*(outstr + j)=*(str + i);
		j=j+1;
	}
	*(outstr + limit)='\0';	/*Insert null character at the end*/
	return outstr;
}

int equals(char* str1,char* str2)
{
	int len1,len2;
	len1=length(str1);
	len2=length(str2);
	
	if(len1!=len2)	/*No need to check the contents if the length is different*/
	{
		return 1;
	}

	int i;
	char c;

	for(i=0;i<len1;i++)
	{
		if(*(str1 + i) != *(str2 + i))
		{
			/*String not equal*/
			return 1;
		}
	}

	return 0;
}
/*End Header Guard*/
#endif
