#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct
{
    char f_number[20],a_name[20],d[20],s[20],d_date[20],d_time[20],a_date[20],a_time[20],p[20];
}flight;
int main()
{             int choice,shift,found,length;
char source,destination[10];
   FILE *fp;
   Label1:
      printf("\n1 -> Store a new record in database\n");
      printf("2 -> Search a flight details by destination\n");
      printf("3 -> Search flight details by source\n");
      printf("4 -> Search flight details by price");
      printf("5 -> quit");
      printf("Enter your choice : ");

      scanf("%d",&choice);

      switch(choice)
      {
       case  1:
       Label2:
	      printf("\nenter flight number: ");
       scanf("%d",&flight.f_number);
       printf("\nenter airline name: ");
       scanf("%d",&flight.a_name);
       printf("\nenter destination: ");
       scanf("%d",&flight.d);
       printf("\nenter departure date: ");
       scanf("%d",&flight.d_date);
       printf("\nenter departure time: ");
       scanf("%d",&flight.d_time);
       printf("\nenter arrival date: ");
       scanf("%d",&flight.a_date);
       printf("\nenter arrival time: ");
       scanf("%d",&flight.a_time);
       printf("\nenter price: ");
       scanf("%d",&flight.p);

       fp=fopen("flight.txt","a+");

       fprintf(fp,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",flight.f_number,flight.a_name,flight.d,flight.s,flight.d_date,flight.d_time,flight.a_date,flight.a_time,flight.p);
       fclose(fp);
       printf("Flight record has been added successfully...\n");
       printf("\n\n1 -> Wish to add another record to database");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit from Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label2;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("Exiting.........");
	break;
	}

       case 2:
       Label4:

       printf("\nEnter destinatiopn: ");
       scanf("%s",&destination);
       printf("Searching record with destination=%s.\n",destination);
	   found=0;
	   if((fp=fopen("flight.txt","r"))==NULL)
	{
	    printf(" ! The File is Empty...\n\n");
	}
	else
	{
	    while(!feof(fp)&& found==0)
		{
		fscanf(fp,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",&flight.f_number,flight.a_name,flight.d,flight.s,flight.d_date,flight.d_time,flight.a_date,flight.a_time,flight.p);

		length = strlen(flight.d);
		if(flight.d[length]==destination[length])
		    found=1;
	    }
	    }
       if(found)
       {
	 printf("\nThe record is found.");
	 fprintf(fp,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",flight.f_number,flight.a_name,flight.d,flight.s,flight.d_date,flight.d_time,flight.a_date,flight.a_time,flight.p);

       }
       else
       {
	 printf("Not found...\n");
	 getch();
       }
       Label5:
       printf("\n\n1 -> Wish to search another record");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit from Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label4;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto Label5;
	}
       case 3:

       Label6:
       printf("\nEnter the source: ");
       scanf("%s",&source);
       printf("Searching record with source=%d.\n",source);
	   found=0;
	   if((fp=fopen("flight.txt","r"))==NULL)
	{
	    printf(" ! The File is Empty...\n\n");
	}
	else
	{
	    while(!feof(fp)&& found==0)
		{
		fprintf(fp,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",flight.f_number,flight.a_name,flight.d,flight.s,flight.d_date,flight.d_time,flight.a_date,flight.a_time,flight.p);

		if(flight.s==source)
		    found=1;
	    }
	    }
       if(found)
       {
	 printf("\nThe record is found.");
	 fprintf(fp,"\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",flight.f_number,flight.a_name,flight.d,flight.s,flight.d_date,flight.d_time,flight.a_date,flight.a_time,flight.p);
       }
       else
       {
	 printf("Not found...\n");
	 getch();
       }
       Label7:
       printf("\n\n1 -> Wish to search more..");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit from Program\n");
       scanf("%d",&shift);
       if(shift==1)
	goto Label6;
       if(shift==2)
	goto Label1;
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto Label7;
	}
       case 4: break;
       default :
	  printf(" Bad choice...Enter the choice again...\n");
	  goto Label1;
	}

      getch();
      return 0;
}
code.c
Displaying code.c.