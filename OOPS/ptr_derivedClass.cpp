#include<iostream>
using namespace std;

class Baseclass{
    public:
        int var_base;
        void display(){
            cout<<"Displaying Base class variable var_base"<<var_base<<endl;
        }

};

class Derived:public Baseclass{
    public:
        int var_derived;

        void display(){
            cout<<"Dispalying Base class variable var_base "<<var_base<<endl;
                cout<<"Dispalying Derived class variable var_derived "<<var_derived<<endl;
            
        }
};

int main(){
    Baseclass *base_class_pointer;
    Baseclass obj_base;
    Derived obj_derived;
    base_class_pointer=&obj_derived;
    base_class_pointer->var_base=34;
    base_class_pointer->display();
    base_class_pointer->var_base = 3400; 
    base_class_pointer->display();

    Derived * derived_class_pointer;
    derived_class_pointer = &obj_derived;
    derived_class_pointer->var_base = 9448;
    derived_class_pointer->var_derived = 98;
    derived_class_pointer->display();
    return 0;
}