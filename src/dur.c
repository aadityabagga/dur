/*A program to calculate the no of days between 2 dates
Takes 2 command line args- initial date and final date in format yyyy-mm-dd

Copyright(C) 2013-2014 Aaditya Bagga (aaditya_gnulinux@zoho.com)

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int d=0;        /*to store the output,ie, difference in days*/

/*Make a structure for the date*/
struct date
{
	int year;
	int month;
	int day;
} d1,d2;		/*d1 = initial date, d2 = final date*/

/*Make a macro for checking leap year*/
#define is_leap(year) (((year%4 == 0) && ((year%100) != 0)) || ((year%400)==0))

/*Make a macro for checking elapsed days*/
#define check_elapsed_days(days) (days)

/*Protoypes for functions*/
void check_months(int,int,int,int,int); 
void diff_years(int,int);
int check_days(int,int);	

int main(int argc, char* argv[])
{
        /*Declarations upfront*/
	
	int i;	/*Counter*/
	int flag=0;	/*Flag to check invalid data*/
	
	/*To store the different parts (year,month,day) of the dates*/
	/*(Size +1 for null char at end)*/
	char yi[5];
	char yf[5];
	char mi[3];
	char mf[3];
	char di[3];
	char df[3];
        
	int dy,dm,dd; /*To store the difference between the date components*/
	int cd1,cd2;	/*To check days in months of the dates*/

	/*Now the program begins, ie, statements*/

	if(argc != 3 ) {
                printf("Invalid number of arguments. See the man page for more info.\n");
                exit(1);
        }
	
	/*Check the entered string*/

	for(i=0;i<10;i++)
	{
		if(i==4||i==7)
		{
			/*Skip for the dashes in the date*/
			continue;
		}
		else
		{
			char c1=*(argv[1]+i);
			char c2=*(argv[2]+i);
			if((c1<48||c1>57)||(c2<48||c2>57))	/*Character is not an integer: invalid input*/
			{
				flag=1;
			}
		}
	}

	if(flag==1)
	{
		printf("Incorrect arguments. The arguments are like yyyy-mm-dd yyyy-mm-dd where the first is the initial date and the second is the final date.\n");
		return 1;	/*Exit*/
	}

	/*Extract the year,month,day components from the date*/

	/*Copy the requisite characters from the input strings*/
	strncpy (yi, argv[1], 4);
        strncpy (mi, argv[1]+5, 2);
        strncpy (di, argv[1]+8, 3);
        strncpy (yf, argv[2], 4);
        strncpy (mf, argv[2]+5, 2);
        strncpy (df, argv[2]+8, 3);

	/*insert null character at the end where required*/
	yi[4]='\0';        
	mi[2]='\0';        
        yf[4]='\0';
	mf[2]='\0';
	
	/*Convert the string date components to int and assign them to the structure elements*/
	d1.year=atoi(yi);
        d1.month=atoi(mi);
        d1.day=atoi(di);
        d2.year=atoi(yf);
        d2.month=atoi(mf);
	d2.day=atoi(df);
        
	/*store difference b/w the date elements*/
	dy=d2.year-d1.year;
        dm=d2.month-d1.month;
        dd=d2.day-d1.day;

	/*Check for invalid dates*/

	/* Minimum year changed to 1 instead of 0; suggested by maandree (https://github.com/maandree) */
	if((d1.year < 1 || d1.year > 5000)||(d2.year < 1 || d2.year > 5000))	/*Year out of range*/
	{
		flag=1;
	}
	
	if((d1.month < 1 || d1.month > 12) || (d2.month < 1 || d2.month > 12))	/*Month invalid*/
	{
		flag=1;
	}
	
	/*Check for valid days*/
	/*Find the max valid days for given month*/
	cd1=check_days(d1.year,d1.month);
	cd2=check_days(d2.year,d2.month);

	if((d1.day < 1 || d1.day > cd1) || (d2.day < 1 || d2.day > cd2))	/*Day invalid*/
	{
		flag=1;
	}

	if(flag == 1)
	{
		printf("Invalid date(s) entered. Valid values for the dates are-\n 1 - 5000 for year,\n 1 - 12 for month,\n 1 - max no of days in month for day.\n");
		
		return 1;	/*Exit*/
	}

	if(dy < 0)	/*Final date less than initial date?*/
	{
		printf("Did you enter the date correctly? The format is first earlier date, then later date.\n");
		return 1;
	}

	/*Now the date part*/
	/*Procedure:find diff in year -> find diff in month -> find diff in days

	diff in years: find diff in year -> diff in month -> diff in days
	diff in months -> find diff in months -> diff in days*/

	if(dy==0)	/*Year same*/
	{
		/*Check difference in months*/
		if(dm==0)	/*Month same*/
		{
			d=dd;	/*output=diff in days*/
			/*done*/
		}
		else
		{
			check_months(d1.year,d1.month,d2.month,d1.day,d2.day);
		}
	}
	else 		/*There is Difference in Years*/
	{
		/*Check if there is diff in years = 1 year, or more*/
		if(dy==1)
		{
			/*Only diff in months need to be checked*/

			/*When there is difference in year(s), the diff in months(and days) is divided into 2 parts: from the initial date to the end of initial year, and then from the start of the final year to the final date.*/

			check_months(d1.year,d1.month,12,d1.day,31);
			check_months(d2.year,1,d2.month,0,d2.day);	/* 0 is used as initial day to compensate for the day being lost due to 2 function calls to check_months*/
		}
		else
		{
			diff_years(d1.year,d2.year);	/*Check diff in years*/
		}
	}

	/*Print the output*/
	printf("%d days \n",d);
	return 0;
}

