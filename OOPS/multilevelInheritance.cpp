#include<iostream>
using namespace std;

class Student {
protected:
    int roll_number;

public:
    void set_roll(int);
    void get_roll(void);
};

void Student::set_roll(int a) {
    roll_number = a;
}

void Student::get_roll(void) {
    cout << "The roll number is " << roll_number << endl;
}

class Exam : public Student {
protected:
    float math;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam::set_marks(float a, float b) {
    math = a;
    physics = b;
}

void Exam::get_marks() {
    cout << "The marks obtained in maths are: " << math << endl;
    cout << "The marks obtained in physics are: " << physics << endl;
}

class Result : public Exam {
    float percentage;

public:
    void display_result() {
        get_roll();
        get_marks();
        percentage = (math + physics) / 2;
        cout << "Your result is " << percentage << "%" << endl;
        cout<<"roll"<<roll_number<<endl;
    }
};

int main() {
    Result M;
    M.set_roll(22);
    M.set_marks(94, 90);
    M.display_result();
    return 0;
}
