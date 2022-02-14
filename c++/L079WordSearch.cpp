#include <iostream>
#include <vector>
#include <string>
using namespace std;

class L079WordSearch
{
private:
    /* data */
public:
    L079WordSearch(/* args */);
    ~L079WordSearch();

    bool exist(vector<vector<char>> &board, string word)
    {
        bool res = false;
        vector<vector<int>> check(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size() && res != true; j++) {
                // 每个单元格开始处理
                backtrace(board, word, res, "", check, i, j);
            }
        }

        return res;
    }

    void backtrace(vector<vector<char>> &board, string &word, bool &res, string sub, vector<vector<int>> &check, int r, int c)
    {
        // cout << "sub:" << sub << " sub.size()=" << sub.size() << " r:" << r << " c:" << c << endl;
        if (sub == word) { // 匹配
            res = true;
            return;
        } else if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || // 行号和列号是否超出范围
                   check[r][c] == 1 || // 单元格已经访问
                   board[r][c] != word[sub.size()]) { // 当前单元格不匹配
            return;
        }
        cout << "sub:" << sub << " r:" << r << " c:" << c << " " << board[r][c] << "==" << word[sub.size()] << endl;
        check[r][c] = 1; // 设置该单元格已经访问
        backtrace(board, word, res, sub + board[r][c], check, r - 1, c); // 上
        backtrace(board, word, res, sub + board[r][c], check, r + 1, c); // 下
        backtrace(board, word, res, sub + board[r][c], check, r, c - 1); // 左
        backtrace(board, word, res, sub + board[r][c], check, r, c + 1); // 右
        check[r][c] = 0; // 回溯

        return;
    }
};

L079WordSearch::L079WordSearch(/* args */) {}

L079WordSearch::~L079WordSearch() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L079WordSearch.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
//     string word = "SEE";
//     L079WordSearch WordSearch;
//     bool res = WordSearch.exist(board, word);
//     if (res) {
//         cout << "find!" << endl;
//     } else {
//         cout << "not find!" << endl;
//     }
//     return 0;
// }