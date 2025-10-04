#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
using namespace std;

// string getCurrentTime()
// {
//     time_t now =time(0);
//     string currentdate[11];
//     string currentTime[9];
//     _strdate_s(currentdate, 11);
//     _strtime_s(currentTime, 9);
//     return string(currentdate) + " " + string(currentTime);

// }

class user{
    protected:
        string username;
        string password;
    
    public:
        user()
        {

        }
        user(string username, string password)
        {
            this->username=username;
            this->password=password;
        }
        string setusername(string userName)
        {
            username=userName;
        }
        string setpassword(string Password)
        {
            password=Password;
        }
        void changepassword()
        {
            string newpassword;
            cout << "\t\t\tEnter New Password:";
            cin >> newpassword;
            password = newpassword;
            cout << "\t\t\t Password Changed Successfully";
        }
        string getname()
        {
            return username;
        }
        string getpassword()
        {
            return password;
        }
        virtual ~user(){} // destructor for easy cleanup
        
};
class customer: public user{
    public:
        customer()
        {

        }
        customer(string username,string password):user(username, password)
        {
        }
        bool  login()
        {
            string enteredpin, enteredid;
            cout << "\t\t\tEnter Username:";
            cin >> enteredid;
            cout << "\t\t\tEnter Password";
            cin >> enteredpin;
            
            if ( enteredid == "user" && enteredpin == "user")
            {
                cout << "\t\t\tLogin Successful\n";
                return true;
            }
            else {
                if (enteredid != "user")
                {cout << "\t\t\tUsername Not Found\n";}
                else {
                    cout << "\t\t\tInvalid Password. Login Failed\n";
                }
                cout << "\t\t\t Forgot Password!! Press Y for Changing Password\n"; 
                char y;
                if (y == 'Y'|| y == 'y')
                {
                    customer::changepassword();
                }
            return false;
            }
            
        }
        ~customer(); // destructor for easy cleanup

};
class admin: public user{
    public:
        admin(){
            username ="admin";
            password ="admin";
        }
        admin(string userName, string password) : user(username, password)
        {

        }
        void display()
        {
            cout << "\t\t\tAdmin\n";
        }
        bool login()
        {
            string enter_Username, enter_Password;
             cout << "\t\t\tEnter Username:";
            cin >> enter_Username;
            cout << "\t\t\tEnter Password";
            cin >> enter_Password;
            if( enter_Username == "admin" && enter_Password == "admin")
            {
                return true;
            }
            else {
                if(enter_Username != "admin")
                {
                    cout << "\t\t\tInvalid Username\n";
                }
                else {
                    cout << "\t\t\tInvalid Password\n";
                }
                cout << "\t\t\tTo Change Your Password Please Press Y";
                char y;
                if (y == 'Y' || y == 'y')
                {
                    admin:changepassword;
                }
            return false;
            }
        }
        ~admin();
};
class account{
    protected:
        int accnumber;
        string firstname;
        string lastname;
        double balance;
        string cardtype;
        string phonenum;
        string email;

    public:
        account(){
            accnumber =0;
            balance = 0;
            firstname = "";
            lastname = "";
            cardtype = "";
            phonenum = "";
            email = "";
        }
        account(int accnumber, string firstname, string lastname, double balance, string cardtype, string phonenum, string email)
        {
            this->accnumber=accnumber;
            this->firstname = firstname;
            this->lastname = lastname;
            this->cardtype = cardtype;
            this->phonenum = phonenum;
            this->email = email;
        }
        string getFirstname()
        {
            return firstname;
        }
        void setFirstname(string firstName)
        {
            firstname = firstName;
        }
        string getLastname()
        {
            return lastname;
        }
        void setLastname(string lastName)
        {
            lastname = lastName;
        }
        string getCardtype()
        {
            return cardtype;
        }
        void setCardtype(string cardType)
        {
            cardtype = cardType;
        }
        string getPhonenum()
        {
            return phonenum;
        }
        void setPhonenum(string Phonenum)
        {
            phonenum = Phonenum;
        }
        string getEmail()
        {
            return email;
        }
        void setEmail(string Email)
        {
            email = Email;
        }
        int getAccnumber()
        {
            return accnumber;
        }
        void setAccnumber(int accNumber)
        {
            accnumber = accNumber;
        }
        double getBalance()
        {
            return balance ;
        }
        void setBalance(double Balance)
        {
            balance = Balance;
        }
       
        virtual void deposit(double)=0;
        virtual void deleteaccount(string, int)=0;
        virtual void withdraw(double)= 0;
        virtual void saveAccountData ()= 0;
        virtual void Addaccount()=0;
        virtual void updateaccount()=0;
        virtual void display() const=0;
        virtual void searchaccount()=0;
};

class savingaccount: public account
{
    private:
        string savedatafile;
        int size;
        customer** Customer; //The first * indicates that Customer is a pointer.The second * means that what Customer points to is itself a pointer to a customer object.This is often used when you want to manage a collection of dynamically allocated customer objects, such as an array where each element is a pointer to a customer.
        savingaccount** Saveaccount;
        admin Admin;
    public:
    savingaccount(){
        Customer = nullptr;
        Saveaccount= nullptr;
        size = 0;
    }
    savingaccount(string filename, int S){
        this->savedatafile= filename;
        this->size = S;
        
        Saveaccount= new savingaccount *[size];
        Customer = new customer *[size];

        for(int i =0; i<=size; i++)
        {
            Saveaccount[i]=nullptr;
            Customer [i]=nullptr;
        }
    }

};
int main()
{
    return 0;
}