#include<bits/stdc++.h>
using namespace std;

double multiplyNTimes(double value, int n)
{
    double val = 1.0;
    for(int i=0; i<n; i++)
    {
        val = val * value;
    }
    return val;
}

double nthrootofM(int n, int m)
{
    double low = 1.0;
    double high = double(m);
    double mindiff = 1e-7;

    cout<<"Abhishek: "<<mindiff<<endl;
    while(high - low > mindiff)
    {
        double mid = (high + low)/(2.0);
        cout<<"Abhi low: "<<low<<" high: "<<high<<" mid: "<<mid<<" mindiff: "<<mindiff<<endl;
        double midpown = multiplyNTimes(mid, n);
        cout<<"power: "<<midpown<<endl;
        if((double)m < midpown) high = mid;
        else low = mid;   
    }

    return (low+high)/2;
}

int main()
{
    int m, n;
    cout<<"Enter the numbers n and m: "<<endl;

    cin>>n>>m;

    double answer = nthrootofM(n, m);

    cout<<"Answer: "<<answer<<endl;

    return 0;
}