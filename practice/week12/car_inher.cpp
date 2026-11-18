#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    int speed;

public:
    void SetSpeed(int s) {
        speed = s;
    }

    int GetSpeed() {
        return speed;
    }
};

class SportsCar : public Car {
    bool turbo = false;

public:
    void SetTurbo(bool newValue) {
        turbo = newValue;
    }

    bool GetTurbo() {
        return turbo;
    }

    void Print() {
        cout << "속도: " << speed << ", 터보: " << turbo << endl;
    }
};

int main()
{
    SportsCar c;

    c.SetSpeed(60);
    c.Print();

    c.SetTurbo(true);
    c.Print();

    c.SetSpeed(100);
    c.Print();

    c.SetTurbo(false);
    c.Print();

    return 0;
}