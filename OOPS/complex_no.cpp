#include <iostream>
#include <vector>
using namespace std;

class complex
{
    int a;
    int b;

public:
    void setData(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    void setDataBySum(complex o1, complex o2)
    {
        a = o1.a + o2.a;
        b = o2.b + o1.b;
    }
    void printNumber()
    {
        cout << "complex number is" << a << "+" << b << "i" << endl;
    }
};

int main()
{
    complex c1, c2, c3;

    c1.setData(1, 2);
    c1.printNumber();

    c2.setData(3, 4);
    c2.printNumber();

    c3.setDataBySum(c1,c2);
    c3.printNumber();
    return 0;
}