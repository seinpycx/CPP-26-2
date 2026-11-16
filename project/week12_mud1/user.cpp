#include "user.h"

User::User()
{
    hp = 20; // 기본 설정 20으로 설정
}

void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;

    if (hp < 0) //HP가 0보다 작아지면 0으로 치고 그냥 게임 종료
    {
        hp = 0;
    }
}

void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}

int User::GetHP()
{
    return hp;
}