#include <bits/stdc++.h>

using namespace std;

class bank_acc
{
    int pin;
    string acc_holder;
    int balance;
    string address;

public:
    int t = 0;
    bank_acc()
    {
        string state;
        string city;
        cout << "ENTER YOUR NAME"<<endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, acc_holder);
        cout << "ENTER THE STATE YOU ARE LIVING IN" << endl;
        cin >> state;
        cout << "ENTER CITY YOU ARE LIVING IN" << endl;
        cin >> city;
        cout << "ENTER THE AMOUNT YOU WANT TO DEPOSIT TO YOUR ACCOUNT IF WANT TO" << endl;
        cin >> balance;
        cout << "ENTER THE PIN (IT SHOULD BE A FOUR DIGIT NUMBER)" << endl;
        cin >> pin;
        address = city + ", " + state;
    }
    void fetch_balance()
    {
        int entered_pin;
        cout << "ENTER THE PIN" << endl;
        cin >> entered_pin;
        if (entered_pin == pin)
        {
            cout << "YOU HAVE " << balance << " RUPEES LEFT CURRENTLY" << endl;
        }
        else
        {
            t++;
            cout << "THE ENTERED PIN IS WRONG. THREE MORE WRONG ATTEMPTS AND THIS ACCOUNT WILL BE BLOCKED" << endl;
        }
    }
    void deposite()
    {
        int entered_pin;
        cout << "ENTER THE PIN" << endl;
        cin >> entered_pin;
        if (entered_pin == pin)
        {
            int dep = 0;
            cout << "ENTER THE MONEY YOU WANT TO DEPOSIT" << endl;
            cin >> dep;
            balance += dep;
            cout << "THE QUERY IS COMPLETED" << endl;
        }
        else
        {
            t++;
            cout << "THE ENTERED PIN IS WRONG. THREE MORE WRONG ATTEMPTS AND THIS ACCOUNT WILL BE BLOCKED" << endl;
        }
    }
    void withdraw()
    {
        int entered_pin;
        cout << "ENTER THE PIN" << endl;
        cin >> entered_pin;
        if (entered_pin == pin)
        {
            int withdraw = 0;
            cout << "ENTER THE MONEY YOU WANT TO WITHDRAW" << endl;
            cin >> withdraw;
            balance -= withdraw;
            cout << "THE QUERY IS COMPLETED" << endl;
        }
        else
        {
            t++;
            cout << "THE ENTERED PIN IS WRONG. THREE MORE WRONG ATTEMPTS AND THIS ACCOUNT WILL BE BLOCKED" << endl;
        }
    }
    void update()
    {
        int entered_pin;
        cout << "ENTER THE PIN" << endl;
        cin >> entered_pin;
        if (entered_pin != pin)
        {
            t++;
            cout << "THE ENTERED PIN IS WRONG. THREE MORE WRONG ATTEMPTS AND THIS ACCOUNT WILL BE BLOCKED" << endl;
        }

        int ch = -1;
        cout << "ENTER 1 TO UPDATE THE PIN" << endl;
        cout << "ENTER 2 TO UPDATE THE NAME" << endl;
        cout << "ENTER 3 TO UPDATE THE ADDRESS" << endl;
        cin >> ch;
        if (ch == 1)
        {
            int new_pin;
            cout << "ENTER THE NEW PIN (A 4 DIGIT NUMBER)" << endl;
            cin >> new_pin;
            pin = new_pin;
            cout << "THE PIN IS SUCCESSFULLY UPDATED" << endl;
        }
        else if (ch == 2)
        {
            string new_name;
            cout << "ENTER THE NEW NAME" << endl;
            cin >> new_name;
            acc_holder = new_name;
            cout << "THE NAME IS SUCCESSFULLY UPDATED" << endl;
        }
        else if (ch == 3)
        {
            string state;
            string city;
            cout << "ENTER THE STATE YOU ARE LIVING IN" << endl;
            cin >> state;
            cout << "ENTER CITY YOU ARE LIVING IN" << endl;
            cin >> city;
            address = city + ", " + state;
            cout << "THE ADDRESS IS SUCCESSFULLY UPDATED" << endl;
        }
    }
};

void queries(vector<bank_acc *> &bank)
{
    int ch = -1;
    cout << "IF YOU WANT TO CREATE YOUR BANK ACCOUNT THEN ENTER 1" << endl;
    cout << "FOR ENY OTHER QUERY ENTER 2" << endl;
    cin >> ch;
    if (ch == 1)
    {
        bank_acc *obj = new bank_acc();
        bank.push_back(obj);
        cout << "THE INDEX OF YOUR ACCOUNT IS " << bank.size() - 1 << " REMEMBER IT" << endl;
    }
    else
    {
        int i = bank.size();
        cout << "ENTER THE INDEX OF YOUR ACCOUNT" << endl;
        cin >> i;
        if (i >= bank.size() || i < 0)
        {
            cout << "INCORRECT ACCOUNT NUMBER" << endl;
            return;
        }
        else if (bank[i] == NULL)
        {
            cout << "YOUR ACCOUNT HAS BEEN BLOCKED AS SOMEONE ELSE WAS TRYING TO ACCESS IT" << endl;
            return;
        }
        int sn = -1;
        cout << "IF YOU WANT TO CHECK OF YOUR BANK ACCOUNT THEN ENTER 1" << endl;
        cout << "IF YOU WANT TO DEPOSITE THEN ENTER 2" << endl;
        cout << "IF YOU WANT TO WITHDRAW THEN ENTER 3" << endl;
        cout << "IF YOU WANT TO UPDATE YOUR BANK ACCOUNT THEN ENTER 4" << endl;
        cin>>sn;
        if (sn == 1)
        {
            bank[i]->fetch_balance();
        }
        else if (sn == 2)
        {
            bank[i]->deposite();
        }
        else if (sn == 3)
        {
            bank[i]->withdraw();
        }
        else if (sn == 4)
        {
            bank[i]->update();
        }
        if (bank[i]->t > 3)
        {
            cout << "THE ACCOUNT IS GETTING BLOCKED" << endl;
            bank_acc *acc = bank[i];
            delete (acc);
            bank[i] = NULL;
        }
    }
}

int main()
{
    vector<bank_acc *> bank;
    int k = 1;
    while (true)
    {
        cout << "ENTER 0 IF YOU WANT TO EXIT OR IF WANT TO CONTINUE ENTER ANYTHING" << endl;
        cin >> k;
        if (k == 0)
        {
            cout << "YOU ARE EXITING" << endl;
            break;
        }
        queries(bank);
    }
    cout << "THANK YOU FOR USING" << endl;
    int n = bank.size();
    bank_acc *tem = NULL;
    for (int i = 0; i < n; i++)
    {
        if (bank[i])
        {
            tem = bank[i];
            delete (tem);
            bank[i] = NULL;
        }
    }
    bank.clear();
    // std::string input;

    // std::cout << "Enter a string with spaces: ";
    // std::getline(std::cin, input);

    // std::cout << "You entered: " << input << std::endl;

    return 0;
}