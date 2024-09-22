#include <iostream>
using namespace std;
#include <string>



class user{
    protected:
        double balance;

    public:
        user(double var_bal = 0): balance(var_bal) {}

    virtual void deposit(double amount){
        if (amount > 0){
            balance += amount;
                cout<<"Successful deposit, New Balance: /n"<<balance<<endl;
        }
        
        else{
            cout<<"Invalid amount please try again: "<<endl;
        }
    }

    virtual void withdraw(double amount) = 0;

    virtual void check_bal() const {
        cout<<"Balance: "<<balance<<endl;
      } 

  
};


class cur_acc: public user{
    public: 
        cur_acc(double var_bal = 0): user(var_bal) {}

        void withdraw(double amount) override{
            if(amount < 0){
                cout<<"Invalid amount please try again. "<<endl;
            }

            else if(amount > balance){
                cout<<" Insufficient Balance, please try again "<<endl;
            }

            else{
                balance -= amount;
                cout<<"Withdrawal successful, new Balance: "<<balance<<endl;
            }
        }


};

class sav_acc: public user{
    public:
        sav_acc(double var_bal = 1000): user(var_bal) {}

        void withdraw(double amount) override{
            if(amount < 0){
                cout<<"Invalid amount please try again. "<<endl;
            }

            else if(amount > balance){
                cout<<" Insufficient Balance, please try again "<<endl;
            }

            else{
                balance -= amount;
                cout<<"Withdrawal successful, new Balance: "<<balance<<endl;
            }
        }

  

};

void sav_sub_menu(sav_acc &user){
            
            int choice;
            double amount;

            do{
                cout<<"\nSub Menu\n"<<endl;

                cout<<"1. Deposit\n"<<endl;
                cout<<"2. Withdraw\n"<<endl;
                cout<<"3. Check Balance\n"<<endl;
                cout<<"4. Exit\n"<<endl;

                    cout<<"Enter choice: \n"<<endl;
                        cin>>choice;

            switch (choice)
            {
            case 1:
                cout<<"Enter amount to deposit: \n"<<endl;
                    cin>>amount;
                    user.deposit(amount);
                    break;
            case 2:
                cout<<"Enter amount to withdraw: "<<endl;
                    cin>>amount;
                    user.withdraw(amount);
                    break;
            case 3:
                    user.check_bal();
                    break;
            case 4: 
                cout<<"Exiting sub menu \n"<<endl;
                    break;
            
            default:
                cout<<"Invalid choice please try again\n"<<endl;
            }
            }while(choice != 4);
    }

    void cur_sub_menu(cur_acc &user){
            
            int choice;
            double amount;

            do{
                cout<<"\nSub Menu\n"<<endl;

                cout<<"1. Deposit\n"<<endl;
                cout<<"2. Withdraw\n"<<endl;
                cout<<"3. Check Balance\n"<<endl;
                cout<<"4. Exit\n"<<endl;

                    cout<<"Enter choice: \n"<<endl;
                        cin>>choice;

            switch (choice)
            {
            case 1:
                cout<<"Enter amount to deposit: \n"<<endl;
                    cin>>amount;
                    user.deposit(amount);
                    break;
            case 2:
                cout<<"Enter amount to withdraw: "<<endl;
                    cin>>amount;
                    user.withdraw(amount);
                    break;
            case 3:
                    user.check_bal();
                    break;
            case 4: 
                cout<<"Exiting sub menu \n"<<endl;
                    break;
            
            default:
                cout<<"Invalid choice please try again\n"<<endl;
            }
            }while(choice != 4);
    }

void main_menu(){
    int choice;
        sav_acc sav_acc(1000);
        cur_acc cur_acc(0);
    
    do{
        cout<<"\nMain Menu\n "<<endl;
        cout<<"1. Savings Account\n"<<endl;
        cout<<"2. Current Account\n"<<endl;
        cout<<"3. Exit\n"<<endl;
            cout<<"Enter your choice: "<<endl;
                cin>>choice;

            switch (choice)
            {
            case 1:
                sav_sub_menu(sav_acc);
                break;

            case 2:
                cur_sub_menu(cur_acc);
                break;

            case 3:
                cout<<"Exiting the system.\n";
                break;
            
            default:
                cout<<"Invalid choice. Please Try again. \n";
            }
    
    }while(choice != 3);
}



int main(){

    main_menu();

}
