#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int k;
		int q;
		cin>>k>>q;
		long long a[k];
		long long b[q];
		long long apmax[k];
		long long apsum[k];
		
		for(int i=0; i<k ;i++)
		{
			cin>>a[i];
			if(i==0)
			{
				apsum[0] = a[0];
				apmax[0] = a[0];
			}
			
			if(i>0)
			apsum[i] = a[i] + apsum[i-1];

			if(i>0)
			{
				if(apmax[i-1] < a[i])
				{
					apmax[i] = a[i];
				}
				else{
					apmax[i] = apmax[i-1];
				}
			}

		}


		for(int j=0; j<q; j++)
		{
			cin>>b[j];
		}


		for(int i=0; i<q; i++)
		{
			int index = upper_bound(apmax, apmax+k, b[i]) - apmax;
			if(index <= 0)
			{
				cout<<0<<" ";
			}
			else{
			cout<<apsum[index-1]<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}