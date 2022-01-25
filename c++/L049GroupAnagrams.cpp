#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class L049GroupAnagrams
{
private:
    /* data */
public:
    L049GroupAnagrams(/* args */);
    ~L049GroupAnagrams();

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        for (string str : strs) {
            string s = str;
            sort(s.begin(), s.end()); // 对字符串中的字符进行排序
            if (m.find(s) != m.end()) { // map 中存在key
                m[s].push_back(str);
            } else {
                m[s] = vector<string>{str};
            }
        }
        map<string, vector<string>>::iterator it = m.begin();
        for (; it != m.end(); it++) res.push_back(it->second);

        return res;
    }
};

L049GroupAnagrams::L049GroupAnagrams(/* args */) {}

L049GroupAnagrams::~L049GroupAnagrams() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L049GroupAnagrams.cpp"
// using namespace std;

// int main()
// {
//     vector<string> strs{"ddddddddddg", "dgggggggggg"};
//     L049GroupAnagrams GroupAnagrams;
//     vector<vector<string>> res = GroupAnagrams.groupAnagrams(strs);
//     for (auto v : res) {
//         cout << "[";
//         for (string s : v) cout << " " << s;
//         cout << " ]" << endl;
//     }
//     return 0;
// }