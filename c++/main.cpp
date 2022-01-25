// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L049GroupAnagrams.cpp"
using namespace std;

int main()
{
    vector<string> strs{"ddddddddddg", "dgggggggggg"};
    L049GroupAnagrams GroupAnagrams;
    vector<vector<string>> res = GroupAnagrams.groupAnagrams(strs);
    for (auto v : res) {
        cout << "[";
        for (string s : v) cout << " " << s;
        cout << " ]" << endl;
    }
    return 0;
}