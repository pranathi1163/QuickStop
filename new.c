#include<stdio.h>
#include<string.h>
#include<conio.h>
//#include<ctype.h>
#include<stdlib.h>
#include<time.h>


void add();
void list();
void edit();
void delete1();
void search();
void feedback();
void service();
void adminLogin();
int total=0;

struct CustomerDetails
{
char roomnumber[10];
char name[20];
char address[25];
char phonenumber[15];
char nationality[15];
char email[20];
char period[10];
char arrivaldate[10];
}s;

int main()
{
    int i=0;
    time_t t;
    time(&t);
    char choice;
    printf("\n Enter 1 to enter as admin ");
    printf("\n Enter 2 to enter as user \n");
    int ch;
    scanf("%d",&ch);
    printf("ch %d\n",ch);
    switch(ch)
            {
              case 1:
                        adminLogin();
                        break;
              case 2:
                        login();
                        break;
              default:
                    system("cls");
                    printf("Incorrect Input");
                    printf("\n Press any key to continue");
                    getch();
            }

    system("cls");
    while(1)  //infinte loop
    {
        system("cls");
        while(ch==1)
        {
            printf("\n\n");
            printf(" ************************************  |MAIN MENU|   *********************************************** \n");
            printf("\n");
            printf("\t\t *Please enter your choice for menu :");
            printf("\n\n");
            printf(" \n Enter 1 -> View Customer Record");
            printf("\n");
            printf(" \n Enter 2 -> Delete Customer Record");
            printf("\n");
            printf(" \n Enter 3 -> Search Customer Record");
            printf("\n");
            printf(" \n Enter 4 -> Edit Record");
            printf("\n");
            printf(" \n Enter 5 -> Exit");
            printf("\n");
            printf("\n\nCurrent date and time : %s",ctime(&t));

            choice=getche();
            switch(choice)
            {

              case '1':
                        list();
                        break;
              case '2':
                        delete1();
                        break;
              case '3':
                        search();
                        break;
              case '4':
                        edit();
                        break;
              case '5':
                    system("cls");
                    printf("\n\t EXIT");
                    exit(0);
                    break;
                default:
                    system("cls");
                    printf("Incorrect Input");
                    printf("\n Press any key to continue");
                    getch();

            }

        }

        while(ch==2)
        {
            printf("\n\n");
            printf(" ************************************  |MAIN MENU|   *********************************************** \n");
            printf("\n");
            printf("\t\t *Please enter your choice for menu :");
            printf("\n\n");
            printf(" \n Enter 1 -> Book a room ");
            printf("\n");
            printf(" \n Enter 2 -> View Customer Record");
            printf("\n");
            printf(" \n Enter 3 -> Delete Customer Record");
            printf("\n");
            printf(" \n Enter 4 -> Search Customer Record");
            printf("\n");
            printf(" \n Enter 5 -> Edit Record");
            printf("\n");
            printf(" \n Enter 6 -> Complaints and Suggestions");
            printf("\n");
            printf(" \n Enter 7 -> Services");
            printf("\n");
            printf(" \n Enter 8 -> Exit");
            printf("\n");
            printf("\n\nCurrent date and time : %s",ctime(&t));

                choice=getche();

                switch(choice)
                {
                  case '1':
                            add();
                            break;
                  case '2':
                            list();
                            break;
                  case '3':
                            delete1();
                            break;
                  case '4':
                            search();
                            break;
                  case '5':
                            edit();
                            break;
                  case '6':
                            feedback();
                            break;
                  case '7':
                            service();
                            break;
                  case '8':
                        system("cls");
                        printf("\n\nYour total payment is:%d",total);
                        printf("\n\n\t *****THANK YOU*****");
                        printf("\n\t FOR TRUSTING OUR SERVICE");
                        exit(0);
                        break;
                    default:
                        system("cls");
                        printf("Incorrect Input");
                        printf("\n Press any key to continue");
                        getch();

                }

        }
  }

}

void adminLogin()
{
  int a=0,i=0;
  char aname[]="admin",c='*';
  char pword[]="admin";
  char admin[10];
  char pass[10];
  do
  {
      system("cls");
     l2 : printf("ENTER ADMIN NAME AND PASSWORD:\n");
      scanf("%s%s",&admin,&pass);
      if(strcmp(aname,admin)==0 && strcmp(pword,pass)==0)
      {
        printf("\nYOUR LOGIN IS SUCESSFUL.");
        break;
      }
      else
      {
        printf("\nSORRY!YOUR LOGIN IS UNSUCESSFUL.");
        a++;
        getch();
      }

  }
  while(a<=2);
  if(a>2)
  {
     printf("\nSorry you have entered the wrong username and password for four times!!!\n\n");
     goto l2;
  }
  system("cls");

}

