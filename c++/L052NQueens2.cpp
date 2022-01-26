#include <iostream>
#include <vector>
#include <string>
#include <utility> // pair
using namespace std;

class L052NQueens2
{
private:
    /* data */
public:
    L052NQueens2(/* args */);
    ~L052NQueens2();

    /**
     * 任两个皇后都不能处于同一条横行、纵行或斜线上。
     */
    int totalNQueens(int n)
    {
        int total = 0;
        vector<pair<int, int>> one;
        backtrack(total, one, n, 0);
        return total;
    }

    void backtrack(int &total, vector<pair<int, int>> &one, int n, int i)
    {
        if (i >= n) { return; }
        for (int j = 0; j < n; j++) { // 每一列进行回溯
            bool conflict = false;
            for (pair<int, int> p : one) { // 检验是否存在冲突
                if (p.first - i == p.second - j || p.first - i == j - p.second || p.second == j) {
                    conflict = true;
                    break;
                }
            }
            if (conflict) continue; // 冲突
            if (i == n - 1) { // 最后一行
                total++;
                return;
            }
            one.push_back(make_pair(i, j));
            backtrack(total, one, n, i + 1);
            one.pop_back(); // 恢复现场 以便回溯
        }
        return;
    }
};

L052NQueens2::L052NQueens2(/* args */) {}

L052NQueens2::~L052NQueens2() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L052NQueens2.cpp"
// using namespace std;

// int main()
// {
//     int n = 4;
//     L052NQueens2 NQueens2;
//     int total = NQueens2.totalNQueens(n);
//     cout << total << endl;
//     return 0;
// }