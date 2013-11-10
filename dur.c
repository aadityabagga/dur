//A program to calculate the no of days between 2 dates in format yyyy-mm-dd
//Takes 2 command line args- initial date and final date

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

main(int argc, char* argv[])
{
        if(argc != 3 ) {
                printf("Invalid number of arguments\n");
                exit(1);
        }
	
	//Extract the numbers from the date
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


	//Now the date part


	//int flag=0;	//to check for wrong dates
	int y=0,m=0,d=0;	//to store the date

	if(strcmp(yi,yf))	//Calculate the difference in years
	{
		y=strcmp(yf,yi);
		printf("%d",y);
		
		month(mf,mi);	//Now Check difference in months
	}
	
	else 		//Year same, check month
	{
		if(strcmp(mf,mi))
		{
			month(mf,mi);	//Calculate the difference in months

			day(df,di);
			//if(strcmp(mf,mi)) //Calculate the difference in months
			//{
			//	m=strcmp(mf,mi);
                	//	printf(" %d",m);

			//	goto day;     //Now Check difference in days
			//}
			
			else	//Month same, check day
			{
				day:
					if(strcmp(df,di)) //Calculate the difference in days
                        		{
                                		d=strcmp(mf,mi);
                                		printf(" %d",d);
					}
					
					else	//Update on same day
					{
						printf("You have updated today!\n");
						exit(0);
					}


                        }

			
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


