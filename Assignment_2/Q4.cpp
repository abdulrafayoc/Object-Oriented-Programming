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

int main() {
    SavingAccount* savers[100];
    int accountsOpen = 0;
    char* accountNum = new char[5];

    accountNum[0] = 'S';
    accountNum[1] = 'A';
    accountNum[2] = '0';
    accountNum[3] = '0';
    OpenCustomerAccount(savers, accountsOpen, accountNum, 1000);

    modifyInterestRate(savers[0], 0.05);
    modifyInterestRate(savers[1], 0.05);
    
    cout << calculateMonthlyInterest(savers[0]) << endl;
    cout << calculateMonthlyInterest(savers[1]) << endl;

    cout << searchCustomer(savers, accountsOpen, accountNum) << endl;

    cout << UpdateAccountBalance(savers, accountsOpen, accountNum, 1500) << endl;

}