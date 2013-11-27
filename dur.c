//A program to calculate the no of days between 2 dates in format yyyy-mm-dd
//Takes 2 command line args- initial date and final date

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
#define is_leap(year) (((year%4==0) && (year%100)!=0)||(year%400)==0)

//Make a macro for checking elapsed days
#define check_elapsed_days(days) (days)

//Protoypes for functions
void diff_month(int,int,int); 

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

	if(!dy)	//Year same
	{
		//Check difference in months
		if(!dm)	//Month same
		{
			d=dd;	//output=diff in days
			//done
		}
		else
		{
			diff_month(d1.year,d1.month,d2.month);
		}
	}
	else 		//There is Difference in Years
	{
		//diff_year();		//Check difference
		diff_month(d1.year,d1.month,d2.month);
		
	}

	printf("Difference = %d day(s)\n",d);

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

void diff_month(int yr,int mi,int mf)
{
	
	d=d+check_remaining_days(mi,d1.day);	//Add the days in current month
	printf("initial date = %d %d %d\n",d1.year,d1.month,d1.day);
	printf("final date = %d %d %d\n",d2.year,d2.month,d2.day);
	printf("remaining days in month = %d\n",d);
	printf("final month = %d\n",mf);

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

	d=d+check_elapsed_days(d2.day);	//add the days from the final month

}

