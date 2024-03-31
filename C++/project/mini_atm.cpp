#include<bits/stdc++.h>
#include<conio.h>
#include<string>
using namespace std;

/*
    ->  MINI_Project - ATM
    ->  Cheeck Balance 
    ->  Cash Withdraw
    ->  User Details
    ->  Update Mobile No.
*/

class ATM{     // class ATM

private:

    // Necessary Details
    // Personal Entry Of User So It Is Privated
    long int Account_No;
    string Name;
    string Mobile_No;
    double Balance;
    int PIN;
    string Adhar_No;

public: 

    // making setter for set the value for object

    void setAccountNo(long int Account_No){
        this->Account_No = Account_No;
    }

    void setName(string Name){
        this->Name = Name;
    }

    void setMobileNo(string Mobile_No){
        this->Mobile_No = Mobile_No;
    }

    void setBalance(double Balance){
        this->Balance = Balance;
    }

    void setPIN(int PIN){
        this->PIN = PIN;
    }

    void setAdharNo(string Adhar_No){
        this->Adhar_No = Adhar_No;
    }

    // taking the object value by getter func..

    long int getAccount_no()
    {
        return Account_No;
    }

    double getBalance()
    {
        return Balance;
    }

    string getName()
    {
        return Name;
    }

    string getMobile_No()
    {
        return Mobile_No;
    }

    int get_PIN()
    {
        return PIN;
    }

    string getadhar(){
        return Adhar_No;
    }

    // set mobile number or update mobile no.
    void changeMobileNo(string mob_prev , string new_mob)
    {
        //now check the previous mobile numer is same or not

        if( Mobile_No == mob_prev)
        {
            this->Mobile_No = new_mob;        //new mobile number updated
            cout<<"Sucessfully Mobile Number Update \n";
        }
        else 
        {
            cout<<"Incorrect Mobile No. !! \n";
        }
        _getch();   //used for holing the screen..

    }

    void changeAdharNo(string prev_adhar , string new_adhar)
    {
        //now check the previous mobile numer is same or not

        if( prev_adhar == Adhar_No)
        {
            this->Adhar_No = new_adhar;        //new mobile number updated
            cout<<"Sucessfully Adhar Number Update \n";
        }
        else 
        {
            cout<<"Incorrect Adhar No. !! \n";
        }
        _getch();   //used for holing the screen..

    }

    void cashWithDraw(int amount)
    {
        // first we r checking enter amount is availabe or not int this bank account..
        if( amount > 0 && amount <= Balance)
        {
            Balance -= amount;
            cout<<"Please Collect Your Cash \n";
            cout<<"Remaining Balance : " << Balance<<"\n";
        }
        else
        {
            cout<<"Balance is not available \n";

        }
        _getch();
    }
};

int main(){

    int choice,enterPIN;
    long int enterAccountNo;
   
    cout<<"Welcome To your XYZ Bank\n\n";
    int x;
    cout<<"Enter True or 1 If You Want To Open Your Bank Account :";
    cin>>x;

    ATM user1;
    if(x != 1)
    {
        cout<<"Thankyou for visiting...\n";
         return 0;
    }
    else 
    {
        string mobileNo;
        string adhar;
        string name;
         double balance;

        cout<<"Now give me the correct information \n";

        cout<<"Enter Name :";
        cin>>name;
        user1.setName(name);
       
        cout<<"Enter Mobile No.  :";
        cin>>mobileNo;
        user1.setMobileNo(mobileNo);

        cout<<"Enter adhar No. :";
        cin>>adhar;
        user1.setAdharNo(adhar);

        cout<<"Enter Balance :";
        cin>>balance;
        user1.setBalance(balance);

        cout<<"Take account no. : 12345\n";
        user1.setAccountNo(12345);

        cout<<"Enter PIN to Acess Balance : ";
        cin>>enterPIN;
        user1.setPIN(enterPIN);

        cout<<endl <<"Your Account Has Been Created !!\n";
        cout<<"**Thankyou**\n";
    }



    system("cls");

    // set user details

    // user1.setData(4735000122 , "Harsh", "8869826279", 45556.459, 9371);

    do
    {
        system("cls");

        cout<<"****Welcome To ATM**** \n";
        cout<<"Enter Account No : ";      //enter account no.
        cin>>enterAccountNo;

        if(enterAccountNo != user1.getAccount_no())
        {
            cout<<"Wrong Account No !!";
            break;
        }

        cout<<"\nEnter PIN :";
        cin>>enterPIN;

        if(enterPIN != user1.get_PIN() )
        {
            cout<<"Wrong PIN No !!";
            break;
        }

        cout<<"Hi "<<user1.getName()<<" Welcome To Your Bank"<<endl;

        do
        {
            int amount=0;
            string Pmob,Nmob;

            system("cls");

            cout<<"****Welcome To ATM**** \n";
            cout<<"Select Options : \n";
            cout<<"1. Check Balance : \n";
            cout<<"2. Cash Withdraw : \n";
            cout<<"3. Show User Details : \n";
            cout<<"4. Update Mobile No. : \n";
            cout<<"5. Update Adhar No. : \n";
            cout<<"6. To Exit: \n";
          
            cout<<"Enter : ";
            
            cin>>choice;

            switch(choice)
            {
                case 1:
                cout<<"Your Balance Is : "<<user1.getBalance()<<endl;
                _getch();
                break;

                case 2:
                cout<<"Enter the Amount : ";
                cin>>amount;
                user1.cashWithDraw(amount);
                break;

                case 3:
                cout<<"\n ****User Details are :- \n";
                cout<<"-> Name : "<<user1.getName()<<endl;
                cout<<"-> Account No. : "<<user1.getAccount_no()<<endl;
                cout<<"-> Adhar No. : "<<user1.getadhar()<<endl;
                cout<<"-> Balance : "<<user1.getBalance()<<endl;
                cout<<"-> Mobile No. : "<<user1.getMobile_No()<<endl;

                _getch();
                break;

                case 4: 
                cout<<"Enter Mobile No : ";
                cin>>Pmob;

                cout<<"\nEnter New Mobile No :";
                cin>>Nmob;

                user1.changeMobileNo(Pmob , Nmob);
                break;

                case 5:
                cout<<"Enter adhar No : ";
                cin>>Pmob;

                cout<<"\nEnter New adhar No :";
                cin>>Nmob;

                user1.changeAdharNo(Pmob , Nmob);
                break;

                case 6:
                cout<<"Thankyou For Visiting..."<<endl;
                exit(0);

                default:
                cout<<"Invalid Data Found : \n";
                break;

            }
            
        }while(1);

    }while(1);


    return 0;
}