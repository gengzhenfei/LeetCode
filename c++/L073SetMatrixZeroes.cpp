#include <vector>
#include <set>
using namespace std;

class L073SetMatrixZeroes
{
private:
    /* data */
public:
    L073SetMatrixZeroes(/* args */);
    ~L073SetMatrixZeroes();

    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> zeor_col; // 需设置为0的列
        set<int> none_zeor_row; // 不存在0的行
        int rows = matrix.size(), col = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            int zeor = 0;
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    zeor++;
                    zeor_col.insert(j);
                }
            }
            if (zeor > 0) {
                matrix[i] = vector<int>(col, 0);
            } else {
                none_zeor_row.insert(i);
            }
        }
        for (int r : none_zeor_row) { // 设置列为0
            for (int c : zeor_col) { matrix[r][c] = 0; }
        }
        return;
    }
};

L073SetMatrixZeroes::L073SetMatrixZeroes(/* args */) {}

L073SetMatrixZeroes::~L073SetMatrixZeroes() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L073SetMatrixZeroes.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> matrix{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
//     L073SetMatrixZeroes SetMatrixZeroes;
//     SetMatrixZeroes.setZeroes(matrix);
//     for (auto v : matrix) {
//         cout << "[ ";
//         for (int i : v) { cout << i << " "; }
//         cout << "]" << endl;
//     }
//     return 0;
// }