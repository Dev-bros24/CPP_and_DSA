#include<iostream>
using namespace std;

// float funcAverage(int a, int b){
//     float avg = (a+b)/2.0;
//     return avg;
// }

// float funcAverage2(int a, float b){
//     float avg = (a+b)/2.0;
//     return avg;
// }
template<class T>
void swapp(T &m, T &n){
    T temp;
    temp = m;
    m = n;
    n = temp;
}

template<class T1, class T2>
float funcAverage(T1 a, T2 b){
    float avg = (a+b)/2.0;
    return avg;
}

int main(){
    float ans = funcAverage(3, 4.4);
    printf("The ans is: %.3f \n", ans);
    // cout<<ans<<endl;

    int x = 5, y = 8;

    swapp(x, y);
    cout<<x<<endl<<y;

    return 0;
}