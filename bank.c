#include "defs.h"

/*
  Function: loadBankData
   Purpose: initializes bank data for testing purposes
    in-out: the bank that will contain this data
*/
void loadBankData(BankType *bank)
{
  AccountType  *acc;
  CustomerType *cust;
  int currCustId = NEXT_CUST_ID;
  int currAcctId = NEXT_ACCT_ID;

  initCustomer(currCustId++, "Kara", &cust);
  addCustomer(&bank->customers, cust);
  initAccount(currAcctId++, SAVINGS, cust, 10.0f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, SAVINGS, cust, 50.0f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, CHEQUING, cust, 280.42f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);

  initCustomer(currCustId++, "Lee", &cust);
  addCustomer(&bank->customers, cust);
  initAccount(currAcctId++, SAVINGS, cust, 4598.0f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, CHEQUING, cust, 2344.98f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);

  initCustomer(currCustId++, "Laura", &cust);
  addCustomer(&bank->customers, cust);
  initAccount(currAcctId++, SAVINGS, cust, 8771.14f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, CHEQUING, cust, 6832.55f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, CHEQUING, cust, 459.0f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);

  initCustomer(currCustId++, "William", &cust);
  addCustomer(&bank->customers, cust);
  initAccount(currAcctId++, CHEQUING, cust, 3455.76f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);

  initCustomer(currCustId++, "Sharon", &cust);
  addCustomer(&bank->customers, cust);

  initCustomer(currCustId++, "Karl", &cust);
  addCustomer(&bank->customers, cust);
  initAccount(currAcctId++, SAVINGS, cust, 1256.80f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, CHEQUING, cust, 3207.82f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);

  initCustomer(currCustId++, "Gaius", &cust);
  addCustomer(&bank->customers, cust);
  initAccount(currAcctId++, CHEQUING, cust, 10988.44f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, CHEQUING, cust, 45.87f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);

  initCustomer(currCustId++, "Six", &cust);
  addCustomer(&bank->customers, cust);

  initCustomer(currCustId++, "Saul", &cust);
  addCustomer(&bank->customers, cust);

  initCustomer(currCustId++, "Ellen", &cust);
  addCustomer(&bank->customers, cust);

  initCustomer(currCustId++, "Sam", &cust);
  addCustomer(&bank->customers, cust);

  initCustomer(currCustId++, "Dee", &cust);
  addCustomer(&bank->customers, cust);
  initAccount(currAcctId++, SAVINGS, cust, 200.0f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);
  initAccount(currAcctId++, SAVINGS, cust, 1498.6f, &acc);
  addAccount(&bank->accounts, acc);
  addAccount(cust->accounts, acc);

  initAccount(currAcctId++, CHEQUING, NULL, 150.0f, &acc);
  addAccount(&bank->accounts, acc);

  initAccount(currAcctId++, OTHER, NULL, 580.0f, &acc);
  addAccount(&bank->accounts, acc);
}

/*
  Function: initBank
   Purpose: initializes the bank by initializing its fields
    in-out: the bank that will be initialized
*/

void initBank(BankType *b){
 initAcctList(&b->accounts);
 initCustArray(&b->customers);
}

/*
  Function: cleanupBank
   Purpose: deallocates all memory associated with the bank including customers, account lists, and account data
        in: the bank to deallocate
*/
void cleanupBank(BankType *b){
  cleanupCustArray(&b->customers);
  cleanupAcctData(&b->accounts);
  cleanupAcctList(&b->accounts);
  free(b);
}
