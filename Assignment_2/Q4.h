#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>

using namespace std;

struct SavingAccount
{
    char* name;
    float annualInterstRate;
    double savingBalance;
    char* accountNum;
};

void OpenCustomerAccount(SavingAccount* savers[], int accountsOpen, char* NameVal, double balance) {
    savers[accountsOpen] = new SavingAccount{ NameVal, (float)balance };
    stringstream ss;
    ss << setw(2) << setfill('0') << accountsOpen;
    savers[accountsOpen]->accountNum = new char[ss.str().length() + 1];
    accountsOpen++;
}
float calculateMonthlyInterest(SavingAccount* saver) {
    float monthlyInterest = (saver->annualInterstRate / 12) * saver->savingBalance;
    return monthlyInterest;
}
void modifyInterestRate(SavingAccount* saver, float newValue) {
    saver->annualInterstRate = newValue;
}
int searchCustomer(SavingAccount* savers[], int accountsOpen, char* accountNum) {
    for (int i = 0; i < accountsOpen; i++) {
        if (savers[i]->accountNum == accountNum) {
            return i;
        }
    }
    return -1;
}
bool UpdateAccountBalance(SavingAccount* savers[], int accountsOpen, char* accountNumVal, double balanceVal) {
    int index = searchCustomer(savers, accountsOpen, accountNumVal);
    if (index == -1) {
        return false;
    }
    savers[index]->savingBalance = balanceVal;
    return true;
}

