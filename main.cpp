#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
struct InfoPersonal
{
    char * IDPersonal;
    char * name;
    char * dateOfBirth;
};
struct AccountInfo
{
    char* numberAccount;
    char* pinCode;
    int balance;
};

std::string gen_random(const int len)
{
    static const char alphanum[] = "0123456789";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}

class PersonalAccount
{
private:
    struct InfoPersonal infoPersonal;
    struct AccountInfo accountInfo;

public:
    PersonalAccount()
    {
        infoPersonal.name = new char[100];
        infoPersonal.IDPersonal = new char[100];
        infoPersonal.dateOfBirth = new char[100];
        accountInfo.numberAccount = new char[100];
        accountInfo.pinCode = new char[100];
        accountInfo.balance = 0;
    }
    // PersonalAccount(struct InfoPersonal _infoPersonal, struct AccountInfo _accountInfo)
    // {
    //     infoPersonal.name = _infoPersonal.name;
    //     accountInfo.balance = _accountInfo.balance;
    // }
    struct InfoPersonal getInfoPersonal()
    {
        return infoPersonal;
    }
    struct AccountInfo getAccountInfo()
    {
        return accountInfo;
    }
    char * getName(){
        return infoPersonal.name;
    }
    void setName(char* _name){
        infoPersonal.name = _name;
    }
    char *getIDPersonal(){
        return infoPersonal.IDPersonal;
    }
    void setIDPersonal(char *_IDPersonal){
        infoPersonal.IDPersonal = _IDPersonal;
    }
    char *getDOB(){
        return infoPersonal.dateOfBirth;
    }
    void setDOB(char *_DOB){
        infoPersonal.dateOfBirth = _DOB;
    }
    char * getPinCode(){
        return accountInfo.pinCode;
    }
    void setPinCode(char *_pinCode){
        accountInfo.pinCode = _pinCode;
    }
    char * getNumAccount(){
        return accountInfo.numberAccount;
    }
    void setNumAccount(char *_numAccount){
        accountInfo.numberAccount = _numAccount;
    }
    int getBalance()
    {
        return accountInfo.balance;
    }
    void setBalance(int _balance){
        accountInfo.balance = _balance;
    }
};
class BankManagement
{
public:
    BankManagement()
    {
    }
    ~BankManagement() = default;
    static void CreateAccountBank(PersonalAccount &personalAccount)
    {
        cin.ignore();
        cout << "Type Name:";
        fgets(personalAccount.getInfoPersonal().name, 20, stdin);
        cout << "Type ID Personal:";
        fgets(personalAccount.getInfoPersonal().IDPersonal, 20, stdin);
        cout << "Type Date Of Birth:";
        fgets(personalAccount.getInfoPersonal().dateOfBirth, 20, stdin);
        personalAccount.setBalance(0);
        personalAccount.setPinCode((char *)(gen_random(6).c_str()));
        personalAccount.setNumAccount((char *)(gen_random(12).c_str()));
        userInfor.push_back(personalAccount);
        // for(int i = 0; i < userInfor.size(); i++){
        //     cout << userInfor[i].getName() << " " << userInfor[i].getIDPersonal() << " " << userInfor[i].getDOB() << " " << userInfor[i].getNumAccount() << " " << userInfor[i].getPinCode() << " " << userInfor[i].getBalance()<< endl;
        // }
    }
    static void Deposite()
    {
        cout << "=============Welcome to my service=============" << endl;
        cout << "Please to type the number you want to deposite to your account: ";
        int numDeposite;
        cin >> numDeposite;
        cin.ignore();
        char *numAccount = new char[100];
        cout << "Please type the number account you want to deposite: ";
        fgets(numAccount, 3, stdin);
        for(int i = 0; i < getVector().size(); i++){
            if (strcmp(numAccount, getVector()[i].getIDPersonal()) == 0){
                cout << "in if" << endl;
                getVector()[i].setBalance(getVector()[i].getBalance() + numDeposite);
            }
        }
        // for(int i = 0; i < getVector().size(); i++){
        //     cout << getVector()[i].getBalance() << " " << endl;
        // }

    }
    void Withdraw()
    {
    }
    void changePINCode()
    {
    }
    void Transfer()
    {
    }
    static std::vector<PersonalAccount> getVector() {
        return userInfor;
    }

private:
    static std::vector<PersonalAccount> userInfor;
};
std::vector<PersonalAccount> BankManagement::userInfor(0);
int main()
{
    cout << "===========Welcome to my bank===========" << endl;
    while (1)
    {
        /* code */
        cout << endl;
        cout << "\t============Menu===========" << endl;
        cout << "\t\033[33m1. \033[0mCreate new account" << endl;
        cout << "\t\033[33m2. \033[0mDeposite" << endl;
        cout << "\t\033[33m3. \033[0mWithdraw" << endl;
        cout << "\t\033[33m4. \033[0mChange PIN code" << endl;
        cout << "\t\033[33m5. \033[0mTransfer" << endl;
        cout << "\t\033[33m6. \033[0mTransfer cash to account" << endl;
        cout << "\t\033[33m7. \033[0mExit" << endl;
        cout << "\t============================" << endl;
        int choice;
        cout << endl;
        cout << "Please type your choice:";
        cin >> choice;
        if (choice == 0)
        {
        }
        else if (choice == 1)
        {
            cout << "Thank you for believe our banking. We need some your personal information. Please type carefully!!!" << endl;
            PersonalAccount a;
            BankManagement::CreateAccountBank(a);
        }
        else if (choice == 2)
        {
            BankManagement::Deposite();
        }
        else if (choice == 3)
        {
        }
        else if (choice == 4)
        {
        }
        else if (choice == 5)
        {
        }
        else if (choice == 6)
        {
        }
        else if (choice == 7)
        {
        }
        else if (choice == 8)
        {
        }
    }
    return 0;
}