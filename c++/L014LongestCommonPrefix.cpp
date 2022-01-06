#include <string>
#include <vector>

using namespace std;

class L014LongestCommonPrefix
{
private:
    /* data */
public:
    L014LongestCommonPrefix(/* args */);
    ~L014LongestCommonPrefix();

    string longestCommonPrefix(vector<string> &strs)
    {
        int strs_len = strs.size();
        string match = strs[0];
        for (int i = 1; i < strs_len; i++) {
            int match_len = match.size();
            int i_len = strs[i].size();
            int j = 0;
            while (j < match_len && j < i_len) {
                if (match[j] != strs[i][j]) break;
                j++;
            }
            if (j == 0) return "";
            if (j < match_len) match = match.substr(0, j);
        }
        return match;
    }
};

L014LongestCommonPrefix::L014LongestCommonPrefix(/* args */) {}

L014LongestCommonPrefix::~L014LongestCommonPrefix() {}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "L014LongestCommonPrefix.cpp"
// using namespace std;

// int main()
// {
//     vector<string> list{"nll", "null", "nu3"};
//     L014LongestCommonPrefix LongestCommonPrefix;
//     cout << LongestCommonPrefix.longestCommonPrefix(list) << endl;

//     return 0;
// }