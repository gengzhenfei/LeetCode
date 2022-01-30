#include <iostream>
#include <vector>
using namespace std;

class L054SpiralMatrix
{
private:
    /* data */
public:
    L054SpiralMatrix(/* args */);
    ~L054SpiralMatrix();

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int row = matrix.size(); // 行
        if (row == 0) return res;
        int col = matrix[0].size(); // 列
        int up = 0, down = row - 1, left = 0, right = col - 1;
        while (true) {
            // cout << "up:" << up << " left:" << left << " down:" << down << " right:" << right << endl;
            // 自左上向右上
            for (int i = left; i <= right; i++) { res.push_back(matrix[up][i]); }
            up++;
            if (up > down) break;
            // 自右上至右下
            for (int i = up; i <= down; i++) { res.push_back(matrix[i][right]); }
            right--;
            if (left > right) break;
            // 自右下向左下
            for (int i = right; i >= left; i--) { res.push_back(matrix[down][i]); }
            down--;
            if (up > down) break;
            // 自左下至左上
            for (int i = down; i >= up; i--) { res.push_back(matrix[i][left]); }
            left++;
            if (left > right) break;
        }
        return res;
    }
};

L054SpiralMatrix::L054SpiralMatrix(/* args */) {}

L054SpiralMatrix::~L054SpiralMatrix() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L054SpiralMatrix.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
//     L054SpiralMatrix SpiralMatrix;
//     vector<int> result = SpiralMatrix.spiralOrder(matrix);
//     for (int i : result) cout << i << endl;
//     return 0;
// }