#include <string>
#include <vector>
#include <iostream>

using namespace std;

class L028ImplementStrstr
{
private:
    /* data */
public:
    L028ImplementStrstr(/* args */);
    ~L028ImplementStrstr();

    int strStr(string haystack, string needle)
    {
        int haystack_len = haystack.size();
        int needle_len = needle.size();
        if (needle_len == 0) return 0;
        vector<int> next;
        getNext(next, needle);
        for (int i = 0; i < needle_len; i++) { cout << "next" << i << ":" << next[i] << endl; }
        int i = 0;
        while (i < haystack_len) {
            cout << "i:" << i << endl;
            int match = i;
            int j = 0;
            while (j < needle_len) {
                cout << "i:" << i << " j:" << j << endl;
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                } else if (j == 0) {
                    i = match + next[j] + 1;
                    break;
                } else {
                    i = match + next[j];
                    break;
                }
            }
            if (j == needle_len) return match;
        }

        return -1;
    }

    void getNext(vector<int> &next, string needle)
    {
        int needle_len = needle.size();
        if (needle_len == 0) return;
        next.push_back(0);
        if (needle_len == 1) return;
        next.push_back(1);

        for (int i = 1; i < needle_len; i++) {
            next.push_back(1);
            for (int j = 0; j < i; j++) {
                string prefix = needle.substr(0, j + 1);
                string suffix = needle.substr(i - j, j + 1);
                if (prefix == suffix && i != needle_len - 1) next[i] = j + 1;
            }
        }
    }
};

L028ImplementStrstr::L028ImplementStrstr(/* args */) {}

L028ImplementStrstr::~L028ImplementStrstr() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L028ImplementStrstr.cpp"
// using namespace std;

// int main()
// {
//     string str1 = "aabaaabaaac";
//     string str2 = "aabaaac";
//     L028ImplementStrstr ImplementStrstr;
//     int index = ImplementStrstr.strStr(str1, str2);
//     cout << index << endl;
//     return 0;
// }