#include<iostream>
using namespace std;

class shop{
    int itemId[100];
    int itemPrice[100];
    int counter;

    public:
        void initCounter(void){counter=0;}
        void setPrice(void);
        void displayPrice(void);
};

void shop::setPrice(void){
    cout<<"Enter ID of your product of the product number::"<<counter+1<<endl;
    cin>>itemId[counter];
    cout<<"Enter the Price of Your item::";
    cin>>itemPrice[counter];

    counter++;
}

void shop::displayPrice(void){
    for(int i=0;i<counter;i++){
        cout<<"The price of Item with Id::"<<itemId[i]<<"is"<<itemPrice[i]<<endl;
    }
}

int main(){

    shop s1;
    s1.initCounter();
    s1.setPrice();
    s1.setPrice();
    s1.setPrice();
    s1.displayPrice();

    shop s2;
    s2.initCounter();
    s2.setPrice();
    s2.setPrice();
    s2.setPrice();
    s2.displayPrice();
    return 0;
}