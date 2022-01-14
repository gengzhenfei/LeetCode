// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L030SubstringWithConcatenationOfAllWords.cpp"
using namespace std;

int main()
{
    // string str = "wordgoodgoodgoodbestword";
    // vector<string> words{"word", "good", "best", "word"};
    string str = "barfoothefoobarman";
    vector<string> words{"foo", "bar"};
    L030SubstringWithConcatenationOfAllWords SubstringWithConcatenationOfAllWords;
    vector<int> result = SubstringWithConcatenationOfAllWords.findSubstring(str, words);
    for (auto v : result) cout << v << endl;
    return 0;
}