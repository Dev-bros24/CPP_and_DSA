#include<iostream>
#include<list>
// #include<forward_list> // forward list is singly linked list
#include<algorithm>
using namespace std;

void display(list<int> &lst){
    list<int> :: iterator it;
    for(it = lst.begin(); it!=lst.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main(){
    list<int> list1; // List of 0 length
    list1.push_back(14);
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(8);
    list1.push_back(2);

    // display(list1);   
    // list1.pop_back();
    // list1.pop_front();
    // list1.remove(8);
    display(list1);
    // list1.reverse();
    // display(list1);

    list<int> list2(4);  // Empty list of size 4
    list<int> :: iterator itr = list2.begin();
    *itr = 5;
    itr++;
    *itr = 6;
    itr++;
    *itr = 17;
    itr++;
    *itr = 18;
    display(list2);
    // list1.sort();
    // sort(list1.begin(), list1.end()); --> does not work in lists
    // display(list1);
    list1.sort();
    // display(list1);
    // list2.sort();
    // display(list2);
    list1.merge(list2);  // If list 1 is sorted then the list after merging will also be sorted
    display(list1);

    return 0;
}