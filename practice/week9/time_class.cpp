#include <iostream>
using namespace std;

class Time {
    public:
    int hour;
    int minute;

    Time(){

    }
    Time(int h, int m){
        hour = h;
        minute = m;
    }
    void print(){
        cout << hour << ":" << minute << endl;
    }
};

int main(){
    Time a;
    Time b(10,25);
    b.print();
    Time c{12,25};
    c.print();
    Time d = {13, 25};
    d.print();

    return 0;
}