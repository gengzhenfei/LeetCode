#include <vector>
using namespace std;

class L059SpiralMatrix2
{
private:
    /* data */
public:
    L059SpiralMatrix2(/* args */);
    ~L059SpiralMatrix2();

    vector<vector<int>> generateMatrix(int n)
    {
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int i = 1;
        vector<vector<int>> res;
        for (int j = 0; j < n; j++) res.push_back(vector<int>(n, 0));
        while (i <= n * n) {
            // 从左上向右上
            for (int j = left; j <= right; j++) { res[up][j] = i++; }
            up++;
            if (up > down) return res;
            // 从右上到右下
            for (int j = up; j <= down; j++) { res[j][right] = i++; }
            right--;
            if (left > right) return res;
            // 从右下向左下
            for (int j = right; j >= left; j--) { res[down][j] = i++; }
            down--;
            if (up > down) return res;
            // 从左下到左上
            for (int j = down; j >= up; j--) { res[j][left] = i++; }
            left++;
            if (up > down) return res;
        }
        return res;
    }
};

L059SpiralMatrix2::L059SpiralMatrix2(/* args */) {}

L059SpiralMatrix2::~L059SpiralMatrix2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L059SpiralMatrix2.cpp"
// using namespace std;

// int main()
// {
//     int n = 4;
//     L059SpiralMatrix2 SpiralMatrix2;
//     vector<vector<int>> result = SpiralMatrix2.generateMatrix(n);
//     for (auto v : result) {
//         for (int i : v) cout << " " << i;
//         cout << endl;
//     }
//     return 0;
// }