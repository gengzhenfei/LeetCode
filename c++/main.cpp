// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L079WordSearch.cpp"
using namespace std;

int main()
{
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "SEE";
    L079WordSearch WordSearch;
    bool res = WordSearch.exist(board, word);
    if (res) {
        cout << "find!" << endl;
    } else {
        cout << "not find!" << endl;
    }
    return 0;
}