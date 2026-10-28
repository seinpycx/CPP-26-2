#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
    string name;
    double score;

public:
    Movie(string n, double s) {
        name = n;
        score = s;
    }

    void Print() {
        cout << name << ": " << score << endl;
    }
};

int main() {
    vector<Movie> list;

    list.push_back(Movie("titanic", 9.9));
    list.push_back(Movie("gone with the wind", 9.6));
    list.push_back(Movie("terminator", 9.7));

    for (auto& m : list) {
        m.Print();
    }

    return 0;
}