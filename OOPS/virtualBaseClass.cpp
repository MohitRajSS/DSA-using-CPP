#include<iostream>
using namespace std;

class Student{
    protected:
        int roll_no;
    public:
        void set_number(int a){
            roll_no=a;
        }
        void print_number(void){
            cout<<"your roll no is"<<roll_no<<endl;
        }
};

class Test:public virtual Student{
    protected:
        float maths,physics;
    
    public:
        void set_marks(float m1,float m2){
            maths=m1;
            physics=m2;
        }
        
        void print_marks(void){
             cout << "You result is here: "<<endl
                     << "Maths: "<< maths<<endl
                     << "Physics: "<< physics<<endl;
        }

};

class Sports:public virtual Student{
    protected:
        float score;
    public:
        void set_score(float sc){
            score=sc;
        }
        void print_score(void){
            cout<<"your score in sports is"<<score<<endl;
        }
};

class Result:public Test,public Sports{
    private:
        float total;
    public:
        void display(void){
            total=maths+physics+score;
            print_number();
            print_marks();
            print_score();
            cout<<"Your total score is"<<total<<endl;
        }
};

int main(){
    Result Mohit;
    Mohit.set_number(222);
    Mohit.set_marks(99,99);
    Mohit.set_score(9);
    Mohit.display();
    return 0;
}