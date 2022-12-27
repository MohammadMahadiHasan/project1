#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;
class bank{
    private:
    string id,pass,name,fname,address,phone,pin; //
    double balance; //
    double* available_money;
public:
void menu();
void bank_management();
void atm_management();
void new_user();
void allready_user();
void deposit();
void withdraw();
void transfer();
void payment();
void user_balance();
void atm_withdraw();
void atm_deposit();
void search();
void edit();
void atm_money();

};
void bank::atm_money() {
    double v;
    cout << "Enter money add to ATM: " << endl;
    cin >> v;

    // Open the "bank.txt" file in input mode
    fstream file;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Read the available money from the file
    double available_money;
    file >> available_money;

    // Close the file
    file.close();

    // Add the specified amount to the available money
    available_money += v;

    // Open the "bank.txt" file in output mode
    file.open("bank.txt", ios::out);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Write the updated available money to the file
    file << available_money;

    // Close the file
    file.close();

    cout << "Available money in ATM is: " << available_money << endl;
}


void bank::menu()
{

    p:
    system("cls");
    int choice;
    char ch;
    string pin,pass,email;
    cout<<"\n\n\t\t\t  Bank Control panel";
    cout<<endl;
    cout<<endl;
    cout<<"\n 1. Bank Management";
    cout<<endl;
    cout<<" 2. ATM Management";
    cout<<endl;
    cout<<" 3. Exit";
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter Your  Choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
    cout<<"\n\n\t\tLOG IN Account";
    cout<<"\n\n Email Address:" ;
    cin>>email;
    cout<<"\n\n Pin Code : ";
    for(int i=1; i<=5;i++)
    {
        ch=getch();
        pin+=ch;
        cout<<"*";
    }
    cout<<"\n\n Password : ";
    for(int i=1; i<=5;i++)
    {
        ch=getch();
        pass+=ch;
        cout<<"*";
    }
    if(email =="mahadi@gmail.com" && pin=="13366" && pass=="14366")
    {
        bank_management();
    }
    else{
        cout<<"wrong!";
    }
        break;

    case 2:
    atm_management();
    break;
    case 3:
    exit(0);
    default:
    cout<<"Wrong Choice please try again."<<endl;
      getch();
      goto p;
    }

    //getch();
   //goto p;

}
void bank::bank_management()
{
     p:
    system("cls");
    int choice;
    cout<<"\n\n \t \t \t \tBank Management System";
    cout<<endl;
    cout<<endl;
    cout<<"1. Create New User"<<endl;
    cout<<"2. Already User"<<endl;
    cout<<"3. Deposit"<<endl;
    cout<<"4. Withdraw"<<endl;
    cout<<"5. Balance Transfer"<<endl;
    cout<<"6. Payment"<<endl;
    cout<<"7.Search User Record"<<endl;
    cout<<"8. Edit User Record"<<endl;
    cout<<"9. Go Back"<<endl;
    cout<<"10. Add Money on ATM"<<endl;
    cout<<"Enter Your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
    new_user();
    break;
    case 2:
    allready_user();
    break;
    case 3:
    deposit();
    break;
    case 4:
    withdraw();
    break;
    case 5:
    transfer();
    break;
    case 6:
        payment();
        break;
    break;
    case 7:
    	search(	);
    break;
    case 8:
    	edit();
    break;
    case 9:
    	menu();
    case 10:
        atm_money();
        break;
    /*default:
        cout<<"Wrong!"<<endl;
    }*/
    getch();
    goto p;


}
}


