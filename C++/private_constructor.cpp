#include<iostream>
#include<cstring>
using namespace std;

/*
    We can call the private constructor from inside the class only. That's why
    we create the object inside the class in a static member function as static
    members can be called from outside the class.
    Static members belong to the class and not to the object.
    Also, we create the object dynamically as whenever something is created
    dynamically using the new keyword it doesn't destroy outside the scope(here
    it's of function) as well till the program ends or we destroy it using 
    delete keyword.
*/


// Since there is only 1 object that can be created of the below class, 
// it is a Singleton class.

class Admin{
    private:
    char name[20];
    char pass[20];
    static int objectCount;

    Admin(){
        strcpy(name, "Abhishek");
        strcpy(pass, "Chess123");
    }

    public:
    void showData(){
        cout<<"Name is: "<<name<<endl;
        cout<<"Pass is: "<<pass<<endl;
    }

    static Admin* getInstance(){
        cout<<"Obj: "<<objectCount<<endl;
        if(objectCount == 0)
        {
            Admin* obj = new Admin();   // Also we can create a static object and store the return value in a reference object in main() ---> i.e. we can write static (Admin obj) here and return type will be (Admin&) and in main we can write Admin &catchobj = Admin::getInstance()
            objectCount++;
            return obj;
        }
        else return NULL;
    }
};

int Admin :: objectCount = 0;

int main(){
    
    // Admin ad1;
    // ad1.showData();

// We can't create an object but we can create a pointer outside the class even if the 
// constructor is private
    Admin* adminPointer = Admin :: getInstance(); 
    if(adminPointer) adminPointer->showData();
    else cout<<"No more Admins can be created"<<endl;

    Admin* p = Admin :: getInstance();
    if(p) p->showData();
    else cout<<"No more Admins can be created"<<endl;

    return 0;
}