#include <iostream>
#include <vector>
using namespace std;

class L063UniquePaths2
{
private:
    /* data */
public:
    L063UniquePaths2(/* args */);
    ~L063UniquePaths2();

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int paths = 0;
        int m = obstacleGrid.size();
        int n = (m == 0) ? 0 : obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1) { return paths; } // finish位有个障碍物
        // dfs(m, n, paths, obstacleGrid); // 深度优先搜索
        dp(m, n, paths, obstacleGrid);

        return paths;
    }

    /**
     * 深度优先搜索
     * LeetCode 30/41个通过测试用例 超出时间限制
     */
    void dfs(int &m, int &n, int &paths, vector<vector<int>> &obstacleGrid, int mi = 1, int ni = 1)
    {
        // cout << "mi:" << mi << " ni:" << ni << " paths:" << paths << endl;
        if (obstacleGrid[mi - 1][ni - 1] == 1) return;
        if (mi == m && ni == n) {
            paths++;
            return;
        } else {
            if (mi != m) { dfs(m, n, paths, obstacleGrid, mi + 1, ni); }
            if (ni != n) { dfs(m, n, paths, obstacleGrid, mi, ni + 1); }
        }
        // cout << "mi:" << mi << " ni:" << ni << " paths:" << paths << endl;
        return;
    }

    /**
     * 动态方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
     */
    void dp(int &m, int &n, int &paths, vector<vector<int>> &obstacleGrid)
    {
        vector<vector<int>> dp_path(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) { // 处理第1列
            if (obstacleGrid[i][0] == 1) { // 遇到一个障碍物，则此列后续路径均为0
                while (i < m) { dp_path[i++][0] = 0; }
            }
        }
        for (int i = 0; i < n; i++) { // 处理第一行
            if (obstacleGrid[0][i] == 1) { // 遇到一个障碍物，则此列后续路径均为0
                while (i < n) { dp_path[0][i++] = 0; }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) { // 计算每个位置的路径数
                if (obstacleGrid[i][j] == 1) { // 遇到障碍物 则该位置不可到达 即路径为0
                    dp_path[i][j] = 0;
                } else {
                    dp_path[i][j] = dp_path[i - 1][j] + dp_path[i][j - 1];
                }
            }
        }
        paths = dp_path[m - 1][n - 1];
        return;
    }
};

L063UniquePaths2::L063UniquePaths2(/* args */) {}

L063UniquePaths2::~L063UniquePaths2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L063UniquePaths2.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<int>> obstacleGrid{{0, 1}, {0, 0}};
//     L063UniquePaths2 UniquePaths2;
//     int paths = UniquePaths2.uniquePathsWithObstacles(obstacleGrid);
//     cout << paths << endl;
//     return 0;
// }