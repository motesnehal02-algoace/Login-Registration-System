#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void registerUser()
{
    string username, password;
    string user, pass;
    bool found = false;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream fin("users.txt");

    while(fin >> user >> pass)
    {
        if(username == user)
        {
            found = true;
            break;
        }
    }

    fin.close();

    if(found)
    {
        cout << "Username already exists." << endl;
    }
    else
    {
        ofstream fout("users.txt", ios::app);
        fout << username << " " << password << endl;
        fout.close();

        cout << "Registration Successful." << endl;
    }
}

void loginUser()
{
    string username, password;
    string user, pass;
    bool found = false;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream fin("users.txt");

    while(fin >> user >> pass)
    {
        if(username == user && password == pass)
        {
            found = true;
            break;
        }
    }

    fin.close();

    if(found)
    {
        cout << "Login Successful." << endl;
    }
    else
    {
        cout << "Invalid Username or Password." << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Register";
        cout << "\n2. Login";
        cout << "\n3. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Thank You!";
                break;

            default:
                cout << "Invalid Choice.";
        }

    }while(choice != 3);

    return 0;
}