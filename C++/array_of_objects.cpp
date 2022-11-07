#include<iostream>
using namespace std;

class ShopItem{
    int id;
    float price;
    public:
    void setData(int a, float b)
    {
        id = a;
        price = b;
    }
    void getData()
    {
        cout<<"The id of the item is: "<<id<<endl;
        cout<<"The price of the item is: "<<price<<endl;
    }
};


int main(){
    ShopItem *ptr = new ShopItem[4];

    ShopItem *ptrtemp = ptr;

    // ShopItem arr[4];

    int p;
    float q;

    for(int i=0; i<4; i++)
    {
        cout<<"Enter the id and price of item "<<i+1<<endl;
        cin>>p>>q;
        ptr->setData(p, q);
        ptr++;
    }

    for(int i=0; i<4; i++)
    {
        ptrtemp->getData();
        ptrtemp++;
    }

    return 0;
}