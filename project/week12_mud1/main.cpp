#include <iostream>
#include <string>
#include "user.h"
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 0: 빈 공간, 1: 아이템, 2: 적, 3: 포션, 4: 목적지
int map[mapY][mapX] = {
    {0, 1, 2, 0, 4},
    {1, 0, 0, 2, 0},
    {0, 0, 0, 0, 0},
    {0, 2, 3, 0, 0},
    {3, 0, 0, 0, 2}
};

// 사용자 정의 함수. CheckUser 추가
bool checkXY(int user_x, int map_width, int user_y, int map_height);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
void checkState(int map[][mapX], int user_x, int user_y, User& user);
bool CheckUser(User user);

int main()
{
    // User 객체 하나 생성
    User user;

    int user_x = 0;
    int user_y = 0;

    while (true)
    {
        string user_input;

        // GetHP() 함수로 현재 HP 출력
        cout << "\n현재 HP: " << user.GetHP() << endl;
        cout << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 종료): ";
        cin >> user_input;

        bool isMove = false;

        // 입력에 따라 유저 위치 이동
        if (user_input == "상")
        {
            user_y--;
            isMove = true;
            cout << "위로 한 칸 올라갑니다." << endl;
        }
        else if (user_input == "하")
        {
            user_y++;
            isMove = true;
            cout << "아래로 한 칸 내려갑니다." << endl;
        }
        else if (user_input == "좌")
        {
            user_x--;
            isMove = true;
            cout << "왼쪽으로 이동합니다." << endl;
        }
        else if (user_input == "우")
        {
            user_x++;
            isMove = true;
            cout << "오른쪽으로 이동합니다." << endl;
        }

        if (isMove)
        {
            // 맵 밖으로 나가면 원래 위치로 복귀
            if (!checkXY(user_x, mapX, user_y, mapY))
            {
                cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;

                if (user_input == "상")
                    user_y++;
                else if (user_input == "하")
                    user_y--;
                else if (user_input == "좌")
                    user_x++;
                else if (user_input == "우")
                    user_x--;

                continue;
            }

            // 이동할 때마다 HP 1 감소
            user.DecreaseHP(1);

            // HP가 0이면 실패하고 종료
            if (!CheckUser(user))
            {
                cout << "실패" << endl;
                cout << "게임을 종료합니다." << endl;
                break;
            }

            // 이동한 칸의 아이템, 적, 포션 확인
            checkState(map, user_x, user_y, user);

            // 적을 만난 뒤 HP가 0이 되었는지 확인
            if (!CheckUser(user))
            {
                cout << "실패" << endl;
                cout << "게임을 종료합니다." << endl;
                break;
            }

            // 이동 후 지도 출력
            displayMap(map, user_x, user_y);

            // 목적지 도착 여부 확인
            if (checkGoal(map, user_x, user_y))
            {
                cout << "성공" << endl;
                cout << "게임을 종료합니다." << endl;
                break;
            }
        }
        else if (user_input == "지도")
        {
            displayMap(map, user_x, user_y);
        }
        else if (user_input == "종료")
        {
            cout << "종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
        }
    }

    return 0;
}

// 지도와 사용자 위치 출력
void displayMap(int map[][mapX], int user_x, int user_y)
{
    cout << "\n========== 지도 ==========" << endl;

    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == user_y && j == user_x)
            {
                cout << " USER |";
            }
            else
            {
                switch (map[i][j])
                {
                case 0:
                    cout << "      |";
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |";
                    break;
                case 3:
                    cout << " 포션 |";
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }

        cout << endl;
        cout << " -------------------------------- " << endl;
    }

    cout << "현재 위치: (" << user_x << ", " << user_y << ")" << endl;
}

// 이동하려는 위치가 맵 안인지 확인
bool checkXY(int user_x, int map_width, int user_y, int map_height)
{
    return user_x >= 0 && user_x < map_width &&
           user_y >= 0 && user_y < map_height;
}

// 현재 위치가 목적지인지 확인
bool checkGoal(int map[][mapX], int user_x, int user_y)
{
    return map[user_y][user_x] == 4;
}

// 현재 칸의 아이템, 적, 포션 상태 확인
void checkState(int map[][mapX], int user_x, int user_y, User& user)
{
    int posState = map[user_y][user_x];

    if (posState == 1)
    {
        cout << "아이템이 있습니다." << endl;
    }
    else if (posState == 2)
    {
        // 적은 지도에서 사라지지 않음
        user.DecreaseHP(2);
        cout << "적이 있습니다." << endl;
        cout << "적을 만나 HP가 2 감소했습니다." << endl;
    }
    else if (posState == 3)
    {
        // 포션은 지도에서 사라지지 않음
        user.IncreaseHP(2);
        cout << "포션이 있습니다." << endl;
        cout << "포션을 만나 HP가 2 증가했습니다." << endl;
    }
}

// HP가 0이면 false, 0보다 크면 true 반환
bool CheckUser(User user)
{
    if (user.GetHP() == 0)
    {
        return false;
    }

    return true;
}