// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L054SpiralMatrix.cpp"
using namespace std;

int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    L054SpiralMatrix SpiralMatrix;
    vector<int> result = SpiralMatrix.spiralOrder(matrix);
    for (int i : result) cout << i << endl;
    return 0;
}