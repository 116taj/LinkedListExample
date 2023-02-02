#include "defs.h"

/*
  Function: initAcctList
   Purpose: initializes the account linked list (null since list is empty)
    in-out: linked list to initialize 
*/
void initAcctList(AcctListType *list){
 list->head = NULL;
 list->tail = NULL;
}

/*
  Function: initAccount
   Purpose: sets all the fields in the CustomerType to proper values and allocates memory
        in: account number to store
        in: the type of bank account 
        in: the customer that owns of the account
        in: the balance of the account
    in-out: the account in which all of the other parameters will be stored in
*/
void initAccount(int n, AcctEnumType at, CustomerType *c, float b, AccountType **acct){
  *acct = malloc(sizeof(CustomerType));
  (*acct)->acctNum = n;
  (*acct)->acctType = at;
  (*acct)->cust = c;
  (*acct)->balance = b;
}

/*
  Function: addAccount
   Purpose: adds a node to the end of the list containing account data
    in-out: the list to add a node to
        in: the data the new node will contain
*/
void addAccount(AcctListType *list, AccountType *acct){
  NodeType *currNode = list->head;
  NodeType *prevNode = NULL;
  NodeType *newNode = malloc(sizeof(NodeType));
  newNode->data = acct;
  newNode->next = NULL;
  
  while(currNode != NULL){
    prevNode = currNode;
    currNode = currNode->next; 
  }
  
  if (prevNode == NULL)
    list->head = newNode;
  else 
    prevNode->next = newNode;  
  newNode->next = currNode;  
  list->tail = newNode; 
}

/*
  Function: addAccountByBalance
   Purpose: adds a node such the list is sorted by balance. done by finding a node which has a smaller balance and inserting the node before that one
    in-out: the list to add a node to
        in: the data the new node will contain
*/
void addAccountByBalance(AcctListType *list, AccountType *acct){
  NodeType *currNode = list->head;
  NodeType *prevNode = NULL;
  NodeType *newNode = malloc(sizeof(NodeType));
  newNode->data = acct;
  newNode->next = NULL;
  while(currNode != NULL){
    if(currNode->data->balance < newNode->data->balance){
      break;
    }
    prevNode = currNode;
    currNode = currNode->next; 
  }
  if (prevNode == NULL)
    list->head = newNode;
  else 
    prevNode->next = newNode;  
  newNode->next = currNode;  
  if (newNode->next == NULL)
    list->tail = newNode;
}

/*
  Function: printAccount
   Purpose: prints out the account information after doing some string handling for accountType and name
        in: the account to print out
*/
void printAccount(AccountType *acct){
  char acctType[MAX_STR];
  char name[MAX_STR];
  if (acct->acctType == CHEQUING)
    strcpy(acctType,"Chequing");
  else if (acct->acctType == SAVINGS)
    strcpy(acctType,"Savings");
  else if (acct->acctType == OTHER)
    strcpy(acctType,"Other");
  else
    strcpy(acctType,"Unknown");
  if (acct->cust == NULL)
    strcpy(name,"Unknown");
  else
    strcpy(name,acct->cust->name);            
  printf("Acct Num: %10d Type: %10s Owner: %10s Balance: $ %10.2f \n",acct->acctNum, acctType, name, acct->balance);
}

/*
  Function: printAccounts
   Purpose: prints out a list of accounts by traversing the list and using a helper function
        in: the list that contains all the accounts to print out
        in: whether to print the head and tail again or not
*/
void printAccounts(AcctListType *list, int ends){
  if (list->head == NULL){
    printf("NO ACCOUNTS \n");
    return;
  }
  for (NodeType *currNode = list->head; currNode != NULL; currNode = currNode->next) {
    printAccount(currNode->data);
  }
  if (ends == C_TRUE){
    printf("--HEAD: ");
    printAccount(list->head->data);
    printf("--TAIL: ");
    printAccount(list->tail->data);
  }
}
/*
  Function: cleanupAcctData
   Purpose: deallocates the data of the list
    in-out: the list containing the data to deallocate
*/
void cleanupAcctData(AcctListType *list){
  NodeType *currNode = list->head;
  NodeType *nextNode;
  
  while(currNode != NULL){
    nextNode = currNode->next;
    free(currNode->data);
    currNode = nextNode; 
  }
}

/*
  Function: cleanupAcctList
   Purpose: deallocates the nodes of a list only
        in: the list containing the nodes to deallocate
*/
void cleanupAcctList(AcctListType *list){
  NodeType *currNode = list->head;
  NodeType *nextNode;
  while(currNode != NULL){
    nextNode = currNode->next;
    free(currNode);
    currNode = nextNode; 
  }
}
/*
  Function: printByBalance
   Purpose: prints a list of accounts from highest balance to lowest by creating a duplicate list that will be sorted by balance
        in: the original list to copy
        in: whether to print out the tail and head or not
*/
void printByBalance(AcctListType *orgList, int ends){
  AcctListType *balList;
  balList = malloc(sizeof(AcctListType));
  initAcctList(balList);
  for (NodeType *currNode = orgList->head; currNode != NULL; currNode = currNode->next) {
    addAccountByBalance(balList,currNode->data);
  }
  printAccounts(balList, ends);
  cleanupAcctList(balList);
  free(balList);
}
