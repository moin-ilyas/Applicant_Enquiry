					/*Applicant Enquiry Management System*/
#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<stdlib.h>


struct Applicant
//to store Applicant details
{

    long ph;

    char name[20];
    char email[30];
	char add[20];
	

} obj; // using the object named obj

char query[20],name[20];

FILE *fp, *temp;

int i,n,ch,l,found;

int main()

{

main:

    system("cls");    

    printf("\n\t --------Applicant Enquiry Management System--------");
    printf("\n\t ----------By MOIN AMAAN KHAN------------");
    printf("\n\t -----to be presented to Mr. UPENDRA SINGH----");

    printf("\n\n\n\t\t\tMENU\n\t\t=====================\n\t\t[1] Add new Applicant\n\t\t[2] List all Applicants\n\t\t[3] Search Applicant\n\t\t[4] Edit Applicant\n\t\t[5] Delete Applicant\n\t\t[0] Exit\n\t\t=====================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {
	 //input 0 to exit the program
    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

         

    case 1:
		//to enter applicant details
        system("cls");

        fp=fopen("details.txt","a");

        for (;;)
		// this loop will execute as far as some terminating condition is reached
        {
            fflush(stdin);
            printf("To exit click enter or Enter your information below :\nName :");
	 
            scanf("%[^\n]",&obj.name);

            if(stricmp(obj.name,"")== '0' || stricmp(obj.name," ")==0)

                break;

            fflush(stdin);

            printf("Phone:");

            scanf("%ld",&obj.ph);

            fflush(stdin);

            printf("address:");

            scanf("%[^\n]",&obj.add);

            fflush(stdin);

            printf("email address:");

            gets(obj.email);

            printf("\n");

            fwrite(&obj,sizeof(obj),1,fp);

        }
	   

        fclose(fp);

        break;

        

    case 2:
		//to show the list of applicants
        system("cls");

        printf("\n\t\t================================\n\t\t\tlist OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\t    Address\t\tE-mail.\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("details.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&obj,sizeof(obj),1,fp)==1)

            {

                if(obj.name[0]==i || obj.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",obj.name,

                           obj.ph,obj.add,obj.email);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;

        
    case 3:
		//searching a particular applicant
        system("cls");

        do

        {

            found=0;

            printf("\n\n\tAPPLICANT SEARCH\n\t===========================\n\tName of applicant to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("details.txt","r");

            system("cls");

            printf("\n\nSearch result for '%s' \n===================================================\n",query);

            while(fread(&obj,sizeof(obj),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=obj.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\n",obj.name,obj.ph,obj.add,obj.email);

                    found++;

                    if (found%4==0)

                    {

                        printf("Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\nNo match found!");

            else

                printf("\n%d match(s) found!",found);

            fclose(fp);

            printf("\n Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

        
    case 4:
		//case used for editing an applicant's name
        system("cls");

        fp=fopen("details.txt","r");

        temp=fopen("temp.txt","w");

        fflush(stdin);

        printf("Edit applicant\n===============================\n\n\tEnter the name of applicant to edit:");

        scanf("%[^\n]",name);

        while(fread(&obj,sizeof(obj),1,fp)==1)

        {

            if(stricmp(name,obj.name)!=0)

                fwrite(&obj,sizeof(obj),1,temp);

        }

        fflush(stdin);

        printf("\n\nEditing '%s'\n\n",name);

        printf("Name(Use identical):");

        scanf("%[^\n]",&obj.name);

        fflush(stdin);

        printf("Phone:");

        scanf("%ld",&obj.ph);

        fflush(stdin);

        printf("address:");

        scanf("%[^\n]",&obj.add);

        fflush(stdin);

        printf("email address:");

        gets(obj.email);

        printf("\n");

        fwrite(&obj,sizeof(obj),1,temp);

        fclose(fp);

        fclose(temp);

        remove("details.txt");

        rename("temp.txt","details.txt");

        break;

        

    case 5:
		//case for deleting an applicant
        system("cls");

        fflush(stdin);

        printf("\n\n\tDELETE AN APPLICANT\n\t==========================\n\tEnter the name of applicant to be deleted:");

        scanf("%[^\n]",&name);

        fp=fopen("details.txt","r");

        temp=fopen("temp.txt","w");

        while(fread(&obj,sizeof(obj),1,fp)!=0)

            if (stricmp(name,obj.name)!=0)

                fwrite(&obj,sizeof(obj),1,temp);

        fclose(fp);

        fclose(temp);

        remove("details.txt");

        rename("temp.txt","details.txt");

        break;

    default:
  		//case for invalid input
        printf("Invalid choice");

        break;

    }

    printf("\n\n\n\t\tEnter the Choice:\n\n\t[1] Main Menu\t\t[0] \n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}
