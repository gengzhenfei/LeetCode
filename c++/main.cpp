// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L036ValidSudoku.cpp"
using namespace std;

int main()
{
    vector<vector<char>> board{{'.', '.', '4', '.', '.', '.', '6', '3', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'5', '.', '.', '.', '.', '.', '.', '9', '.'},
                               {'.', '.', '.', '5', '6', '.', '.', '.', '.'}, {'4', '.', '3', '.', '.', '.', '.', '.', '1'}, {'.', '.', '.', '7', '.', '.', '.', '.', '.'},
                               {'.', '.', '.', '5', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '.'}};
    L036ValidSudoku ValidSudoku;
    bool result = ValidSudoku.isValidSudoku(board);
    cout << "true:" << true << " " << result << endl;
    return 0;
}