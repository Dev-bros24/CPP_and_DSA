#include <iostream>
using namespace std;

/*
If we derive two classes test, sports from Student and then derive one Result class
from these two classes, then the inheritable data members in Student will be inherited
two times in Result(i.e. one from Test and one from Sports). To resolve this ambuiguity
we make Student a virtual base class by adding virtual keyword in Test and sports while
Deriving these.
*/

class Student
{
protected:
    int roll_no;

public:
    void set_Rollno(int a)
    {
        roll_no = a;
    }
    void print_number(void)
    {
        cout << "Your roll no is: " << roll_no << endl;
    }
};

class Test : virtual public Student // Both virtual public and public virtual work
{
protected:
    float maths, physics;

public:
    void set_Marks(float m1, float m2)
    {
        maths = m1;
        physics = m2;
    }
    void print_marks(void)
    {
        cout << "Your marks are: " << endl
             << "Maths: " << maths << endl
             << "Physics: " << physics << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_Score(float sc)
    {
        score = sc;
    }
    void print_Score(void)
    {
        cout << "Your PT score is: " << score << endl;
    }
};

class Result : public Test, public Sports
{
private:
    float total;

public:
    void display(void)
    {
        total = maths + physics + score;
        print_number();
        print_marks();
        print_Score();
        cout<<"Your Total score is: "<<total<<endl;
    }
};

int main()
{
    Result abhi;
    abhi.set_Rollno(1406);
    abhi.set_Marks(98.9, 99.5);
    abhi.set_Score(9);
    abhi.display();

    return 0;
}