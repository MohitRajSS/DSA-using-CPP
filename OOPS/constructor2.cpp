#include <iostream>
#include<math.h>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void display()
    {
        cout << "Pt is" << "(" << x << "," << y << ")" << endl;
    }
friend float distance(Point,Point);
};

float distance(Point object1,Point object2){
    int a=pow(object2.x-object1.x,2);
    int b=pow(object2.y-object1.y,2);
    float result=sqrt(a+b);
    return result;
}

int main()
{
    Point p(1, 1);
    Point q(2, 2);
    p.display();
    q.display();
    cout<<"The distance Between the Points are"<<distance(p,q);
    return 0;
}