void login()
{
  int a=0,i=0;
  char uname[26],c='*';
  char pword[10];
  char user[10];
  char pass[10];
  do
  {
      system("cls");
     l2 : printf("CREATE AN USERNAME AND PASSWORD:\n");
      scanf("%s%s",&user,&pass);
      printf("\n Welcome to WILD LIFE RESORT\n");
      printf("\t\t\tLogin form\t\t\t\n");
      printf("\nEnter user name : ");
      scanf("%s",&uname);
      printf("\nEnter the password:");
      while(i<10)
      {
          pword[i]=getch();
          c=pword[i];
          if(c==13)break;
          else printf("*");
          i++;
      }
      pword[i]='\0';
      i=0;
      if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
      {
        printf("\nYOUR LOGIN IS SUCESSFUL.");
        break;
      }
      else
      {
        printf("\nSORRY!YOUR LOGIN IS UNSUCESSFUL.");
        a++;
        getch();
      }

  }
  while(a<=2);
  if(a>2)
  {
     printf("\nSorry you have entered the wrong username and password for four times!!!\n\n");
     goto l2;
  }
  system("cls");

}

void add()
{
    FILE* f;
    char test;

    f=fopen("add.txt","a+");
    if(f==0)
    {
        f=fopen("add.txt","w+");
        system("cls");
        getch();
    }

    while(1)
    {
      system("cls");
      int count;
      printf("\n Enter Customer Details:");
      printf("\n**************************");
   l : printf("\nWhat type of room you want to book?\n");
      printf("\nEnter (1) for Basic Room -> Rs 2000\n");
      printf("\nEnter (2) for Medium Room -> Rs 3000\n");
      printf("\nEnter (3) for Deluxe Room -> Rs 5000\n");
      scanf("%d",&count);
      if(count==1)
      {
          printf("\nYou have selected a Basic room.\nEnjoy your stay.\n");
          total+=2000;
      }
      else if(count==2)
      {
          printf("\nYou have booked a Medium room.\nEnjoy your stay.\n");
          total+=3000;
      }
      else if(count==3)
      {
          printf("\nYou have booked a Deluxe room.\nEnjoy your stay.\n");
          total+=5000;
      }
      else if(count!=1 && count!=2 && count!=3)
      {
          printf("\nSelect a valid room.\n");
          goto l;
          break;
      }

     //fflush(stdin);
     printf("Enter Name:");
     scanf("%s",s.name);
     char temp[200]="";
     strncat(temp,s.name,sizeof(s.name));
     strncat(temp,"\t",4);
     printf("\nEnter Address :");
     scanf("%s",s.address);
     strncat(temp,s.address,sizeof(s.address));
     strncat(temp,"\t",4);
   w : printf("\nEnter Phone Number :");
     scanf("%s",s.phonenumber);
     strncat(temp,s.phonenumber,10);
     strncat(temp,"\t",4);
     if(strlen(s.phonenumber)<10 || strlen(s.phonenumber)!=10)
     {
         printf("\nEnter a valid number.");
         goto w;
     }

     printf("\nEnter Nationality:");
     scanf("%s",s.nationality);
     strncat(temp,s.nationality,sizeof(s.nationality));
     strncat(temp,"\t",4);
     printf("\nEnter Email:");
     scanf("%s",s.email);
     strncat(temp,s.email,sizeof(s.email));
     strncat(temp,"\t",4);
     printf("\nEnter Period(\'x\'days):");
     scanf("%s",&s.period);
     strncat(temp,s.period,sizeof(s.period));
     strncat(temp,"\t",4);
     printf("\nEnter Arrival date(dd/mm/yyyy):");
     scanf("%s",&s.arrivaldate);
     strncat(temp,s.arrivaldate,sizeof(s.arrivaldate));

     fprintf(f,"\n");
     printf("\nsize of temp : %d",sizeof(temp));
     fwrite(temp,strlen(temp),1,f);
     //printf("\n%s \t\t%s\t\t %s \t\t%s\t\t%s\t \t    %s  \t     %s",s.name,s.address,s.phonenumber,s.nationality,s.email,s.period,s.arrivaldate);
     // fflush(stdin);
      printf("\n\n 1 Room is successfully booked!!");
      printf("\nPress 'esc' key to exit ,any other key to add another customer detail:");
      test=getche();

      if(test==27)
      {
          //fwrite("1 Room is successfully booked!!",40,1,f);
          break;
      }


    }
    //fflush(f);
    fclose(f);

}

