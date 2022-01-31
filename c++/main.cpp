// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L059SpiralMatrix2.cpp"
using namespace std;

int main()
{
    int n = 4;
    L059SpiralMatrix2 SpiralMatrix2;
    vector<vector<int>> result = SpiralMatrix2.generateMatrix(n);
    for (auto v : result) {
        for (int i : v) cout << " " << i;
        cout << endl;
    }
    return 0;
}