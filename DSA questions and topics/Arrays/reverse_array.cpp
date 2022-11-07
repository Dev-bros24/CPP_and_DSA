#include<bits/stdc++.h>
using namespace std;

void reverse_vector(vector<int> :: iterator it_begin, vector<int> :: iterator it_end)
{
    int size = it_end - it_begin;
    int itr = (size/2) - 1;
    it_end = it_end - 1;
    for(int i=0; i<=itr; i++)
    {
        int temp = *(it_begin);
        *(it_begin) = *(it_end);
        *(it_end) = temp;
        it_begin = it_begin + 1;
        it_end = it_end - 1;
    }
}

int main(){
    
    vector<int> vec = {1, 5, 9, 4, 3, 6};

    cout<<"Input vector: "<<endl;
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }

    reverse_vector(vec.begin(), vec.end());


    cout<<"\nOutput vector: "<<endl;
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }

    return 0;
}