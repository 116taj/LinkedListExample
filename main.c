#include "defs.h"

int main()
{
  BankType *b;
  b = malloc(sizeof(BankType));
  initBank(b);
  loadBankData(b);
  int choice = 0;
  int *cPtr = &choice;
  while(1){
    printMenu(cPtr);
    if (*cPtr == 0)
      break;
    if (*cPtr == 1)
      printCustomers(&b->customers);
    else if (*cPtr == 2)  
      printAccounts(&b->accounts,C_TRUE);
    else  
      printByBalance(&b->accounts,C_TRUE);
  }
  cleanupBank(b);
  return(0);
}
/*
  Function: printMenu
   Purpose: prints out the menu so the user may choose an option then stores the option in a pointer
       out: the option the user selected
*/
void printMenu(int *choice)
{
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Print customers\n");
  printf("  (2) Print accounts\n");
  printf("  (3) Print accounts by balance\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

