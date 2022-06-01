#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct
{
    int day;
    int month;
    int year;
}
date;
typedef struct
{
    char first_name[10];
    char last_name[10];

    char phone_number[100];
    date DOB;
    char email[100];
    char address[100];
}
contact;
int valid_mail(char mail[])
{
    int i,found=0;
    for(i=0; i<strlen(mail); i++)
    {
        if(mail[i]=='@')
        {
            found=1;
            break;
        }
    }
    if(found)
    {
        for(i=i+2; i<strlen(mail); i++)
        {
            if(mail[i]=='.')
                return 1;
        }
    }
    return 0;
}
int valid_phone(char phone_number[])
{
    int i;
    for(i=0; i<strlen(phone_number); i++)
    {
        if(!isdigit(phone_number[i]))
            return 0;
    }
    return 1;
}


contact* load(char file_name[],int*n)
{

    FILE*f=fopen(file_name,"r");
    int i=0;
    contact*c=malloc(100*sizeof(contact));

    if(f!=NULL)
    {
        while(!feof(f))
        {
            fscanf(f,"%[^ ] ",c[i].first_name);
            fscanf(f,"%[^,],",c[i].last_name);
            fscanf(f,"%d",&c[i].DOB.day);
            fscanf(f,"%d",&c[i].DOB.month);
            fscanf(f,"%d,",&c[i].DOB.year);
            fscanf(f,"%[^,],",c[i].address);
            fscanf(f,"%[^,],",&c[i].phone_number);
            fscanf(f,"%[^\n]\n",c[i].email);


            /*   printf("%s  ",c[i].first_name);
               printf("%s ",c[i].last_name);
               printf("%d %d %d ",c[i].DOB.day,c[i].DOB.month,c[i].DOB.year);
               printf("%s ",c[i].address);
               printf("%s ",c[i].phone_number);
               printf("%s\n",c[i].email);
               */
            i++;
        }
        *n=i;
        return c;
        fclose(f);

    }
    else
    {
        printf("file not found");
    }

}

void search( contact *c,int n)
{
    char name[100];
    system("cls");
    printf("\nEnter the last name of person you want to Search\n");
    scanf("%s",name);

    int i,found=0;
    for(i=0; i<n; i++)
    {
        if(strcasecmp(c[i].last_name,name)==0)
        {
            printf("\n\tDetail Information About %s\n",name);
            printf("%s\n",c[i].first_name);
            printf("%d %d %d \n",c[i].DOB.day,c[i].DOB.month,c[i].DOB.year);
            printf("%s\n",c[i].address);
            printf("%s\n",c[i].phone_number);
            printf("%s\n",c[i].email);
            found=1;

        }

    }
    if(!found)
        printf("name not found");

}




