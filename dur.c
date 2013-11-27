//A program to calculate the no of days between 2 dates in format yyyy-mm-dd
//Takes 2 command line args- initial date and final date

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

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"to_int.h"

int d=0;        //to store the output,ie, difference in days

//Make a structure for the date
struct date
{
	int year;
	int month;
	int day;
}d1,d2;

//Make a macro for checking leap year
#define is_leap(year) (((year%4==0)&&((year%100)!=0)) || ((year%400)==0))

//Make a macro for checking elapsed days
#define check_elapsed_days(days) (days)

//Protoypes for functions
void diff_months(int,int,int,int,int); 
void diff_years(int,int);

void main(int argc, char* argv[])
{
        if(argc != 3 ) {
                printf("Invalid number of arguments\n");
                exit(1);
        }
	
	//Extract the year,month,day components from the date

	char yi[5],yf[5],mi[3],mf[3],di[3],df[3];	//size+1 for null character at the end
	
	strncpy (yi, argv[1], 4);
	strncpy (mi, argv[1]+5, 2);
	strncpy (di, argv[1]+8, 3);
	
	strncpy (yf, argv[2], 4);
        strncpy (mf, argv[2]+5, 2);
        strncpy (df, argv[2]+8, 3);

	yi[4]='\0';	//insert null character at the end
	mi[2]='\0';	
	yf[4]='\0';     //insert null character at the end
        mf[2]='\0';
	

	//Convert the string date components to int and assign them to the structure elements

	d1.year=to_int(yi);
        d1.month=to_int(mi);
        d1.day=to_int(di);
        d2.year=to_int(yf);
        d2.month=to_int(mf);
	d2.day=to_int(df);

        
	//store difference b/w the date elements
        int dy=d2.year-d1.year;
        int dm=d2.month-d1.month;
        int dd=d2.day-d1.day;


	//*Now the date part


	//int flag=0;	//to check for wrong dates: currently the program is non-interactive so its not being implemented yet


	//Procedure:find diff in year -> find diff in month -> find diff in days

	//diff in year: find diff in year -> diff in month -> diff in days
	//diff in months -> find diff in months -> diff in days	
	//diff in days -> find diff in days	

	if(dy==0)	//Year same
	{
		//Check difference in months
		if(dm==0)	//Month same
		{
			d=dd;	//output=diff in days
			//done
		}
		else
		{
			diff_months(d1.year,d1.month,d2.month,d1.day,d2.day);
		}
	}
	else 		//There is Difference in Years
	{
		//Check if there is diff in years = 1 year, or more
		if(dy==1)
		{
			//Only diff in months need to be checked

			//if(dm>=0)
			//{
				//Go from current month to end of year
				diff_months(d1.year,d1.month,12,d1.day,31);
				
				//Now go from start of year to end of month
				diff_months(d2.year,1,d2.month,1,d2.day);	//0 has been used to compensate the 1 day diff arising out of 2 runs of the diff_months function
			//}
			//else
			//{
			//Check difference in months
			//	diff_months(d2.year,d1.month,d2.month,d1.day,d2.day);	//This case is handled directly by the diff_months function
			//}
		}
		else
		{
			diff_years(d1.year,d2.year);	//Check diff in years
		}
	}

	printf(" %d day(s)\n",d);

}

int check_days(int year,int month)	//find the no of days in a month
{
	int leap=is_leap(year);		//check if its leap year
	
	//printf("Month = %d\n",month);

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

int check_remaining_days(int month,int day)
{
	int days_in_month=check_days(d1.year,month);
	//printf("Days in month = %d\n",days_in_month);
	return(days_in_month-day);
}

void diff_months(int yr,int mi,int mf,int di,int df)
{
	
	d=d+check_remaining_days(mi,di);	//Add the days in current month
	//printf("initial date = %d %d %d\n",d1.year,d1.month,d1.day);
	//printf("final date = %d %d %d\n",d2.year,d2.month,d2.day);
	//printf("remaining days in month = %d\n",d);
	//printf("final month = %d\n",mf);

	if(mf>mi)
	{
		mi=mi+1;	//Increment the month as days in current month have been added

		while(mi<mf)
		{
			d=d+check_days(yr,mi);	//add the days of the month
			mi=mi+1;	//now increment to check for next month
		}

	}
	else	
	{
		//there is difference of years, as initial month > final month
		//first the difference in years is calculated and added to the difference,
		//till there is only 1 year gap b/w the years

		//Check if current month is december
		if(mi==12)
		{
			//Start from the next year

			//Check if final month is 1,ie, January
			if(mf==1)
			{
				//Do nothing, as the days in last month are added(in the end of this function)
			}
			else
			{	
				//Add the days from the months from 1 till final month
				mi=1;	//Start from 1, ie,January
				while(mi<mf)
				{
					d=d+check_days(yr,mi);	//add the days of the month
					mi=mi+1;	//now increment to check for next month
				}
			}
		}
	}

	d=d+check_elapsed_days(df);	//add the days from the final month
}

void diff_years(int yi,int yf)
{
	//printf("Initial year = %d\n",yi);
	//printf("Final year = %d\n",yf);
	
	int dy=yf-yi;	//Difference in years
	
	while(dy>1)
	{
		//printf("%d:%d ",yi+1,is_leap((yi+1)));
		if (is_leap((yi+1)))	//Check if next year is leap or not
			d=d+366;	//Add the no of days in the year
		else
			d=d+365;	//Add the no of days in the year

		yi=yi+1;	//Increment the year to  check for next year
		dy=yf-yi;	//Recalculate the difference
	}
	//done with the difference in years

	//printf("Difference till now = %d\n",d);
	
	//now need to check the difference b/w months
	diff_months(yi,d1.month,d2.month,d1.day,d2.day);
}
