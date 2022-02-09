#include <string>
#include <vector>
using namespace std;

class L068TextJustification
{
private:
    /* data */
public:
    L068TextJustification(/* args */);
    ~L068TextJustification();

    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        int len = words.size();
        vector<string> res;
        vector<string> new_line;
        int new_line_chars = 0;
        new_line.push_back(words[0]);
        new_line_chars = words[0].size() + 1;
        for (int i = 1; i < len; i++) {
            // cout << "i:" << i << " new_line_chars:" << new_line_chars << endl;
            if (new_line_chars + words[i].size() > maxWidth) {
                res.push_back(newLine(new_line, new_line_chars, maxWidth));
                new_line_chars = 0;
                new_line.clear();
                new_line.push_back(words[i]);
                new_line_chars = words[i].size() + 1;
            } else {
                new_line.push_back(words[i]);
                new_line_chars += words[i].size() + 1;
            }
        }
        res.push_back(newLine(new_line, new_line_chars, maxWidth, true));

        return res;
    }

    string newLine(vector<string> &new_line, int new_line_chars, int maxWidth, bool is_last = false)
    {
        int len = new_line.size();
        vector<string> space(len - 1, " ");
        string res;
        if (is_last || len == 1) { // 最后一行或此行只有一个单词
            // 相邻单词间一个空格
            for (int i = 0; i < len - 1; i++) { res += new_line[i] + " "; }
            res += new_line[len - 1];
            // 末尾补上空格
            // res += string(maxWidth - new_line_chars + 1, " ");
            for (int i = maxWidth - new_line_chars + 1; i > 0; i--) { res += " "; }
        } else {
            int space_remain = maxWidth - new_line_chars + 1;
            while (space_remain > 0) {
                for (int i = 0; i < len - 1 && space_remain > 0; i++, space_remain--) { space[i] += " "; }
            }
            for (int i = 0; i < len - 1; i++) { res += new_line[i] + space[i]; }
            res += new_line[len - 1];
        }
        return res;
    }
};

L068TextJustification::L068TextJustification(/* args */) {}

L068TextJustification::~L068TextJustification() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L068TextJustification.cpp"
// using namespace std;

// int main()
// {
//     vector<string> words{"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
//     int maxWidth = 20;
//     L068TextJustification TextJustification;
//     vector<string> result = TextJustification.fullJustify(words, maxWidth);
//     for (string s : result) cout << "\"" << s << "\"" << endl;
//     return 0;
// }