void modify(contact*c,int n)
{
    char name[100];
    system("cls");
    printf("\nEnter the last name of person you want to Search\n");
    scanf("%s",name);
    int x;
    int i,found=0;
    int a[100];
    int t=0;
    for(i=0; i<n; i++)
    {


            if(strcasecmp(c[i].last_name,name)==0)
            {
                a[t]=i;
                t++;
                found=1;
            }
    }
    if(found==0)
        printf("not found");
    else{
            for(i=0; i<t-1; i++)
            {


                printf("\n\tDetail Information About %s\n",name);
                printf("%d.%s\n",i+1,c[a[i]].first_name);
                printf("%d %d %d \n",c[a[i]].DOB.day,c[a[i]].DOB.month,c[a[i]].DOB.year);
                printf("%s\n",c[a[i]].address);
                printf("%s\n",c[a[i]].phone_number);
                printf("%s\n\n",c[a[i]].email);
            }
            int y;
            if(t>1)
            {
                printf("enter number of contact you want to modify:\n");
                int z;
                scanf("%d",&z);
                y=z;
            }
            else y=0;

            while(1)
            {
                printf("what do you need to modify?\n");
                printf("1.first name\n2.last name\n3.date of birth\n4.address\n5.phone number\n6.email\n7.done\n");
                scanf("%d",&x);
                if(x==1)
                {
                    printf("enter new first name\n\n");
                    scanf("%s",c[a[y-1]].first_name);
                }
                else if(x==2)
                {
                    printf("enter new last name\n\n");
                    scanf("%s",c[a[y-1]].last_name);

                }
                else if(x==3)
                {
                    printf("\n\t**DATE OF BIRTH** \n");
                    do
                    {
                        printf("\nEnter the day: ");
                        scanf("%d",&c[a[y-1]].DOB.day);
                    }
                    while(c[a[y-1]].DOB.day<0||c[a[y-1]].DOB.day>32);
                    do
                    {
                        printf("\nEnter the month: ");
                        scanf("%d",&c[a[y-1]].DOB.month);
                    }
                    while(c[a[y-1]].DOB.month<0||c[a[y-1]].DOB.month>12);
                    do
                    {
                        printf("\nEnter the year: ");
                        scanf("%d",&c[a[y-1]].DOB.year);
                    }
                    while(c[a[y-1]].DOB.year<0||c[a[y-1]].DOB.year>2020);
                }
                else if(x==4)
                {
                    printf("enter new address\n\n");
                    scanf("%s",c[a[y-1]].address);
                }
                else if(x==5)
                {
                    do
                    {
                        printf("\nEnter phone number: ");
                        scanf("%s",c[a[y-1]].phone_number);
                    }
                    while(!valid_phone(c[a[y-1]].phone_number));
                }
                else if(x==6)
                {
                    do
                    {
                        printf("\nemail: ");
                        scanf("%s",c[a[y-1]].email);
                    }
                    while(!valid_mail(c[a[y-1]].email));
                }
                else if(x==7)
                    break;
            }
    }


//        if(!found)
//            printf("last name not found\n");
    }




    void add(contact*c,int*n)
    {
        int f,g=1;
        do
        {

            system("cls");


            printf("\nEnter a new contact\n");
            printf("first name: ");
            scanf("%s",c[*n].first_name);
            printf("\nlast name: ");
            scanf("%s",c[*n].last_name);
            printf("\n\t**DATE OF BIRTH** \n");
            do
            {
                printf("\nEnter the day: ");
                scanf("%d",&c[*n].DOB.day);
            }
            while(c[*n].DOB.day<0||c[*n].DOB.day>32);
            do
            {
                printf("\nEnter the month: ");
                scanf("%d",&c[*n].DOB.month);
            }
            while(c[*n].DOB.month<0||c[*n].DOB.month>12);
            do
            {
                printf("\nEnter the year: ");
                scanf("%d",&c[*n].DOB.year);
            }
            while(c[*n].DOB.year<0||c[*n].DOB.year>2020);
            printf("\naddress: ");
            getchar();
            gets(c[*n].address);
            do
            {
                printf("\nEnter phone number: ");
                scanf("%s",c[*n].phone_number);
            }
            while(!valid_phone(c[*n].phone_number));
            do
            {
                printf("\nemail: ");
                scanf("%s",c[*n].email);
            }
            while(!valid_mail(c[*n].email));
            printf("do you want to add another entry\n1.yes\n2.no");
            scanf("%d",&f);
            if (f==2)
                g=0;
        }
        while(g);
        *n=*n+1;
    }





    void REMOVE(contact*c,int*n)
    {
        char first[100];
        char last[100];
        printf("Enter the first name for the contact to be deleted:\n");
        scanf("%s",first);
        printf("Enter the last name for the contact to be deleted:\n");
        scanf("%s",last);
        int i,j,found=0;

        for(i=0; i<*n; i++)
        {
            if(strcasecmp(c[i].last_name,last)==0 && strcasecmp(c[i].first_name,first)==0)
            {
                found=1;
                for(j=i; j<*n-1; j++)
                {
                    c[j]=c[j+1];
                }
                (*n)--;
                i--;
            }
        }

        if(!found)
            printf("%s %s is not found in the Telephone Book\n",first,last);
        else
            printf("ALL Records for the contact has been deleted successfully.\n");
    }



    void save(contact*c,int n,char file_name[])
    {
        system("cls");
        int i;

        FILE*f=fopen(file_name,"w");
        for(i=0; i<n; i++)
        {
            fprintf(f,"%s %s,%d %d %d,%s,%s,%s\n",c[i].first_name,c[i].last_name,c[i].DOB.day,c[i].DOB.month,c[i].DOB.year,c[i].address,c[i].phone_number,c[i].email);
        }
        fclose(f);
    }


    void print_and_sort(contact*c, int n)
    {

        printf("Sort by lastname (choose 1) or date of birth (choose 2)?\n");
        int y;
        scanf("%d",&y);
        int i;
        contact temp;
        int sorted=0;
        if(y==1)
            while(!sorted)
            {
                sorted=1;
                for(i=0; i<n-1; i++)
                {
                    if(strcasecmp(c[i].last_name,c[i+1].last_name)>0)
                    {
                        temp=c[i];
                        c[i]=c[i+1];
                        c[i+1]=temp;
                        sorted=0;
                    }

                }
            }

        if(y==2)
        {
            while(!sorted)
            {
                sorted=1;
                for(i=0; i<n-1; i++)
                {

                    if(c[i].DOB.year<c[i+1].DOB.year)
                    {

                        temp=c[i];
                        c[i]=c[i+1];
                        c[i+1]=temp;
                        sorted=0;

                    }
                    else if(c[i].DOB.year==c[i+1].DOB.year)
                    {
                        if(c[i].DOB.month<c[i+1].DOB.month)
                        {

                            temp=c[i];
                            c[i]=c[i+1];
                            c[i+1]=temp;
                            sorted=0;

                        }
                        else if(c[i].DOB.month==c[i+1].DOB.month)
                        {
                            if(c[i].DOB.day<c[i+1].DOB.day)
                            {

                                temp=c[i];
                                c[i]=c[i+1];
                                c[i+1]=temp;
                                sorted=0;

                            }
                        }
                    }

                }
            }
        }


        int x;
        printf("ALL CONTACTS\n");
        for(x=0; x<n; x++)
        {
            printf("%s ",c[x].first_name);
            printf("%s ",c[x].last_name);
            printf("%d %d %d ",c[x].DOB.day,c[x].DOB.month,c[x].DOB.year);
            printf("%s ",c[x].address);
            printf("%s ",c[x].phone_number);
            printf("%s\n",c[x].email);
        }

    }
    void Quit(contact*c,int n,char file_name[])
    {
        int x;
        printf("would you like to save changes?\n1.yes 2.no");

        scanf("%d",&x);
        if(x==1)
        {
            save(c,n,file_name);
        }

    }




    int main()
    {
        int  n=0;
        int x;
        char file_name[100];
        printf("enter file name\n");
        scanf("%s",file_name);
        contact*c=load(file_name,&n);




        while(1)
        {
            printf("\n1.search\n2.Add\n3.Delete\n4.Modify\n5.Print and sort\n6.save\n7.Quit\n");
            scanf("%d",&x);
            if(x==1)
                search (c,n);
            if(x==4)
                modify(c,n);
            if(x==2)
            {
                add(c,&n);
                printf("\tfirst name :-%s \n",c[n-1].first_name);
                printf("\tlast name :-%s \n",c[n-1].last_name);
                printf("\tdate of birth :-%d-%d-%d \n",c[n-1].DOB.day,c[n-1].DOB.month,c[n-1].DOB.year);
                printf("\taddress :-%s\n",c[n-1].address);
                printf("\tphone number :-%s\n",c[n-1].phone_number);
                printf("\tEmail :-%s\n",c[n-1].email);

            }
            if(x==3)
                REMOVE(c,&n);
            if(x==6)
                save(c,n,file_name);
            if(x==5)
                print_and_sort(c,n);
            if(x==7)
            {
                Quit(c,n,file_name);
                break;
            }

        }

        return 0;


    }
