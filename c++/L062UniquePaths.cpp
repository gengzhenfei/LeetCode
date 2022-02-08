#include <vector>
using namespace std;

class L062UniquePaths
{
private:
    /* data */
public:
    L062UniquePaths(/* args */);
    ~L062UniquePaths();

    int uniquePaths(int m, int n)
    {
        int paths = 0;
        // dfs(m, n, paths); // 深度优先搜索
        dp(m, n, paths);

        return paths;
    }

    /**
     * LeetCode  38/62个通过测试用例 超出时间限制!!!
     * m = 19, n = 13
     */
    void dfs(int &m, int &n, int &paths, int mi = 1, int ni = 1)
    {
        if (mi == m && ni == n) {
            paths++;
            return;
        } else {
            if (mi != m) {
                if (ni != n) {
                    dfs(m, n, paths, mi + 1, ni);
                } else {
                    paths++;
                    return;
                }
            }
            if (ni != n) {
                if (mi != m) {
                    dfs(m, n, paths, mi, ni + 1);
                } else {
                    paths++;
                    return;
                }
            }
        }
        return;
    }

    /**
     * 动态方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]
     */
    void dp(int &m, int &n, int &paths)
    {
        vector<vector<int>> dp_path(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) { // 计算每个位置的路径数
                dp_path[i][j] = dp_path[i - 1][j] + dp_path[i][j - 1];
            }
        }
        paths = dp_path[m - 1][n - 1];
        return;
    }
};

L062UniquePaths::L062UniquePaths(/* args */) {}

L062UniquePaths::~L062UniquePaths() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L062UniquePaths.cpp"
// using namespace std;

// int main()
// {
//     int m = 19, n = 13;
//     L062UniquePaths UniquePaths;
//     int paths = UniquePaths.uniquePaths(m, n);
//     cout << paths << endl;
//     return 0;
// }