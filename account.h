struct Account
{
    char name[20],add[30],cont[10];
    int acno,bal;
};
void read_account(struct Account *A)
{
    printf("\n enter acno,name,address and contact :");
    scanf("%d%s%s%s",&A->acno,A->name,A->add,A->cont);
    A->bal=500;
}
void add_account()
{
    struct Account A;
    FILE *fp1;
    fp1=fopen("account2.txt","a");
    read_account(&A);
    fwrite((char*)&A,sizeof(struct Account),1,fp1);
    fclose(fp1);
}
void display_account(struct Account A)
{
    printf("\n%d\t%s\t%s\t\t%s\t%d",A.acno,A.name,A.add,A.cont,A.bal);
}
void display_accounts()
{
    struct Account A;
    FILE *fp1;
    fp1=fopen("account2.txt","r");
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        display_account(A);
    }
}
void search_account()
{
    struct Account A;
    FILE *fp1;
    int an,flag=0;
    fp1=fopen("account2.txt","r");
    printf("\n enter account number to search:");
    scanf("%d",&an);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(an==A.acno)
        {
            display_account(A);
            flag=1;
            break;
        }
    }
    fclose(fp1);
    if(flag==0)
       printf("\n record not found");
}
void modify_account()
{
    struct Account A;
    FILE *fp1,*fp2;
    int an,flag=0,choice;
    fp1=fopen("account2.txt","r");
    fp2=fopen("temp.txt","w");
    printf("\n enter account number to modify:");
    scanf("%d",&an);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
           if(feof(fp1))
            break;
         if(an==A.acno)
         {
             display_account(A);
             flag=1;
             printf("\n 1. Address\n2.Contact\n3.PIN\n enter your choice:");
             scanf("%d",&choice);
             if(choice==1)
             {
                 printf("\n Enter new address :");
                 scanf("%s",A.add);
             }
             else if(choice==2)
             {
                 printf("\n enter new contact:");
                 scanf("%s",A.cont);
             }
             else if(choice==3)
             {

             }
             fwrite((char *)&A,sizeof(struct Account),1,fp2);
         }
         else
            fwrite((char *)&A,sizeof(struct Account),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(flag==0)
        printf("\n Record not found");
    else
    {
        remove("account2.txt");
        rename("temp.txt","account2.txt");
        printf("\n Record Modified");
    }
}
void delete_account()
{
    struct Account A;
    FILE *fp1,*fp2;
    int an,flag=0,choice;
    fp1=fopen("account2.txt","r");
    fp2=fopen("temp.txt","w");
    printf("\n enter account number to delete:");
    scanf("%d",&an);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        if(an==A.acno)
        {
            display_account(A);
            flag=1;
        }
        else
            fwrite((char *)&A,sizeof(struct Account),1,fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if(flag==0)
        printf("\n record not found");
    else
    {
        remove("account2.txt");
        rename("temp.txt","account2.txt");
        printf("\n record not found");
    }
}
void transaction()
{
    struct Account A;
    FILE *fp1,*fp2;
    int an,flag=0,choice,amt;
    fp1=fopen("account2.txt","r");
    fp2=fopen("temp.txt","w");
    printf("\n enter account number for transaction:");
    scanf("%d",&an);
    while(!feof(fp1))
    {
        fread((char *)&A,sizeof(struct Account),1,fp1);
        if(feof(fp1))
            break;
        if(an==A.acno){
            display_account(A);
            flag=1;
            printf("\n1. Withdraw\n2. Deposit\n enter your choice:");
            scanf("%d",&choice);
            if(choice==1)
            {
                printf("\n enter amount to withdraw:");
                scanf("%d",&amt);
                if((A.bal-amt)>=500)
                {
                    A.bal-=amt;
                    printf("\n Withdrawl success");
                }
                else
                {
                    printf("\n insufficient balance");
                }
            }
            else
            {
                printf("\n insufficient balance");
            }
        }
        else if(choice==2)
        {
            printf("\n enter deposit amount:");
            scanf("%d",&amt);
            A.bal+=amt;
            printf("\n deposit success");
        }
        fwrite((char *)&A,sizeof(struct Account),1,fp2);
    }
fclose(fp1);
fclose(fp2);
if(flag==0)
    printf("\record not found");
else
{
    remove("account2.txt");
    rename("temp.txt","account2.txt");
}
}
