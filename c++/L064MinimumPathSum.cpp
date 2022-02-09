#include <vector>
using namespace std;

class L064MinimumPathSum
{
private:
    /* data */
public:
    L064MinimumPathSum(/* args */);
    ~L064MinimumPathSum();

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m; i++) { grid[i][0] += grid[i - 1][0]; }
        for (int i = 1; i < n; i++) { grid[0][i] += grid[0][i - 1]; }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) { grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]); }
        }
        return grid[m - 1][n - 1];
    }
};

L064MinimumPathSum::L064MinimumPathSum(/* args */) {}

L064MinimumPathSum::~L064MinimumPathSum() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L064MinimumPathSum.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
//     L064MinimumPathSum MinimumPathSum;
//     int sum = MinimumPathSum.minPathSum(grid);
//     cout << sum << endl;
//     return 0;
// }