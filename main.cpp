#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <chrono>
#include <thread>
using namespace std;
struct InfoPersonal
{
    string IDPersonal;
    string name;
    string dateOfBirth;
};
struct AccountInfo
{
    string numberAccount;
    string pinCode;
    int balance;
};
void Loading(string s)
{
    cout << s;
    cout.flush();
    for (int j = 0; j < 20; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << ".";
            cout.flush();
            // Sử dụng std::this_thread::sleep_for để thay thế _sleep
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        cout << "\b\b\b   \b\b\b";
    }
    cout << " successful..." << endl;
}
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
class HandleJson
{
};

class PersonalAccount
{
private:
    struct InfoPersonal infoPersonal;
    struct AccountInfo accountInfo;

public:
    PersonalAccount()
    {
        accountInfo.balance = 0;
    }
    // struct InfoPersonal getInfoPersonal()
    // {
    //     return infoPersonal;
    // }
    // struct AccountInfo getAccountInfo()
    // {
    //     return accountInfo;
    // }
    string getName()
    {
        return infoPersonal.name;
    }
    void setName(string _name)
    {
        infoPersonal.name = _name;
    }
    string getIDPersonal()
    {
        return infoPersonal.IDPersonal;
    }
    void setIDPersonal(string _IDPersonal)
    {
        infoPersonal.IDPersonal = _IDPersonal;
    }
    string getDOB()
    {
        return infoPersonal.dateOfBirth;
    }
    void setDOB(string _DOB)
    {
        infoPersonal.dateOfBirth = _DOB;
    }
    string getPinCode()
    {
        return accountInfo.pinCode;
    }
    void setPinCode(string _pinCode)
    {
        accountInfo.pinCode = _pinCode;
    }
    string getNumAccount()
    {
        return accountInfo.numberAccount;
    }
    void setNumAccount(string _numAccount)
    {
        accountInfo.numberAccount = _numAccount;
    }
    int getBalance()
    {
        return accountInfo.balance;
    }
    void setBalance(int _balance)
    {
        accountInfo.balance = _balance;
    }
};
class BankManagement
{
private:
    static std::vector<PersonalAccount> userInfor;

public:
    BankManagement()
    {
    }
    ~BankManagement() = default;
    static void CreateAccountBank(PersonalAccount &personalAccount)
    {
        cin.ignore();
        string name;
        cout << "Type Name:";
        getline(cin, name);
        personalAccount.setName(name);
        string IDPersonal;
        cout << "Type ID Personal:";
        getline(cin, IDPersonal);
        personalAccount.setIDPersonal(IDPersonal);
        string dob;
        cout << "Type Date Of Birth:";
        getline(cin, dob);
        personalAccount.setDOB(dob);
        // personalAccount.setBalance(0);
        personalAccount.setPinCode((gen_random(6)));
        personalAccount.setNumAccount((gen_random(12)));
        Loading("Creating account");
        userInfor.push_back(personalAccount);
        cout << personalAccount.getNumAccount() << endl;
        ;
    }
    static void Deposite(std::vector<PersonalAccount> &listAccount)
    {
        cout << "=============Welcome to my service=============" << endl;
        cout << "Please to type the number money you want to deposite to your account: ";
        int numDeposite;
        cin >> numDeposite;
        cin.ignore();
        string numAccount;
        cout << "Please type the your number account: ";
        getline(cin, numAccount);
        for (int i = 0; i < listAccount.size(); i++)
        {
            cout << listAccount[i].getNumAccount() << " ";
            if (numAccount == listAccount[i].getNumAccount())
            {
                int nowMoney = listAccount[i].getBalance();
                nowMoney += numDeposite;
                listAccount[i].setBalance(nowMoney);
                break;
            }
        }
        setVector(listAccount);
    }
    static void Withdraw(std::vector<PersonalAccount> &listAccount)
    {
        cin.ignore();
        string numAccount;
        cout << "Please type your number account: ";
        getline(cin, numAccount);
        for (int i = 0; i < listAccount.size(); i++)
        {
            if (numAccount == listAccount[i].getNumAccount())
            {
                cout << "Please type the money you want to withdraw: ";
                int numWithDraw;
                cin >> numWithDraw;
                while (numWithDraw > listAccount[i].getBalance())
                {
                    cout << "The balance is not enough. Please type money you want to withdraw again: ";
                    cin >> numWithDraw;
                }
                int moneyRemain = listAccount[i].getBalance();
                moneyRemain -= numWithDraw;
                listAccount[i].setBalance(moneyRemain);
                break;
            }
        }
        setVector(listAccount);
        Loading("Withdrawing");
    }
    static void ChangePINCode(std::vector<PersonalAccount> &listAccount)
    {
        cin.ignore();
        string numAccount;
        cout << "Please type your number account: ";
        getline(cin, numAccount);
        for (int i = 0; i < listAccount.size(); i++)
        {
            if (numAccount == listAccount[i].getNumAccount())
            {
                cout << "Please type the pincode you want to change: ";
                string pinCode;
                getline(cin, pinCode);
                listAccount[i].setPinCode(pinCode);
                break;
            }
        }
        setVector(listAccount);
        Loading("Changing");
    }
    static void Transfer(std::vector<PersonalAccount> &listAccount)
    {
        cin.ignore();
        string numAccount;
        cout << "Please type your number account: ";
        getline(cin, numAccount);
        for (int i = 0; i < listAccount.size(); i++)
        {
            if (numAccount == listAccount[i].getNumAccount())
            {
                cout << "Please type the account you want to transfer: ";
                string numAccountTransfer;
                getline(cin, numAccountTransfer);
                for (int j = 0; j < listAccount.size(); j++)
                {
                    if (numAccountTransfer == listAccount[j].getNumAccount())
                    {
                        cout << "Please type the money you want transfer: ";
                        int moneyTransfer;
                        cin >> moneyTransfer;
                        while (moneyTransfer > listAccount[i].getBalance())
                        {
                            cout << "Sorry! Your balance is not enough to transfer!!!" << endl;
                        }
                        int newMoney = listAccount[j].getBalance();
                        newMoney += moneyTransfer;
                        listAccount[j].setBalance(newMoney);
                        int oldMoney = listAccount[i].getBalance();
                        oldMoney -= moneyTransfer;
                        listAccount[i].setBalance(oldMoney);
                        break;
                    }
                }
                break;
            }
        }
        setVector(listAccount);
    }
    static std::vector<PersonalAccount> getVector()
    {
        return userInfor;
    }
    static void setVector(std::vector<PersonalAccount> _vector)
    {
        userInfor = _vector;
    }
};
std::vector<PersonalAccount> BankManagement::userInfor = {};
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
        // cout << "\t\033[33m6. \033[0mTransfer cash to account" << endl;
        cout << "\t\033[33m6. \033[0mExit" << endl;
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
            cout << "Do you want to process another function Y/N ?" << endl;
            char kitu;
            cin >> kitu;
            if (kitu == 'Y')
            {
            }
            else
            {
                cout << "=============Thank for using my service=============" << endl;
                exit(0);
            }
        }
        else if (choice == 2)
        {
            vector<PersonalAccount> vector = BankManagement::getVector();
            BankManagement::Deposite(vector);
            cout << "Do you want to process another function Y/N ?" << endl;
            char kitu;
            cin >> kitu;
            if (kitu == 'Y')
            {
            }
            else
            {
                cout << "=============Thank for using my service=============" << endl;
                exit(0);
            }
        }
        else if (choice == 3)
        {
            vector<PersonalAccount> vector = BankManagement::getVector();
            BankManagement::Withdraw(vector);
            cout << "Do you want to process another function Y/N ?" << endl;
            char kitu;
            cin >> kitu;
            if (kitu == 'Y')
            {
            }
            else
            {
                cout << "=============Thank for using my service=============" << endl;
                exit(0);
            }
        }
        else if (choice == 4)
        {
            vector<PersonalAccount> vector = BankManagement::getVector();
            BankManagement::ChangePINCode(vector);
            cout << "Do you want to process another function Y/N ?" << endl;
            char kitu;
            cin >> kitu;
            if (kitu == 'Y')
            {
            }
            else
            {
                cout << "=============Thank for using my service=============" << endl;
                exit(0);
            }
        }
        else if (choice == 5)
        {
            vector<PersonalAccount> vector = BankManagement::getVector();
            BankManagement::Transfer(vector);
            cout << "Do you want to process another function Y/N ?" << endl;
            char kitu;
            cin >> kitu;
            if (kitu == 'Y')
            {
            }
            else
            {
                cout << "=============Thank for using my service=============" << endl;
                exit(0);
            }
        }
        // else if (choice == 6)
        // {
        //     // for (int i = 0; i < BankManagement::getVector().size(); i++)
        //     // {
        //     //     cout << BankManagement::getVector()[i].getBalance() << " " << endl;
        //     // }
        // }
        else
        {
        }
    }
    return 0;
}