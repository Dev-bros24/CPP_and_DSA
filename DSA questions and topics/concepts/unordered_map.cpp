#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, pair<int, int>> mp;

    mp[4] = {5, 7};

    unordered_map<int, pair<int, int>> :: iterator it = mp.find(4);
    // auto it = mp.find(4);

    cout<<"Abhishek first: "<<it->first<<" second: "<<it->second.first<<" third: "<<it->second.second; 

    return 0;
}