#include <iostream>
#include <memory>
using namespace std;
int main()
{
    unique_ptr<int[]> buf(new int[10]); //4바이트 이후에도 끝까지 찾아서 없애라
    for (int i = 0; i < 10; i++)
    {
        buf[i] = i;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << buf[i] << " ";
    }
    cout << endl;
    return 0;
}