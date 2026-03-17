#include<iostream>
using namespace std;

class Base1{
    int data1;
    public:
        Base1(int i){
            data1=i;
            cout<<"Base1 Ka Constructor called"<<endl;
        }
        void printDataBase1(void){
            cout<<"The value in base 1 is::"<<data1<<endl;
        }
};

class Base2{
    int data2;
        public:
            Base2(int b){
                data2=b;
                cout << "Base2 ka constructor called" << endl;
            }
            void printDataBase2(void){
                cout<<"The value in base 2 is::"<<data2<<endl;
            }
};

class Derived:public Base1,public Base2{
    int derived1,derived2;
    public:
        Derived(int a,int b,int c,int d):Base1(a),Base2(b){
            derived1=c;
            derived2=d;
            cout<<"derived class Constructor called"<<endl;
        }
        void printDataDerived(void){
            cout<<"The value of derive1 is::"<<derived1<<endl;
            cout<<"the value of derived2 is::"<<derived2<<endl;
        }
};

int main(){
    Derived Mohit(1,2,3,4);
    Mohit.printDataBase1();
    Mohit.printDataBase2();
    Mohit.printDataDerived();
    return 0;
}