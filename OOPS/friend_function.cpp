#include<iostream>
#include<vector>

using namespace std;

class complex{
    int a,b;
    friend complex sumComplex(complex o1,complex o2);
    public:
        void setData(int a1,int b1){
            a=a1;
            b=b1;
        }
        void printData(void){
            cout<<"complex No:"<<a<<"+"<<b<<"i"<<endl;
        }
};

complex sumComplex(complex object1,complex object2){
    complex O3;
    O3.setData((object1.a+object2.a),(object1.b+object2.b));
    return O3;
}

int main(){
    complex c1, c2, sum;
    c1.setData(1, 4);
    c1.printData();

    c2.setData(5, 8);
    c2.printData();

    sum = sumComplex(c1, c2);
    sum.printData();

    return 0;
}