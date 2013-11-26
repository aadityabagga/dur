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
