// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L031NextPermutation.cpp"
using namespace std;

int main()
{
    vector<int> v{1, 3, 2};
    L031NextPermutation NextPermutation;
    NextPermutation.nextPermutation(v);
    for (auto i : v) { cout << i << endl; }
    return 0;
}