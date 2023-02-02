#include "defs.h"
/*
  Function: initCustArray
   Purpose: sets the array size to 0
    in-out: the array to set 
*/
void initCustArray(CustArrayType *arr){
  arr->size = 0;
}

/*
  Function: initCustomer
   Purpose: initializes a customer by setting all the field values including an account list and allocating memory
        in: the customer id
        in: the name of the customer
    in-out: the customer that stores the fields
*/
void initCustomer(int id, char *n, CustomerType **cust){
  *cust = malloc(sizeof(CustomerType));
  (*cust)->id = id;
  strcpy((*cust)->name,n);
  (*cust)->accounts = malloc(sizeof(AcctListType));
  initAcctList((*cust)->accounts);
}
/*
  Function: addCustomer
   Purpose: adds a customer to the customer array and updates the size
    in-out: the customer array
        in: the customer
*/
void addCustomer(CustArrayType *arr, CustomerType *c){
 arr->elements[arr->size] = c;
 arr->size++;
}

/*
  Function: printCustomers
   Purpose: prints out all of the customers information one by one, including all of their accounts
        in: the customer array
*/
void printCustomers(CustArrayType *arr){
  for (int i = 0; i < arr->size; i++){
    printf("%-10d %10s \n",arr->elements[i]->id,arr->elements[i]->name);
    printAccounts(arr->elements[i]->accounts, C_FALSE);
    printf("\n");
  }
}

/*
  Function: cleanupCustArray
   Purpose: deallocates the customers and their accounts (nodes only)
    in-out: the customer array
*/
void cleanupCustArray(CustArrayType *arr){
  for (int i = 0; i < arr->size; i++){
    cleanupAcctList(arr->elements[i]->accounts);
    free(arr->elements[i]->accounts);
    free(arr->elements[i]);
  }
  arr->size = 0;
}
