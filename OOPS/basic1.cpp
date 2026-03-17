#include<iostream>
using namespace std;

class Employee
{
    private:
        int a,b,c;

    public:
        int d,e;
        void setData(int a,int b,int c);
        void getData(){
            cout<<"The value of a is"<<a<<endl;
            cout<<"The value of b is"<<b<<endl;
            cout<<"The value of c is"<<c<<endl;
        }
};

void Employee::setData(int a1,int b1,int c1){
    a=a1;
    b=b1;
    c=c1;
}

int main(){
    Employee Mohit;
    Mohit.setData(1,2,4);
    Mohit.getData();
    return 0;
}