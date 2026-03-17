#include <iostream>
using namespace std;

class point
{
    int x;
    int y;

public:
    point()
    {
        x = 0;
        y = 0;
    }
    point(int a)
    {
        x = a;
        y = 0;
    }
    point(int a, int b)
    {
        x = a;
        y = b;
    }

    void printNumber()
    {
        cout << "Your Number is" << x << "---" << y << endl;
    }
};

int main()
{

    point p1(1, 2);
    point p2(3);
    point p3;

    p1.printNumber();
    p2.printNumber();
    p3.printNumber();
    return 0;
}