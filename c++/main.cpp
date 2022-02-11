// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L073SetMatrixZeroes.cpp"
using namespace std;

int main()
{
    vector<vector<int>> matrix{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    L073SetMatrixZeroes SetMatrixZeroes;
    SetMatrixZeroes.setZeroes(matrix);
    for (auto v : matrix) {
        cout << "[ ";
        for (int i : v) { cout << i << " "; }
        cout << "]" << endl;
    }
    return 0;
}