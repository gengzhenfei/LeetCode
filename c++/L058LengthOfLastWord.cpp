#include <string>

using namespace std;

class L058LengthOfLastWord
{
private:
    /* data */
public:
    L058LengthOfLastWord(/* args */);
    ~L058LengthOfLastWord();

    int lengthOfLastWord(string s)
    {
        int last = 0; // 上一个单词的长度
        int cur = 0; // 当前单词长度
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                if (cur == 0) {
                    continue;
                } else {
                    last = cur;
                    cur = 0;
                }
            } else {
                cur++;
            }
        }
        if (cur == 0) return last;
        return cur;
    }
};

L058LengthOfLastWord::L058LengthOfLastWord(/* args */) {}

L058LengthOfLastWord::~L058LengthOfLastWord() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L058LengthOfLastWord.cpp"
// using namespace std;

// int main()
// {
//     string s = "   fly me   to   the moon  ";
//     L058LengthOfLastWord LengthOfLastWord;
//     int result = LengthOfLastWord.lengthOfLastWord(s);
//     cout << result << endl;
//     return 0;
// }