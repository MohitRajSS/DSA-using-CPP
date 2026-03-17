#include<iostream>
using namespace std;

class Base1{
    public:
        void greet(){
            cout<<"how are u?"<<endl;
        }
};

class Base2{
    public:
        void greet(){
            cout<<"Kaisa HOO??"<<endl;
        }
};

class Derived:public Base1,public Base2{
    int a;
    public:
        void greet(){
            Base2::greet();
        }
};

int main(){
  // Ambibuity 1
     Base1 base1obj;
     Base2 base2obj;
     base1obj.greet();
     base2obj.greet();
     Derived d;
     d.greet();

    return 0;
}
