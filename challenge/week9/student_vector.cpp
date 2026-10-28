#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> scores;
    int score;
    int sum = 0;

    while (1) {
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> score;

        if (score == -1)
            break;

        scores.push_back(score);
    }

    for (int s : scores) {
        sum += s;
    }

    if (scores.size() > 0) {
        double average = (double)sum / scores.size();
        cout << "성적 평균 = " << average << "점" << endl;
    }

    return 0;
}