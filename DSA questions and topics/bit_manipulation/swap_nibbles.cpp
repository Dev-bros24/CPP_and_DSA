#include <iostream>
using namespace std;

int swapNibbles(int N)
{
    uint8_t n = N;

    uint8_t ls = N << 4;
    uint8_t rs = N >> 4;

    return ls | rs;
}

int main()
{
    //    int ch = 0xAB;
    char ch = 100;
    cout << ch << endl;
    char res = swapNibbles(ch);
    cout << res;

    return 0;
}