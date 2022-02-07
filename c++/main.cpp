// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L066PlusOne.cpp"
using namespace std;

int main()
{
    vector<int> list{};
    L066PlusOne PlusOne;
    vector<int> res = PlusOne.plusOne(list);
    for (int i : res) cout << i << " ";
    cout << endl;
    return 0;
}