void delete1()
{

        FILE *f,*t;
        int i=1;
        if((t=fopen("temp.txt","w"))==NULL)
        exit(0);
        if((f=fopen("add.txt","r"))==NULL)
        exit(0);
        system("cls");
        printf("Enter the name of the customer  to be deleted from the database: \n");
        fflush(stdin);
        char name[26];
        scanf("%s",&name);
        while(fscanf(f,"%s%s%s%s%s%s%s", s.name,s.address,s.phonenumber,s.nationality,s.email,s.period,s.arrivaldate)!=EOF)
              {
                           if(strcmp(s.name,name)==0)
                           {            i=0;
                                         continue;
                           }
                           else
                                    {
                                         char temp[200]="";
                                         strncat(temp,s.name,sizeof(s.name));
                                         strncat(temp,"\t",4);
                                         strncat(temp,s.address,sizeof(s.address));
                                         strncat(temp,"\t",4);
                                         strncat(temp,s.phonenumber,10);
                                         strncat(temp,"\t",4);
                                         strncat(temp,s.nationality,sizeof(s.nationality));
                                         strncat(temp,"\t",4);
                                         strncat(temp,s.email,sizeof(s.email));
                                         strncat(temp,"\t",4);
                                         strncat(temp,s.period,sizeof(s.period));
                                         strncat(temp,"\t",4);
                                         strncat(temp,s.arrivaldate,sizeof(s.arrivaldate));
                                         fprintf(t,"\n");
                                         fwrite(temp,strlen(temp),1,t);
                                    }
              }
              if(i==1)
              {
                    printf("\n\n Records of Customer in this  Room number is not found!!");
                    getch();
                    fclose(f);
                    fclose(t);
                    goto l2;

              }
              fclose(f);
              fclose(t);
              remove("add.txt");
              rename("temp.txt","add.txt");
              printf("\n\nThe Customer is successfully removed.");
             l2 : fclose(f);

              fclose(t);

              getch();



    }


void list()
{

     FILE *f;
     int i;
     if((f=fopen("add.txt","r"))==NULL)
     exit(0);
     system("cls");
     printf("NAME\t ");
     printf("\tADDRESS ");
     printf("\tPHONE NUMBER ");
     printf("\tNATIONALITY ");
     printf("\tEMAIL ");
     printf("\t\t PERIOD ");
     printf("\t ARRIVAL DATE \n");

    for(i=1;i<=118;i++)
    printf("-");
    char temp[200];
    while(fscanf(f,"%s%s%s%s%s%s%s", s.name,s.address,s.phonenumber,s.nationality,s.email,s.period,s.arrivaldate)!=EOF)
    {
        //printf("\n%s",temp);
       printf("\n%s \t\t%s\t\t %s \t\t%s\t\t%s\t \t    %s  \t     %s",s.name,s.address,s.phonenumber,s.nationality,s.email,s.period,s.arrivaldate);
    }
    printf("\n");

    for(i=1;i<=118;i++)
       printf("-");

       fclose(f);

       getch();


}


void search()
{

  system("cls");
  FILE *f;
  int flag=1;
  f=fopen("add.txt","r+");
  if(f==0)
  exit(0);
  fflush(stdin);
  printf("Enter name of the customer to search its details: \n");
  char name[26];
  scanf("%s", &name);
  while(fscanf(f,"%s%s%s%s%s%s%s", s.name,s.address,s.phonenumber,s.nationality,s.email,s.period,s.arrivaldate)!=EOF)

  {

     if(strcmp(s.name,name)==0)

     {

       flag=0;
       printf("\n\tRecord Found\n ");
       printf("\nName:\t%s",s.name);
       printf("\nAddress:\t%s",s.address);
       printf("\nPhone Number:\t%s",s.phonenumber);
       printf("\nNationality:\t%s",s.nationality);
       printf("\nEmail:\t%s",s.email);
       printf("\nPeriod:\t%s",s.period);
       printf("\nArrival date:\t%s",s.arrivaldate);

       flag=0;
       break;


     }


  }

  if(flag==1)
  {

    printf("\n\tRequested Customer could not be found!");

  }

  getch();
  fclose(f);

}