void bank::atm_management()
{
    p:
          // Initialize variables


    system("cls");
    int choice;
    cout<<"\n\n \t \t \t \tATM Management System";
    cout<<endl;
    cout<<endl;
    cout<<"1. Login & Check Balence"<<endl;
    cout<<"2. Withdraw Amount"<<endl;
    cout<<"3. Deposit Money"<<endl;
    cout<<"4. Back To Main Menu"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Enter Your Choice: "<<endl;
    cin>>choice;
    switch(choice)
    {
        case 1:
        user_balance();
        break;
        case 2:
        atm_withdraw();
        break;
        case 3:
        atm_deposit();
        break;
        case 4:
            menu();
        default:
            cout<<"wrong Entry"<<endl;

    }
    getch();
    goto p;
}
void bank :: new_user()
{
    p:
    system("cls");
    fstream file;
    float b;
    int p;
    string n,f,pa,a,ph,i;
    cout<<"Add New User";
    cout<<endl;
    cout<<endl;
    cout<<"User ID: ";
    cin>>id;
    cout<<endl;
    cout<<"User Name:";
    cin>>name;
    cout<<endl;
    cout<<"Father Name: ";
    cin>>fname;
    cout<<endl;
    cout<<"Address:";
    cin>>address;
    cout<<endl;
    cout<<"Pin Code (5 digit) :";
    cin>>pin;
    cout<<endl;
    cout<<"Password (5 digit):";
    cin>>pass;
    cout<<"Phone Number: ";
    cin>>phone;
    cout <<endl;
    cout<<"Current Balance: ";
    cin>>balance;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" "<<endl;
        file.close();
    }
    else{
        file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        while (!file.eof())
        {

            if(i== id)
            {
                cout<<"User ID allready Exist..";
                getch();
                goto p;
            }
             file>>i>>n>>f>>a>>p>>pa>>ph>>b;

        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<" "<<endl;
        file.close();

    }
    cout<<endl;
    cout<<"New user has been added successfull.";

}
void bank::allready_user()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout<<"Already an User Account"<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<endl;
        cout<<"File opening error";

    }
    else
    {
       cout<<endl;
       cout<<"User ID: ";
       cin>>t_id;
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while (!file.eof())
       {
        if(t_id==id)
        {
            system("cls");
            cout<<"\n Allready an User Account";
            cout<<endl;
            cout<<"\n \n User ID: "<<id<<endl;
            cout<<endl;
            cout<<"Pin Code"<<pin<<endl;
            cout<<"Password: "<<pass<<endl;
        }

        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       }
       file.close();
       if(found==0)
       {

       cout<<endl;
       cout<<"User ID can't be found";
   }

    }


}
void bank::deposit(){

    system("cls");
    fstream file,file1;
    string t_id;
    float dep;
    //file1.open("bank.txt",ios::app|ios::out);
    int found=0 ;
    cout<<"Deposit Money";
    cout<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
     else
    {
       //cout<<endl;
       cout<<"User ID: ";
       cin>>t_id;
       file1.open("bank.txt",ios::app|ios::out);
       file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       while (!file.eof())
       {
        if(t_id==id)
        {
            cout<<endl;
            cout<<"Enter Amount For Deposit:";
            cin>>dep;
            balance+=dep;
            //file>>dep;

             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<endl;
             found++;
            cout<<"\nYour Amount BDT: "<<dep<<" deposited succesfully"<<endl;

        }
        else
        {
             file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<endl;

        }

        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
       }
       file.close();
       file1.close();
       remove("bank.txt");
       rename("bank1.txt","bank.txt");
       if(found==0)
       cout<<endl;
       cout<<"User ID can't be found";
        getch();


    }
}

void bank::withdraw() {
    system("cls");
    fstream file, file1;
    string t_id, entered_pin, entered_pass;
    float with;
    int found = 0;

    cout << "Withdraw" << endl;
    cout << "User ID: ";
    cin >> t_id;
    cout << "Enter PIN: ";
    cin >> entered_pin;
    cout << "Enter password: ";
    cin >> entered_pass;

    // Open the file for reading
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening error!." << endl;
    } else {
        file1.open("bank.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof()) {
            if (t_id == id && entered_pin == pin && entered_pass == pass) {
                cout << endl;
                cout << "Enter Amount For Withdraw:";
                cin >> with;
                if (with <= balance) {
                    balance -= with;

                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << phone << " " << balance << " " << endl;
                    found++;
                    cout << "\nYour Amount BDT: " << with << "Withdrawed succesfully" << endl;
                } else {
                    cout << "You Don't have enough money to withdraw" << endl;
                }
                found++;
            } else {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << phone << " " << balance << " " << endl;
            }

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0) {
            cout << endl;
            cout << "User ID, PIN, or password is incorrect";
        }
    }
}



