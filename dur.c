//A program to calculate the no of days between 2 dates in format yyyy-mm-dd
//Takes 2 command line args- initial date and final date

#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"to_int.h"

main(int argc, char* argv[])
{
        if(argc != 3 ) {
                printf("Invalid number of arguments\n");
                exit(1);
        }
	
	//Extract the year,monthe,day components from the date

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
	
	printf("%s %s %s %s %s %s\n",yi,mi,di,yf,mf,df);

	//Make a structure for the date
	
	struct date
	{
		int year;
		int month;
		int day;
	}d1,d2;


	//Convert the string date components to int and assign them to the structure elements

	d1.year=to_int(yi);
        d1.month=to_int(mi);
        d1.day=to_int(di);
        d2.year=to_int(yf);
        d2.month=to_int(mf);
	d2.day=to_int(df);

        printf("%d %d %d %d %d %d\n",d1.year,d1.month,d1.day,d2.year,d2.month,d2.day);


        //store difference b/w the date elements
        int dy=d2.day-d1.day;
        int dm=d2.month-d1.month;
        int dd=d2.day-d1.day;


	//*Now the date part


	//int flag=0;	//to check for wrong dates
	int d=0;	//to store the output, ie difference in days


	//Procedure :find diff in year -> find diff in month -> find diff in days

	//diff in year: find diff in year -> diff in month -> diff in days
	//diff in months -> find diff in months -> diff in days	
	//diff in days -> find diff in days	

	if(!dy)	//Year same
	{
		//diff_month(d2.month,d1.month);	//Check difference in months
	}
	else 		//There is Difference in Years
	{
		//diff_year(d2.year,d1.year);		//Check difference
		
	}



	int i;
	char *ptr;
	ptr=argv[1];
	
	while (*ptr != '\0')
	{
	//	printf("%c",*ptr);
		ptr++;
	}
}