void edit()
{
	FILE *f;
	int k=1;
	char name[20];
	long int size=sizeof(s);
	if((f=fopen("add.txt","r+"))==NULL)
		exit(0);

	system("cls");

	printf("Enter name of the customer to edit:\n\n");
	scanf("%s",&name);
	fflush(stdin);
	while(fscanf(f,"%s%s%s%s%s%s%s", s.name,s.address,s.phonenumber,s.nationality,s.email,s.period,s.arrivaldate)!=EOF)
	{
		if(strcmp(s.name,name)==0)
		{
			k=0;
			/*
			printf("\nEnter Name    :");
			fflush(stdin);
			scanf("%s",&s.name);
			printf("\nEnter Address        :");
			scanf("%s",&s.address);
			printf("\nEnter Phone number :");
			scanf("%s",&s.phonenumber);
            w: printf("\nEnter Phone Number :");
            scanf("%s",s.phonenumber);
            if(strlen(s.phonenumber)<10 || strlen(s.phonenumber)!=10)
         {
            printf("\nEnter a valid number.");
            goto w;
         }

			printf("\nEnter Nationality :");
			scanf("%s",&s.nationality);
			printf("\nEnter Email :");
			scanf("%s",&s.email);
			printf("\nEnter Period :");
			scanf("%s",&s.period);
			printf("\nEnter Arrival date :");
			scanf("%s",&s.arrivaldate);
			fseek(f,size,SEEK_CUR);  //to go to desired position infile
			fwrite(&s,sizeof(s),1,f);*/
			 printf("Enter Name:");
             scanf("%s",s.name);
             char temp[200]="";
             strncat(temp,s.name,sizeof(s.name));
             strncat(temp,"\t",4);
             printf("\nEnter Address :");
             scanf("%s",s.address);
             strncat(temp,s.address,sizeof(s.address));
             strncat(temp,"\t",4);
           w : printf("\nEnter Phone Number :");
             scanf("%s",s.phonenumber);
             strncat(temp,s.phonenumber,10);
             strncat(temp,"\t",4);
             if(strlen(s.phonenumber)<10 || strlen(s.phonenumber)!=10)
             {
                 printf("\nEnter a valid number.");
                 goto w;
             }
             printf("\nEnter Nationality:");
             scanf("%s",s.nationality);
             strncat(temp,s.nationality,sizeof(s.nationality));
             strncat(temp,"\t",4);
             printf("\nEnter Email:");
             scanf("%s",s.email);
             strncat(temp,s.email,sizeof(s.email));
             strncat(temp,"\t",4);
             printf("\nEnter Period(\'x\'days):");
             scanf("%s",&s.period);
             strncat(temp,s.period,sizeof(s.period));
             strncat(temp,"\t",4);
             printf("\nEnter Arrival date(dd/mm/yyyy):");
             scanf("%s",&s.arrivaldate);
             strncat(temp,s.arrivaldate,sizeof(s.arrivaldate));
             fprintf(f,"\n");
             //printf("\nsize of temp : %d",sizeof(temp));
             fseek(f,size,SEEK_CUR);
             fwrite(temp,strlen(temp),1,f);
			break;
		}
	}
	if(k==1)
        {
		printf("\n\nTHE RECORD DOESN'T EXIST!!!!");
		fclose(f);
		getch();
	    }
    else
        {
	fclose(f);
	printf("\n\n\t\tYOUR RECORD IS SUCCESSFULLY EDITED!!!");
	getch();
}

}


void feedback()
{

    system("cls");

    char x[300];

    FILE *f;

    if(f == NULL)

    {
        printf("\nFile can not be opened.\n");
    }
    printf("\nPlease enter your complaints or suggestions.\n");

    fflush(stdin);
    gets(x);

   f=fopen("feedback.txt","w+");

   fputs(x,f);

    fclose(f);

}

void service()

{

    system("cls");
    int a,n;
    printf("\nWhich service do you want to choose?\n");
    printf("\n 1. Jungle Walk\n 2. Jungle Safari\n 3. Swimming pool\n 4. Kids area\n 5. Cultural show");
    scanf("%d",&a);

    switch(a)

    {

       case 1:
           printf("\nYou choose Jungle Walk.\nHow many people?\n");

           scanf("%d",&n);

        total+=((n)*(1000));

        break;

        case 2:

            printf("\nYou choose Jungle safari.\nHow many people?\n");

            scanf("%d",&n);

            total+=((n)*(1500));

            break;

        case 3:

             printf("\nYou choose Swimming pool.\nHow many people?\n");

             scanf("%d",&n);
             total+=((n)*(1500));
             break;

        case 4:
             printf("\nYou choose Kids area.\nHow many people?\n");
            scanf("%d",&n);
            total+=((n)*(2000));
            break;

        case 5:
            printf("\nYou choose Cultural show.\nHow many people?\n");
            scanf("%d",&n);
            total+=((n)*(1500));
           break;


        default:
            printf("\nSorry!!We don't have that service.\n");
            break;
    }

}

