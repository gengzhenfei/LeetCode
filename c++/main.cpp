// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L058LengthOfLastWord.cpp"
using namespace std;

int main()
{
    string s = "   fly me   to   the moon  ";
    L058LengthOfLastWord LengthOfLastWord;
    int result = LengthOfLastWord.lengthOfLastWord(s);
    cout << result << endl;
    return 0;
}