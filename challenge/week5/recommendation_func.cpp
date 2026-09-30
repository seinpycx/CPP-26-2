#include <iostream>
using namespace std;

const int NUM_USERS = 3;
const int NUM_ITEMS = 3;

// 1. 사용자 선호도를 입력 받는 함수
void initializePreferences(int preferences[NUM_USERS][NUM_ITEMS]){
    // 사용자별로 선호도 입력
    for (int i = 0; i < NUM_USERS; i++){
        cout << "사용자 " << (i + 1) << "의 선호도를 입력하세요 (";
        cout << NUM_ITEMS << "개의 항목에 대해): ";

        for (int j = 0; j < NUM_ITEMS; j++){
            cin >> preferences[i][j];
        }
    }
}

// 2. 사용자별 추천 항목을 찾고 출력하는 함수
void findRecommendedItems(int preferences[NUM_USERS][NUM_ITEMS]){
    // 각 사용자에 대한 추천 항목 찾기
    for (int i = 0; i < NUM_USERS; i++){
        int maxPreferenceIndex = 0;
         // 비교하여 더 큰 경우에만 값을 바꾸도록 설계함. 즉 값이 같아도 정상 작동
        for (int j = 1; j < NUM_ITEMS; j++){
            if (preferences[i][j] > preferences[i][maxPreferenceIndex]){
                maxPreferenceIndex = j;
            }
        }

        // 사용자에게 추천하는 항목 출력
        cout << "사용자 " << (i + 1) << "에게 추천하는 항목: ";
        cout << (maxPreferenceIndex + 1) << endl;
    }
}


int main(){
    int userPreferences[NUM_USERS][NUM_ITEMS];

    // 선호도를 초기화하고 사용자에게 추천할 항목 찾기
    initializePreferences(userPreferences);
    findRecommendedItems(userPreferences);

    return 0;
}