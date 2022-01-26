// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L052NQueens2.cpp"
using namespace std;

int main()
{
    int n = 4;
    L052NQueens2 NQueens2;
    int total = NQueens2.totalNQueens(n);
    cout << total << endl;
    return 0;
}