/*to find the no of days in a month*/

int check_days(int year,int month)	
{
	int leap=is_leap(year);		/*check if its leap year*/
	
	switch(month)
	{
		case 1:case 3: case 5:case 7: case 8: case 10: case 12:
			return 31;

		case 4: case 6: case 9:case 11:
			return 30;

		case 2:
		if(leap)
			return 29;
		else
			return 28;

		default: return 0;
	}
}

int check_remaining_days(int year,int month,int day)
{
	int days_in_month=check_days(year,month);
	
	return(days_in_month-day);
}

void check_months(int yr,int mi,int mf,int di,int df)
{
	/*This function has been made in such a way that mf>=mi, if the opposite is true, display a message to the effect.*/
	if(mi>mf)
	{
		printf("Did you enter the date correctly? Its like first earlier date, then later date.\n");
		exit(1);
	}

	if(mf==1)
	{
		/*if mf=1,ie,final month is january, then the days calculated as days in current month which is done at the end*/
	}
	else
	{
		d=d+check_remaining_days(yr,mi,di);	/*Add the days in current month*/
	}
	
	/*Days in current month added, move on to the next months*/

	mi=mi+1;	/*Increment the month as days in current month have been added*/

	while(mi<mf)
	{
		d=d+check_days(yr,mi);	/*add the days of the month*/
		mi=mi+1;	/*now increment to check for next month*/
	}

	/*Days in in-between months added; now add days in final month*/

	if(mi==13)
	{
		/*In this case initial month was 12,ie,december,and the days are calculated at the top as remaining days*/
	}
	else
	{
		d=d+check_elapsed_days(df);	/*add the days from the final month*/
	}
}

void diff_years(int yi,int yf)
{
	int dy=yf-yi;	/*Difference in years*/
	
	while(dy>1)
	{
		if (is_leap((yi+1)))	/*Check if next year is leap or not*/
			d=d+366;	/*Add the no of days in the year*/
		else
			d=d+365;	/*Add the no of days in the year*/

		yi=yi+1;	/*Increment the year to  check for next year*/
		dy=yf-yi;	/*Recalculate the difference*/
	}
	/*done with the difference in years*/

	/*now need to check the difference b/w months*/
	
	check_months(yi,d1.month,12,d1.day,31);
	check_months(yf,1,d2.month,0,d2.day);	/*0 is used as initial day to compensate for the day being lost due to 2 function calls to check_months*/
}
