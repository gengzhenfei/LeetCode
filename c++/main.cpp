// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L063UniquePaths2.cpp"
using namespace std;

int main()
{
    vector<vector<int>> obstacleGrid{{0, 1}, {0, 0}};
    L063UniquePaths2 UniquePaths2;
    int paths = UniquePaths2.uniquePathsWithObstacles(obstacleGrid);
    cout << paths << endl;
    return 0;
}