class User
{
private:
    int hp;

public:
    User();

    void DecreaseHP(int dec_hp); // 괄호 안에 HP 감소량
    void IncreaseHP(int inc_hp); // 괄호 안에 HP 증가량
    int GetHP(); // HP값 반환
};