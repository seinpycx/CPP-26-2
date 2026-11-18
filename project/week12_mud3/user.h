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

    virtual void doAttack();
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