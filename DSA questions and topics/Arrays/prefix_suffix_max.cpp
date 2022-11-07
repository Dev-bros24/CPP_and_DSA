#include<bits/stdc++.h>
using namespace std;

int main()
{
        vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};

        int size = height.size();
        vector<int> prefix(size,0);
        vector<int> suffix(size,0);
        
        if(height[0]>0)
        {
            prefix[0] = height[0];
        }
        if(height[size-1]>0)
        {
            suffix[size-1] = height[size-1];
        }

        for(int i=1; i<size; i++)
        {
            if(height[i]>prefix[i-1])
            {
                prefix[i] = height[i];
            }
            else
            {
                prefix[i] = prefix[i-1];
            }
        }

        cout<<"Abhishek prefix: "<<endl;
        for(int z=0; z<prefix.size(); z++)
        {
            cout<<prefix[z]<<" ";
        }


        for(int j=size-2; j>=0; j--)
        {
            if(height[j]>suffix[j+1])
            {
                suffix[j] = height[j];
            }
            else
            {
                suffix[j] = suffix[j+1];
            }
        }

        cout<<"\nAbhishek suffix: "<<endl;
        for(int z=0; z<suffix.size(); z++)
        {
            cout<<suffix[z]<<" ";
        }

return 0;
}
