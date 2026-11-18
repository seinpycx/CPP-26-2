#include <iostream>
#include <string>
using namespace std;

class Person {
    string name;

protected:
    string address;

public:
    void SetName(string name) {
        this->name = name;
    }
};

class Student : Person {
public:
    void SetAddress(string add) {
        address = add;
    }

    string GetAddress() {
        return address;
    }

    void SetName(string name) {
        Person::SetName(name);
    }
};

int main() {
    Student obj;

    obj.SetName("미수");
    obj.SetAddress("서울시 종로구 1번지");

    cout << obj.GetAddress() << endl;

    return 0;
}