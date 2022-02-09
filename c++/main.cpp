// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L064MinimumPathSum.cpp"
using namespace std;

int main()
{
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    L064MinimumPathSum MinimumPathSum;
    int sum = MinimumPathSum.minPathSum(grid);
    cout << sum << endl;
    return 0;
}