void bank:: transfer()
{
    fstream file,file1;
    system("cls");
    string s_id,r_id;
    float amount;
    int found =0;
    cout <<"\n\n\t\t Payment Transfer:";
    file.open("bank.txt");
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
     else{
        cout<<"Sender User ID:";
        cin>>s_id;
        cout<<"Reciever User ID:";
        cin>>r_id;
        cout<<"Enter Transaction Amount:";
        cin>>amount;

        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while (!file.eof())
        {
           if(s_id==id && amount<=balance)
             found++;
             else if(r_id==id)
             found++;


            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file1.close();
        if(found==2)
        {
            file1.open("bank.txt",ios::in);
             file1.open("bank1.txt",ios::app|ios::out);
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
              while(!file.eof())
              {
                if(s_id==id)
                {
                    balance-=amount;
                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<endl;
                }
                else if(r_id==id)
                {
                    balance+=amount;
                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<endl;

                }
                else
                {
                     file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<endl;
                }
                 file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
              }
              file1.close();
              file1.close();
              remove("bank.txt");
              rename("bank1.txt","bank.txt");
              cout<<"------Transaction Successful------"<<endl;

        }
        else{
            cout<<"Both Transaction user ID not found or balance invalid!"<<endl;
        }
     }

}
void bank::payment()
{

    system("cls");
    fstream file,file1;
    int found=0;
    float amount;
    string t_id,b_name;
    SYSTEMTIME x;
    cout<<"Pay Bills"<<endl;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
    else
    {
        cout<<"User ID:";
        cin>>t_id;
        cout<<"\n\n Bill Name";
        cin>>b_name;
        cout<<"Bill Amount:";
        cin>>amount;
        file1.open("bank1.txt",ios::app|ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id==id && amount<=balance)
            {
                balance-=amount;
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<endl;
                found++;
            }
            else
            {
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<" "<<endl;
            }
            file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
              remove("bank.txt");
              rename("bank1.txt","bank.txt");
        if(found == 1)
        {
            GetSystemTime(&x);
            file.open("bill.txt",ios::app|ios::out);
            file<<t_id<<" "<<b_name<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<endl;
            file.close();
            cout<<" "<<b_name<<"Bill paid succesfully"<<endl;
        }

    }

}
void bank::user_balance()
{
    system("cls");
    fstream file;
    string t_id, t_pin, t_pass;
    int found = 0;
    char ch;
    cout << "User Login and Check Balance" << endl;
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout << "\nFile Opening error!." << endl;
    }
    else
    {
        cout << "\n\n  User ID: ";
        cin >> t_id;
        cout << "\n\n Pin Code:";
        for(int i = 1; i <= 5; i++)
        {
            ch = getch();
            t_pin += ch;
            cout << "*";
        }
        cout << "\n\n Password :";
        for(int i = 1; i <= 5; i++)
        {
            ch = getch();
            t_pass += ch;
            cout << "*";
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while(!file.eof())
        {
            if(t_id == id)
            {
                if(t_pass == pass)
                {
                    if(t_pin == pin)
                    {
                        cout << endl;
                        cout << endl;
                        cout << "Your Current Balance is : " << balance;
                        found++;
                    }
                }
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if(found == 0)
        {
            cout << endl;
            cout << endl;
            cout << "User ID and Password invalid" << endl;
        }
    }
}

void bank::atm_withdraw() {
    fstream file, file1;
    string t_id, t_pin, t_pass;
    double available_money, with;
    char ch;
    int found = 0;

    system("cls");
    cout << "Withdraw" << endl;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening error!." << endl;
        return;
    }

    cout << "User ID: ";
    cin >> t_id;
    cout << "\n\n Pin Code:";
    for (int i = 1; i <= 5; i++) {
        ch = getch();
        t_pin += ch;
        cout << "*";
    }
    cout << "\n\n Password :";
    for (int i = 1; i <= 5; i++) {
        ch = getch();
        t_pass += ch;
        cout << "*";
    }

    file1.open("bank.txt", ios::app | ios::out);
    file >> available_money;
    file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    while (!file.eof()) {
        if (t_id == id && t_pin == pin && t_pass == pass) {
            cout << endl;
            cout << "Enter Amount For Withdraw:";
            cin >> with;
            if (with <= balance && with <= available_money) {
                balance -= with;
                available_money -= with;

                file1 << " " << available_money << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << phone << " " << balance << endl;
                found++;
                cout << "\nYour Amount BDT: " << with << "Withdrawed succesfully" << endl;
                cout << "Available Money in the ATM Booth: " << available_money;
            } else {
                cout << "You Don't have enough money to withdraw" << endl;
                cout << "Your Amount BDT: " << balance << endl;
                cout << "Available Money in the ATM Booth: " << available_money;
            }
            // Add a break statement here
            break;
        } else {
            file1 << " " << available_money << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << phone << " " << balance << endl;
        }

        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    }
    file.close();
    file1.close();
    remove("bank.txt");
    rename("bank1.txt", "bank.txt");
    if (found == 0) {
        cout << endl;


        cout << "User ID can't be found" << endl;
    }
}


void bank::atm_deposit() {
    fstream file, file1;
    string t_id, t_pin, t_pass;
    double v;
    char ch;
    float dep;
    int found = 0;
    cout << "Deposit Money" << endl;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "\nFile Opening error!." << endl;
    } else {
        cout << "User ID: ";
        cin >> t_id;
        cout << "\nPin Code:";
        for (int i = 1; i <= 5; i++) {
            ch = getch();
            t_pin += ch;
            cout << "*";
        }
        cout << "\nPassword :";
        for (int i = 1; i <= 5; i++) {
            ch = getch();
            t_pass += ch;
            cout << "*";
        }
        file1.open("bank.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance >> v;
        while (!file.eof()) {
            if (t_id == id && t_pin == pin && t_pass == pass) {
                cout << endl;
                cout << "Enter Amount For Deposit:";
                cin >> dep;
                v += dep;
                balance += dep;
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << phone << " " << balance << " " << phone << " " << v << " " << endl;
                found++;
                cout << "\nYour Amount BDT: " << dep << " deposited succesfully" << endl;
                cout << "Available Money in the ATM Booth: " << v;
            } else {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << phone << " " << balance << " " << v << " " << endl;
            }

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance >> v;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
            cout << endl;
        cout << "User ID can't be found";
    }
}

void bank::search() {
    system("cls");
    cout << "Search User Record" << endl;

    // Open the "bank.txt" file in input mode
    fstream file;
    file.open("bank.txt", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    // Read the user ID to search for
    string t_id;
    cout << "User ID:";
    cin >> t_id;

    // Read the user's account information from the file
    string id, name, fname, address, pin, pass, phone;
    double balance;
    file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;

    // Search for the user's information in the file
    int found = 0;
    while (!file.eof()) {
        if (t_id == id) {
            // Display the user's information on the screen
            system("cls");
            cout << "Search User Record" << endl;
            cout << endl;
            cout << "User ID: " << id << "Name: " << name << "Father's Name: " << fname;
            cout << "\n\nAddress: " << address << "     Pin: " << pin << "  Password: " << pass;
            cout << "\n\nPhone Number: " << phone << "    Current Balance: " << balance;
            found++;
            break;
        }
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
    }

    // Close the file
    file.close();

    // Display an error message if the user's information was not found in the file
    if (found == 0) {
        cout << "User ID not found" << endl;
    }
}

void bank::edit()
{
    system("cls");
    cout<<"\n\nEdit User Record"<<endl;
    fstream file;
    string t_id;
    string p,n,f,a,ph,pi;
    int found = 0;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<"\nFile Opening error!."<<endl;
    }
    else
    {
        cout<<"User ID:";
        cin>>t_id;
        ofstream file1("bank1.txt", ios::app | ios::out);
        file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
        while(!file.eof())
        {
            if(t_id==id)
            {
                cout<<"Add New User Record";
                cout<<endl;
                cout<<endl;
                cout<<"User ID: ";
                cin>>id;
                cout<<endl;
                cout<<"User Name:";
                cin>>n;
                cout<<endl;
                cout<<"Father Name: ";
                cin>>f;
                cout<<endl;
                cout<<"Address:";
                cin>>a;
                cout<<endl;
                cout<<"Pin Code (5 digit) :";
                cin>>pi;
                cout<<endl;
                cout<<"Password (5 digit):";
                cin>>p;
                cout<<"Phone Number: ";
                cin>>ph;
                cout <<endl;

                file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<pi<<" "<<p<<" "<<ph<<" "<<balance<<endl;
                cout<<"\n \nRecord Updated Successfully"<<endl;
                found++;
            }

            else
            {
                file1<<" "<<id<<" "<<name<<" "<<fname<<" "<<address<<" "<<pin<<" "<<phone<<" "<<balance<<endl;
            }
              file>>id>>name>>fname>>address>>pin>>pass>>phone>>balance;
         }
         file.close();
         file1.close();
         remove("bank.txt");
         rename("bank1.txt","bank.txt");
         if(found==0)
         {
             cout<<"User ID didn't found"<<endl;
         }
    }

}

int main()
{
    system("color B9 ");
    bank obj;
    obj.menu();
}
