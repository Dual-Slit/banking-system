#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#define lli long long int

using namespace std;

string AccNo, key; // phone number treat as account number;
lli amount, addfund;
string a = "Accoount No", a1;
string b = "Balance", b1;
string T, t1,d1;
char Date[25];

time_t currTime;
tm *currTm;


void checkBal(string userID, string password, string phone_num);
void widthdrowl(string userID, string password, string phone_num);
void deposit(string userID, string password, string phone_num);
void showPassbook(string userID, string password, string phone_num);
bool CheckPassword(string key, string password);
lli Int(string s);

void account(string userID, string password, string phone_num, bool New = true)
{
    system("clear");
    cout << "\n\tWelcome " << userID << endl;
    ofstream file(phone_num + ".txt", ios::app);
    if (New)
    {
        time(&currTime);
        currTm = localtime(&currTime);
        strftime(Date, 50, "%B,%d,%Y", currTm);
        
        T = to_string(currTm->tm_hour);
        T = T + ":" + to_string(currTm->tm_min) + "Hrs";
        amount = 0;
        file << b << " " << amount << " " << Date << " " << T << endl;
    }

    int choice;
    do
    {
        cout << "\t1. Check Balance\n\t2. Widthdrowl\n\t3. Deposit\n\t4. Show Passbook\n\t5. Exit\n\t";
        cin >> choice;
        switch (choice)
        {
        case 1:
            checkBal(userID, password, phone_num);
            break;
        case 2:
            widthdrowl(userID, password, phone_num);
            break;
        case 3:
            deposit(userID, password, phone_num);
            break;
        case 4:
            showPassbook(userID, password, phone_num);
            break;
        case 5:
            system("clear");
            return;
        default:
            cout << "\n\tEntered wrong choice !!\n\tSelect again";
        }
    } while (true);
}

bool CheckPassword(string key, string password)
{
    return (key == password);
}

lli Int(string s)
{
    lli sum = 0;
    int n = s.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            j = i;
            break;
        }
    }

    for (int i = j; i < n; i++)
    {
        sum = sum + (s[i] - '0') * pow(10, n - i - 1);
    }
    return sum;
}

void check2(string phone_num)
{
    ifstream file(phone_num + ".txt");
    while (file >> b1 >> a1 >> d1 >> t1)
    {
    };
    cout << "\tDear coustumer your avilable balance is " << Int(a1) << " Thaking you.\n\tPress any key to continue.\n\t";
    getchar();
    getchar();
}

void checkBal(string userID, string password, string phone_num)
{
    cout << "\tEnter your password to check the avilable balance  ";
    cin >> key;

    if (CheckPassword(key, password))
    {
        ifstream file(phone_num + ".txt");
        while (file >> b1 >> a1 >> d1 >> t1)
        {
        };
        cout << "\tDear coustumer your avilable balance is " << Int(a1) << " Thaking you.\n\tPress any key to continue.\n\t";
        getchar();
        getchar();
    }
    else
    {
        cout << "\t\b\b\bWrong Password !!.\n\tTRY AGAIN !!\n\tPress Enter to continue\n\t";
        getchar();
        getchar();
        return;
    }
}

void deposit(string userID, string password, string phone_num)
{
    cout << "\tEnter your password to deposit funds ";
    cin >> key;
    if (CheckPassword(key, password))
    {
        ifstream file(phone_num + ".txt");


        time(&currTime);
        currTm = localtime(&currTime);
        strftime(Date, 50, "%B,%d,%Y", currTm);

        T = to_string(currTm->tm_hour);
        T = T + ":" + to_string(currTm->tm_min) +"Hrs";

        while (file >> b1 >> a1 >> d1 >> t1)
        {
        };
        cout << "\tEnter the amount that you want to add : ";
        cin >> addfund;

        amount = addfund + Int(a1);

        ofstream of(phone_num + ".txt", ios ::app);
        of << b1 << " " << amount << " " << Date << " " << T << endl;
        file.close();
        of.close();

        check2(phone_num);
    }
    else
    {
        cout << "\t\b\b\bWrong Password !!.\n\tTRY AGAIN !!\n\tPress any key to continue\n\t";
        getchar();
        getchar();
        return;
    }
}

void widthdrowl(string userID, string password, string phone_num)
{
    cout << "\tEnter your password for widthdrowling the funds ";
    cin >> key;

    if (CheckPassword(key, password))
    {
        ifstream file(phone_num + ".txt");
        while (file >> b1 >> a1 >> d1 >> t1)
        {
        };
        cout << "\tEnter the amount that you want to widthdrow : ";
        cin >> addfund;

        if (addfund > Int(a1))
        {
            cout << "\tInsufficient Fund !!.\n\tTRY AGAIN !!\n\tPress any key to continue\n";
            getchar();
            getchar();
            return;
        }
        else
        {
            time(&currTime);
            currTm = localtime(&currTime);
            strftime(Date, 50, "%B,%d,%Y", currTm);

            T = to_string(currTm->tm_hour);
            T = T + ":" + to_string(currTm->tm_min) + "Hrs";

            cout << "Fund Widthdrowl is sucessfull !!\n";
            amount = Int(a1) - addfund;
            ofstream of(phone_num + ".txt", ios ::app);
            of << b1 << " " << amount << " " << Date << " " << T << endl;
            of.close();

            check2(phone_num);
        }
    }
    else
    {
        cout << "\t\b\b\bWrong Password !!.\n\tTRY AGAIN !!\n\tPress any key to continue\n\t";
        getchar();
        getchar();
        return;
    }
}

void showPassbook(string userID, string password, string phone_num)
{
    cout << "\tEnterdeposit funds your password to show passbook ";
    cin >> key;
    if (CheckPassword(key, password))
    {
        cout << endl;
        cout << "\t*****Your Passbook*****\n";
        cout << "\tEntry\t\tAmount Avilable\t\t\tDate & Time\n";
        ifstream file(phone_num + ".txt");
        while (file >> b1 >> a1 >> d1 >> t1)
        {
            cout << "\t" << b1 << "\t\t" << a1 << "\t\t" << d1 << " " << t1 << endl;
        }
        cout << endl;
        cout << "\tPress Enter to continue !!\n";
        file.close();
        getchar();
        getchar();
   }
   else
   {
        cout << "\t\b\b\bWrong Password !!.\n\tTRY AGAIN !!\n\tPress Enter to continue\n\t";
        getchar();
        getchar();
        return;
   }
}