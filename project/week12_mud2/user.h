#include <iostream>

class User
{
private:
    int hp;
    int itemCnt;

public:
    User();

    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItemCnt();

    int GetHP() const;
    int GetItemCnt() const;
};

// 출력 연산자 중복 정의
std::ostream& operator<<(std::ostream& out, const User& user);