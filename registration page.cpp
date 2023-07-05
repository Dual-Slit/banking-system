/*
  this page for login or regitration
*/

#include <iostream>
#include <fstream>

#include"Account.cpp"

using namespace std;
const string FileName = "Login.txt";

string usserID, password, phone_num;
string usserID1, password1, phone_num1;

void Registration();
void Login();
bool check_num(string s);
bool check(string s);
bool check_user(ifstream &File, string &s);

int main()
{
    int choice;
    do
    {
        // system("clear");
        cout << "\n\n\t\t\tLogIn/Registration Management.";
        cout << "\n\n\t1. Login\n\t2. Registration\n\t3. Exit" << endl;
        cout << "\t";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Login();
            break;
        case 2:
            Registration();
            break;
        case 3:
            cout << "__________Thanking you___________\n\n\n\n\n";
            exit(1);
        }

    } while (choice != 3);
    return 0;
}

bool check_num(string s)
{
    if (s.length() == 10)
        return true;
    else
        return false;
}

bool check(string s)
{
    for (int i = 0; i < 10; i++)
    {
        if (!(s[i] >= '0' && s[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

bool check_user(ifstream &file, string &key) // return true when user not exist
{
    bool Notfound = true;
    while (file >> usserID1 >> password1 >> phone_num1)
    {
        if (key == phone_num1)
        {
            Notfound = false;
            return Notfound;
        }
    }

    return Notfound;
}

void Registration()
{
    system("clear");
    cout << "\tEnter  User ID : ";
    cin >> usserID;
    cout << "\tEnter Password  : ";
    cin >> password;
    cout << "\tEnter Mobile No  : ";
    cin >> phone_num;
    // let check that this number is already exist of not;
    ifstream cfile(FileName);
    string key = phone_num;
    ofstream file(FileName, ios::app);
    if (check_user(cfile, key)) // if not then registred
    {

        if (check_num(phone_num))
        {
            if (check(phone_num))
            {
                // writting in the file
                if (file.is_open()) // checking that file is open or not
                {

                    file << usserID << " " << password << " " << phone_num << endl;
                    cout << "\tSucceessfully Registered";
                    file.close();
                    account(usserID, password, phone_num);
                    return;
                }
                else
                {
                    cout << "\t________________RETRY_______________";
                    cout << "\t_______ERROR IN REGISTRATION________";
                    return;
                }
            }

            else
            {
                cout << "\tMobile Number must have only digits.\n";
                return;
            }
        }
        else
        {
            cout << "\tMobile Number must have ten digits.\n";
            return;
        }
    }

    else
    {
        cout << "\tUser already Exist !! login or try with another Mobile number"<<endl;
    }
}

void Login()
{
    system("clear");
    ifstream file(FileName);
    string u_ID, pass, mobile;
    cout << "\tEnter the userID : ";
    cin >> u_ID;
    cout << "\tEnter the Password : ";
    cin >> pass;
    cout << "\tEnter the Mobile No : ";
    cin >> mobile;
    bool Notfound = true;
    while (file >> usserID >> password >> phone_num)
    {
        if (u_ID == usserID && pass == password && mobile == phone_num)
        {
            cout << "\t____Login Successfully____\n";
            Notfound = false;
            account(usserID, password, phone_num, false);
            return;
        }
    }
    if (Notfound)
    {
        cout << "\tInvalid Credential !! Try Again";
        return;
    }
}