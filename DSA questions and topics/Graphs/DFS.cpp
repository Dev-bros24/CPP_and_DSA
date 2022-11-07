#include<iostream>
#include<string.h>

using namespace std;

    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    int visited[7] = {0};

void DFSTraversal(int node)
{
    cout<<node;
    visited[node] = 1;
    for(int j = 0; j<7; j++)
    {
        if(a[node][j] == 1 && !visited[j])
        {
            DFSTraversal(j);
        }
    }
};

int main(){
    
    DFSTraversal(4);

    return 0;
}