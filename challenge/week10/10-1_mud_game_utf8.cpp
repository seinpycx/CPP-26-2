#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

// 추가 계획 1: 게임 시작 HP
int userHP = 20;

// 0: 빈 공간, 1: 무기/갑옷, 2: 적, 3: 포션, 4: 목적지
int map[mapY][mapX] = {
	{0, 1, 2, 0, 4},
	{1, 0, 0, 2, 0},
	{0, 0, 0, 0, 0},
	{0, 2, 3, 0, 0},
	{3, 0, 0, 0, 2}};

// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);

// 추가 계획 5: 현재 칸의 상태를 확인하는 함수
void checkState(int map[][mapX], int user_x, int user_y);

// 메인 함수
int main()
{
	// 유저의 위치
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호

	// 게임 시작
	while (1)
	{
		string user_input = "";

		// 추가 계획 3: 명령어 입력을 받을 때마다 HP 표시
		cout << "\n현재 HP: " << userHP << endl;

		cout << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 종료): ";
		cin >> user_input;

		if (user_input == "상")
		{
			// 위로 한 칸 이동
			user_y -= 1;

			// 기능 계획 2: 지도 밖으로 나가는 경우 원래 위치로 복귀
			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false)
			{
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y += 1;
				continue;
			}

			// 추가 계획 2: 이동할 때마다 HP 1 감소
			userHP--;
			cout << "위로 한 칸 올라갑니다." << endl;

			// 추가 계획 5: 아이템, 적, 포션 상태 확인
			checkState(map, user_x, user_y);

			// 추가 계획 4: HP가 0 이하이면 실패 후 종료
			if (userHP <= 0)
			{
				cout << "실패" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}

			// 이동 후 지도 출력
			displayMap(map, user_x, user_y);

			// 기능 계획 3: 목적지 도착 시 성공 후 종료
			if (checkGoal(map, user_x, user_y))
			{
				cout << "성공" << endl;
				cout << "게임을 종료합니다." << endl;
				break;
			}
		}
		else if (user_input == "하")
		{
			// 아래로 한 칸 이동
			user_y += 1;

			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false)
			{
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_y -= 1;
				continue;
			}

			userHP--;
			cout << "아래로 한 칸 내려갑니다." << endl;

			checkState(map, user_x, user_y);

			if (userHP <= 0)
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
		else if (user_input == "좌")
		{
			// 왼쪽으로 한 칸 이동
			user_x -= 1;

			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false)
			{
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x += 1;
				continue;
			}

			userHP--;
			cout << "왼쪽으로 이동합니다." << endl;

			checkState(map, user_x, user_y);

			if (userHP <= 0)
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
		else if (user_input == "우")
		{
			// 오른쪽으로 한 칸 이동
			user_x += 1;

			bool inMap = checkXY(user_x, mapX, user_y, mapY);
			if (inMap == false)
			{
				cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
				user_x -= 1;
				continue;
			}

			userHP--;
			cout << "오른쪽으로 이동합니다." << endl;

			checkState(map, user_x, user_y);

			if (userHP <= 0)
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
			// 기능 계획 1: 전체 지도와 현재 위치 출력
			displayMap(map, user_x, user_y);
		}
		else if (user_input == "종료")
		{
			cout << "종료합니다." << endl;
			break;
		}
		else
		{
			// 기능 계획 1: 잘못된 입력이면 오류 메시지 출력
			cout << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
		}
	}

	return 0;
}

// 지도와 사용자 위치 출력
void displayMap(int map[][mapX], int user_x, int user_y){

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
				int posState = map[i][j];

				switch (posState)
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
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY)
	{
		checkFlag = true;
	}

	return checkFlag;
}

// 유저의 위치가 목적지인지 확인
bool checkGoal(int map[][mapX], int user_x, int user_y)
{
	if (map[user_y][user_x] == 4)
	{
		return true;
	}

	return false;
}

// 추가 계획 5: 현재 칸의 아이템, 적, 포션 상태 확인
void checkState(int map[][mapX], int user_x, int user_y)
{
	int posState = map[user_y][user_x];

	if (posState == 1)
	{
		cout << "아이템이 있습니다." << endl;
	}
	else if (posState == 2)
	{
		// 적은 지도에서 사라지지 않음
		userHP -= 2;
		cout << "적이 있습니다." << endl;
		cout << "적을 만나 HP가 2 감소했습니다." << endl;
	}
	else if (posState == 3)
	{
		// 포션은 지도에서 사라지지 않음
		userHP += 2;
		cout << "포션이 있습니다." << endl;
		cout << "포션을 만나 HP가 2 증가했습니다." << endl;
	}
}