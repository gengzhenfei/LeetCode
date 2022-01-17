#include <vector>
#include <iostream>
using namespace std;

class L036ValidSudoku
{
private:
    /* data */
public:
    L036ValidSudoku(/* args */);
    ~L036ValidSudoku();

    bool isValidSudoku(vector<vector<char>> &board)
    {
        int row[9][10] = {0}; // 行 i
        int col[9][10] = {0}; // 列 j
        int block[9][10] = {0}; // 块 j/3+(i/3)*3
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '0';
                int block_r = j / 3 + (i / 3) * 3;
                if (row[i][num] == 1) return false;
                if (col[j][num] == 1) return false;
                if (block[block_r][num] == 1) return false;
                row[i][num] = 1;
                col[j][num] = 1;
                block[j / 3 + (i / 3) * 3][num] = 1;
            }
        }
        return true;
    }
};

L036ValidSudoku::L036ValidSudoku(/* args */) {}

L036ValidSudoku::~L036ValidSudoku() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L036ValidSudoku.cpp"
// using namespace std;

// int main()
// {
//     vector<vector<char>> board{{'.', '.', '4', '.', '.', '.', '6', '3', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
//                                {'.', '.', '.', '5', '6', '.', '.', '.', '.'}, {'4', '.', '3', '.', '.', '.', '.', '.', '1'}, {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
//                                {'.', '.', '.', '5', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
//     L036ValidSudoku ValidSudoku;
//     bool result = ValidSudoku.isValidSudoku(board);
//     cout << "true:" << true << " " << result << endl;
//     return 0;
// }