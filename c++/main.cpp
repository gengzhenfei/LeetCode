// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L062UniquePaths.cpp"
using namespace std;

int main()
{
    int m = 19, n = 13;
    L062UniquePaths UniquePaths;
    int paths = UniquePaths.uniquePaths(m, n);
    cout << paths << endl;
    return 0;
}