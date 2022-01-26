// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L051NQueens.cpp"
using namespace std;

int main()
{
    int n = 6;
    L051NQueens NQueens;
    vector<vector<string>> res = NQueens.solveNQueens(n);
    for (auto v_s : res) {
        cout << "[" << endl;
        for (auto s : v_s) { cout << "\"" << s << "\"," << endl; }
        cout << "]" << endl;
    }
    return 0;
}