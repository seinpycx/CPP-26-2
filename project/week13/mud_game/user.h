#include <iostream>

class User
{
private:
    int hp;
    int itemCnt;

public:
    User();
    virtual ~User();

    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void IncreaseItemCnt();

    int GetHP() const;
    int GetItemCnt() const;

    // User를 추상 클래스로 만드는 순수 가상 함수
    virtual void doAttack() = 0;
};

class Magician : public User
{
public:
    void doAttack() override;
};

class Warrior : public User
{
public:
    void doAttack() override;
};

std::ostream& operator<<(std::ostream& out, const User& user);