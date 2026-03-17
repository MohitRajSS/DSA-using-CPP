#include<iostream>
using namespace std;

class Base1{
    protected:
        int data1;
    
    public:
        void set_base1(int a){
            data1=a;
        }
};

class Base2{
    protected:
        int data2;

    public:
        void set_base2(int a){
            data2=a;
        }
};

class Derived:public Base1,public Base2{
    public:
        void show(){
            cout << "The value of Base1 is " << data1<<endl;
            cout << "The value of Base2 is " << data2<<endl;
            cout<<"sum is"<<data1+data2<<endl;
        }
};

int main(){
    Derived Mohit;
    Mohit.set_base1(12);
    Mohit.set_base2(10);
    Mohit.show();
    return 0;
}
