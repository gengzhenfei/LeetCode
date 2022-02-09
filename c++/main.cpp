// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L068TextJustification.cpp"
using namespace std;

int main()
{
    vector<string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    int maxWidth = 20;
    L068TextJustification TextJustification;
    vector<string> result = TextJustification.fullJustify(words, maxWidth);
    for (string s : result) cout << "\"" << s << "\"" << endl;
    return 0;
}