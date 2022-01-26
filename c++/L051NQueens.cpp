#include <iostream>
#include <vector>
#include <string>
#include <utility> // pair
using namespace std;

class L051NQueens
{
private:
    /* data */
public:
    L051NQueens(/* args */);
    ~L051NQueens();

    typedef vector<vector<pair<int, int>>> v_v_pair;
    typedef vector<pair<int, int>> v_pair;
    // C++11
    // using v_v_pair = vector<vector<pair<int, int>>>;
    // using v_pair = vector<pair<int, int>>;

    /**
     * 任两个皇后都不能处于同一条横行、纵行或斜线上。
     */
    vector<vector<string>> solveNQueens(int n)
    {
        v_v_pair res;
        v_pair one;

        backtrack(res, one, n, 0);
        vector<vector<string>> vvs;

        for (v_pair v_p : res) {
            vector<string> v_s(n, string(n, '.'));
            for (pair<int, int> p : v_p) { v_s[p.first][p.second] = 'Q'; }
            vvs.push_back(v_s);
        }

        return vvs;
    }

    void backtrack(v_v_pair &res, v_pair &one, int n, int i)
    {
        if (i >= n) { return; }
        for (int j = 0; j < n; j++) { // 每一列进行回溯
            // cout << "i: " << i << " j: " << j << endl;
            bool conflict = false;
            for (pair<int, int> p : one) { // 检验是否存在冲突
                if (p.first - i == p.second - j || p.first - i == j - p.second || p.second == j) {
                    conflict = true;
                    break;
                }
            }
            if (conflict) continue; // 冲突
            one.push_back(make_pair(i, j));
            // for (pair<int, int> p : one) { cout << "<" << p.first << "," << p.second << "> "; }
            // cout << endl;
            if (i == n - 1) { // 最后一行
                res.push_back(one);
                one.pop_back(); // 恢复现场 以便回溯
                return;
            }
            backtrack(res, one, n, i + 1);
            one.pop_back(); // 恢复现场 以便回溯
        }
        return;
    }
};

L051NQueens::L051NQueens(/* args */) {}

L051NQueens::~L051NQueens() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L051NQueens.cpp"
// using namespace std;

// int main()
// {
//     int n = 6;
//     L051NQueens NQueens;
//     vector<vector<string>> res = NQueens.solveNQueens(n);
//     for (auto v_s : res) {
//         cout << "[" << endl;
//         for (auto s : v_s) { cout << "\"" << s << "\"," << endl; }
//         cout << "]" << endl;
//     }
//     return 0;
// }