#include "user.h"

User::User()
{
    hp = 20;
    itemCnt = 0;
}

void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;

    if (hp < 0)
    {
        hp = 0;
    }
}

void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

void User::IncreaseItemCnt()
{
    itemCnt++;
}

int User::GetHP() const
{
    return hp;
}

int User::GetItemCnt() const
{
    return itemCnt;
}

void User::doAttack()
{
    std::cout << "공격합니다" << std::endl;
}

void Magician::doAttack()
{
    std::cout << "마법 사용" << std::endl;
}

void Warrior::doAttack()
{
    std::cout << "베기 사용" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const User& user)
{
    out << "현재 HP는 " << user.GetHP()
        << "이고, 먹은 아이템은 총 "
        << user.GetItemCnt() << "개 입니다";

    return out;
}