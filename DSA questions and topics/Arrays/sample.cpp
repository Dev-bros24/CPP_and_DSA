#include<iostream>
#include<vector>
using namespace std;
int main(){
    cout<<"Program started"<<endl;
    // vector<int> temp;
    // cout<<"Enter 5 values:"<<endl;
    for(int j=0; j<2; j++)
    {
        vector<int> temp;
        cout<<"\nAbhishek: "<<j+1<<"th time enter 5 values"<<endl;
    for (int i=0 ; i<5; i++)
    {
        int value;
        cin>>value;
        temp.push_back(value);
    }
    cout<<"Abhishek the start and end values are: "<<*(temp.begin())<<"  "<<*(temp.end()-1)<<endl;
    for (int p=0 ; p<temp.size(); p++)
    {
        cout<<temp[p]<<" "; 
    }
    }

    vector<int> temp;

    


    return 0;
}