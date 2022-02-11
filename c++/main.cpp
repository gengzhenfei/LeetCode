// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L074SearchA2dMatrix.cpp"
using namespace std;

int main()
{
    vector<vector<int>> matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    L074SearchA2dMatrix SearchA2dMatrix;
    bool res = SearchA2dMatrix.searchMatrix(matrix, target);
    cout << "true:" << true << " " << res << endl;
    return 0;
}