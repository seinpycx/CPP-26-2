#include <iostream>
#include <string>
#include <vector>
#include "user.h"

using namespace std;

// 0: 빈 공간, 1: 아이템, 2: 적, 3: 포션, 4: 목적지
vector<vector<int>> map = {
    {0, 1, 2, 0, 4},
    {1, 0, 0, 2, 0},
    {0, 0, 0, 0, 0},
    {0, 2, 3, 0, 0},
    {3, 0, 0, 0, 2}
};

// 사용자 정의 함수 선언
bool checkXY(int user_x, int user_y, const vector<vector<int>>& map);
void displayMap(const vector<vector<int>>& map, int user_x, int user_y);
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y);
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user);
bool CheckUser(User user);

int main()
{
    User user;

    int user_x = 0;
    int user_y = 0;

    while (true)
    {
        string user_input;

        cout << "\n현재 HP: " << user.GetHP() << endl;
        cout << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 종료): ";
        cin >> user_input;

        bool isMove = false;
        string moveMessage;

        if (user_input == "상")
        {
            user_y--;
            isMove = true;
            moveMessage = "위로 한 칸 올라갑니다.";
        }
        else if (user_input == "하")
        {
            user_y++;
            isMove = true;
            moveMessage = "아래로 한 칸 내려갑니다.";
        }
        else if (user_input == "좌")
        {
            user_x--;
            isMove = true;
            moveMessage = "왼쪽으로 이동합니다.";
        }
        else if (user_input == "우")
        {
            user_x++;
            isMove = true;
            moveMessage = "오른쪽으로 이동합니다.";
        }

        if (isMove)
        {
            // 맵 밖이면 이동 전 위치로 복귀
            if (!checkXY(user_x, user_y, map))
            {
                cout << "맵을 벗어났습니다. 다시 입력해 주세요." << endl;

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

            cout << moveMessage << endl;

            // 이동할 때마다 HP 1 감소
            user.DecreaseHP(1);

            if (!CheckUser(user))
            {
                cout << "실패" << endl;
                cout << "게임을 종료합니다." << endl;
                break;
            }

            // 아이템, 적, 포션 처리
            checkState(map, user_x, user_y, user);

            if (!CheckUser(user))
            {
                cout << "실패" << endl;
                cout << "게임을 종료합니다." << endl;
                break;
            }

            // 이동 후 지도 출력
            displayMap(map, user_x, user_y);

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
        else if (user_input == "정보" || user_input == "info")
        {
            // 출력 연산자 중복 정의로 사용자 정보 출력
            cout << user << endl;
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

// 이동할 위치가 맵 안인지 확인
bool checkXY(int user_x, int user_y, const vector<vector<int>>& map)
{
    if (user_y < 0 || user_y >= static_cast<int>(map.size()))
    {
        return false;
    }

    if (user_x < 0 || user_x >= static_cast<int>(map[user_y].size()))
    {
        return false;
    }

    return true;
}

// 지도와 사용자 위치 출력
void displayMap(const vector<vector<int>>& map, int user_x, int user_y)
{
    cout << "\n===== 지도 =====" << endl;

    for (int y = 0; y < static_cast<int>(map.size()); y++)
    {
        for (int x = 0; x < static_cast<int>(map[y].size()); x++)
        {
            if (x == user_x && y == user_y)
            {
                cout << " USER |";
            }
            else
            {
                switch (map[y][x])
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

// 현재 위치가 목적지인지 확인
bool checkGoal(const vector<vector<int>>& map, int user_x, int user_y)
{
    return map[user_y][user_x] == 4;
}

// 현재 칸의 아이템, 적, 포션 처리
void checkState(vector<vector<int>>& map, int user_x, int user_y, User& user)
{
    int posState = map[user_y][user_x];

    if (posState == 1)
    {
        cout << "아이템이 있습니다." << endl;

        user.IncreaseItemCnt();
        map[user_y][user_x] = 0;

        cout << "아이템을 획득했습니다." << endl;
    }
    else if (posState == 2)
    {
        // 적은 지도에 남아 있음
        user.DecreaseHP(2);
        cout << "적이 있습니다." << endl;
        cout << "적을 만나 HP가 2 감소했습니다." << endl;
    }
    else if (posState == 3)
    {
        // 포션은 지도에 남아 있음
        user.IncreaseHP(2);
        cout << "포션이 있습니다." << endl;
        cout << "포션을 만나 HP가 2 증가했습니다." << endl;
    }
}

// HP가 0이면 false 반환
bool CheckUser(User user)
{
    return user.GetHP() > 0;
}