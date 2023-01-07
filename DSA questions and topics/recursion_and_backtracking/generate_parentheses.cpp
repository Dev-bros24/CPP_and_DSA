#include<iostream>
#include<vector>
using namespace std;

// Recursion
void genParen(int cp, int op, const int &n, string &temp, vector<string> &ans){
    cout<<"cp: "<<cp<<" op: "<<op<<" n: "<<n<<" temp: "<<temp<<endl;
    if(cp == n && op == n){
        ans.push_back(temp);
        return;
    }

    if(op<n){
        string temp1 = temp;
        temp1.push_back('(');
        genParen(cp, op+1, n, temp1, ans);
    }
            
    if(op>cp){
        temp.push_back(')');
        genParen(cp+1, op, n, temp, ans);
    }
    return;
}

// Backtracking --> can't pass temp as reference, only disadvantage
void genParenBackTrack(int cp, int op, const int &n, string temp, vector<string> &ans){
    cout<<"cp: "<<cp<<" op: "<<op<<" n: "<<n<<" temp: "<<temp<<endl;
    if(cp == n && op == n){
        ans.push_back(temp);
        return;
    }

    if(op<n){
        temp.push_back('(');
        op++;
        genParenBackTrack(cp, op, n, temp, ans);
        temp.pop_back();
        op--;
    }
    

    if(op>cp){
        temp.push_back(')');
        cp++;
        genParenBackTrack(cp, op, n, temp, ans);
    }

    return;
}

vector<string> generateParenthesis(int n) {
    int cp = 0, op = 0;
    string temp = "";
    vector<string> ans;
    // genParen(cp, op, n, temp, ans); 
    genParenBackTrack(cp, op, n, temp, ans); 

    return ans;
}

int main(){
    
    int n = 2;
    vector<string> ans = generateParenthesis(n);

    cout<<"Answer is below: "<<endl;
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].length(); j++){
            cout<<ans[i][j];
        }
        cout<<"  ";
    }

    return 0;
}