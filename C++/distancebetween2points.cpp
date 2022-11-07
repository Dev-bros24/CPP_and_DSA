#include<iostream>
#include<cmath>
using namespace std;

class Point{
    int x, y;
        public:
        Point(int a = 0, int b = 0){
            x = a;
            y = b;
        }
            void printPoint(void){
                cout<<"The point is: ("<<x<<", "<<y<<")"<<endl;
            }
    friend float distance(Point , Point);

};

float distance(Point p, Point q){
    float value = sqrt(pow((p.y-q.y),2) + pow((p.x-q.x),2));
    return value;
}

int main(){
    Point p1(1, 0), p2(70, 0);
    p1.printPoint();
    p2.printPoint();
    cout<<"The distance between these two points is: "<<distance(p1, p2);
    return 0;
}