#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_TRUE     1
#define C_FALSE    0

#define MAX_ARR  128
#define MAX_STR   32

#define NEXT_CUST_ID    4001
#define NEXT_ACCT_ID  700210

typedef enum { CHEQUING, SAVINGS, OTHER } AcctEnumType;

struct AcctList;

typedef struct {
  int  id;
  char name[MAX_STR];
  struct AcctList *accounts;
} CustomerType;

typedef struct {
  int          acctNum;
  AcctEnumType acctType;
  CustomerType *cust;
  float        balance;
} AccountType;

typedef struct CustArray{
  CustomerType *elements[MAX_ARR];
  int size;
} CustArrayType;

typedef struct Node {
  AccountType *data;
  struct Node *next;
} NodeType;

typedef struct AcctList {
  struct Node *head;
  struct Node *tail;
} AcctListType;

typedef struct {
  struct AcctList accounts;
  struct CustArray customers;
} BankType;

void printMenu(int*);
void initAcctList(AcctListType*);
void initAccount(int,AcctEnumType,CustomerType*,float,AccountType**);
void addAccount(AcctListType*,AccountType*);
void addAccountByBalance(AcctListType*,AccountType*);
void printAccount(AccountType*);
void printAccounts(AcctListType*, int);
void cleanupAcctData(AcctListType*);
void cleanupAcctList(AcctListType*);
void printByBalance(AcctListType*,int);
void initCustArray(CustArrayType*);
void initCustomer(int,char*,CustomerType**);
void addCustomer(CustArrayType*,CustomerType*);
void printCustomers(CustArrayType*);
void cleanupCustArray(CustArrayType*);
void initBank(BankType*);
void cleanupBank(BankType*);
void loadBankData(BankType*);

