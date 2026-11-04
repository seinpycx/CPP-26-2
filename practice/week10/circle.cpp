#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle() { radius = 10; }
    ~Circle() {}

    void SetRadius(int radius) { this->radius = radius; }
    int GetRadius() const { return radius; }
};

int main()
{
    Circle* p = new Circle();

    const Circle* pConstObj = new Circle(); // 이거 때문에 고정되어 있어 주석처리된 코드가 실행 불가
    Circle* const pConstPtr = new Circle();

    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl << endl;

    p->SetRadius(30);

    // pConstObj->SetRadius(30); const 처리로 변경이 불가능하기 때문
    pConstPtr->SetRadius(30);

    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl;

    delete p;
    delete pConstObj;
    delete pConstPtr;

    return 0;
}