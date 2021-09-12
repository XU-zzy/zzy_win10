#include<iostream>
using namespace std;

class Point{
    public:
    Point(int xx=0,int yy=0){
        X=xx;
        Y=yy;
    }
    Point(Point &p){
        X=p.X;
        Y=p.Y;
        cout<<"*";
    }
    private:
    int X,Y;
};
class Line{
    public:
    Line(Point xp1,Point xp2):p1(xp1),p2(xp2){}
    private:
    Point p1,p2;
};
int main(){
    Point myp1(1,1),myp2(4,5);
    Line line(myp1,myp2);
    return 0;
}