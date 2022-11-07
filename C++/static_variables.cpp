#include <iostream>
using namespace std;

// If we want a variable that does store values and preserves for each object like when we have
//  to count no of employees in this example. We use static variables.
// Static variables are basically attached to entire class and not each object. It's also known
// as class variable. It's not a property of an object it's a property of class.

class Employee
{
    int id;
    static int count; // Static variable gets initialised by zero by default. We can't initialize the static variables here.
public:
    void setData(void)
    {
        cout << "Enter the id" << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The id of this employee is: " << id << "and this is employee number: " << count << endl;
    }

    static void getCount(void) // Static functions like this can only access other static functions or static data members only. Other methods can access static variables also. Static functions do not work like normal functions that it does not just use the variables inside it and forgets, it retains them as they are static variables.
    {
        cout << " the value of count is : "<<count<<endl;
    }
};

// Count is the static data member oftu class Employee
int Employee ::count; // We can initialize the static variables here

int main()
{
    Employee abhi, some, one;
    // abhi.id = 1;
    // abhi.count = 1; //cannot do this as id and count are private
    abhi.setData();
    abhi.getData();
    Employee :: getCount();

    some.setData();
    some.getData();
    Employee :: getCount();

    one.setData();
    one.getData();
    Employee ::  getCount();

    return 0;
}