#include<iostream>
using namespace std;

class BankDeposit{
    int principal;
    int years;
    float interestRate;
    float returnValue;
    public:
        BankDeposit(){}
        BankDeposit(int , int , float);
        BankDeposit(int , int , int);

        void display(void){
            cout<<"The amount that you will get in return after "<<years<<" years is: "<<returnValue<<endl;
        }
};

BankDeposit :: BankDeposit (int p , int y , float r){
    returnValue = p;
    interestRate = r;
    years = y;
    for (int i= 0; i < years; i++){
        returnValue = returnValue * (1+interestRate);
        cout<<returnValue<<endl;
    }
}

BankDeposit :: BankDeposit (int p , int y , int R){
    returnValue = p;
    interestRate = float(R)/100;
    years = y;
    for (int i= 0; i < years; i++){
        returnValue = returnValue * (1+interestRate);
    }
}

int main(){
    int prin, years, Rate;
    float rate;
    // cout<<"Enter the values of principal amount, years and interest rate in this order itself"<<endl;
    // cin>>prin>>years>>rate;
    // BankDeposit bd1 = BankDeposit(prin, years, rate);
    // bd1.display();

    // cout<<"\nEnter the values of principal amount, years and interest rate(%) in this order itself"<<endl;
    // cin>>prin>>years>>Rate;
    // BankDeposit bd2 = BankDeposit(prin, years, Rate);
    // bd2.display();


/* 2nd Method */

    BankDeposit bd1, bd2, bd3; // for this declaration we have to give an empty 
    // constructor above as the compiler will see that there are constructors present 
    // in this class so it will try to call the default constructor at the time of 
    // declaration as we are not giving any arguments, but it will fail to do so.
    
    
    cout<<"Enter the values of principal amount, years and interest rate in this order itself"<<endl;
    cin>>prin>>years>>rate;
    bd1 = BankDeposit(prin, years, rate);
    bd1.display();

    cout<<"\nEnter the values of principal amount, years and interest rate(%) in this order itself"<<endl;
    cin>>prin>>years>>Rate;
    bd2 = BankDeposit(prin, years, Rate);
    bd2.display();

    return 0;
}