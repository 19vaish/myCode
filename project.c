/* WAP to perform the following operations based on user choice,
1. Add Account
2. Display
3. Search [1. By account number, 2. By contact]
4. Modify [1. Address, 2.contact,3. PIN]
5. Delete
6. Transaction[1. withdraw,2. Deposit]
7. Exit
*/

#include<stdio.h>
#include "account.h"

int main()
{
  int choice;
  do
  {
    printf("\n1. Add Account\n2. Display\n3. Search\n");
    printf("4.Modify\n5. Delete\n6. transaction\n7. Exit");
    printf("\n\t Enter your choice :");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add_account();
        break;

    case 2:
        display_accounts();
        break;

    case 3:
        search_account();
        break;

    case 4:
        modify_account();
        break;

    case 5:
        delete_account();
        break;

    case 6:
        transaction();
        break;

    case 7:
        exit(0);

    default:
        printf("\n Invalid choice");

    }
  }
  while(choice<8);
}

