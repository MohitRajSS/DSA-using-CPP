#include<iostream>
using namespace std;

class Employee{
    int id;
    static int count;

    public:
        void setData(void){
            cout<<"Enter the ID"<<endl;
            cin>>id;
            count++;
        }
        void getData(void){
            cout<<"the id of the employee is"<<id<<"and this is employee number"<<count<<endl;
        }

        static void getCount(void){
            cout<<"The value of count is"<<count<<endl;
        }
};

int Employee::count=1000;

int main(){
    Employee Mohit,Sid,Medha;
    Mohit.setData();
    Mohit.getData();

    
    Medha.setData();
    Medha.getData();

    
    Sid.setData();
    Sid.getData();
    return 0;
}