#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class L030SubstringWithConcatenationOfAllWords
{
private:
    /* data */
public:
    L030SubstringWithConcatenationOfAllWords(/* args */);
    ~L030SubstringWithConcatenationOfAllWords();

    vector<int> findSubstring(string s, vector<string> &words)
    {
        map<string, int> words_map, words_map_dup;
        map<string, int>::iterator it;
        vector<int> result;
        int words_nums = words.size();
        if (words_nums == 0) return result;
        int w_len = words[0].size();
        for (auto w : words) {
            map<string, int>::iterator it = words_map.find(w);
            it = words_map.find(w);
            if (it != words_map.end()) {
                words_map[w]++;
            } else {
                words_map.insert(pair<string, int>(w, 1));
            }
        }
        words_map_dup.insert(words_map.begin(), words_map.end()); // 备份，稍后会用到
        // for (it = words_map_dup.begin(); it != words_map_dup.end(); ++it) std::cout << it->first << " => " << it->second << endl;
        int s_len = s.size();
        for (int i = w_len - 1; i < s_len; i++) {
            // cout << "i " << i << endl;
            string sub = s.substr(i - w_len + 1, w_len);
            it = words_map.find(sub);
            if (it != words_map.end()) { // 找到第一个单词
                for (int j = i; j < s_len; j += w_len) {
                    // cout << "j " << j << endl;
                    string sub = s.substr(j - w_len + 1, w_len);
                    it = words_map.find(sub);
                    if (it != words_map.end()) { // map中找到单词
                        words_map[sub]--;
                        // cout << "words_map.size() " << words_map.size() << endl;
                        if (words_map[sub] == 0) words_map.erase(it);
                        if (words_map.size() == 0) { // words所有单词已经完成匹配
                            result.push_back(j - w_len * words_nums + 1);
                            words_map.clear();
                            words_map.insert(words_map_dup.begin(), words_map_dup.end());
                            break;
                        }
                    } else { // 匹配中断
                        words_map.clear();
                        words_map.insert(words_map_dup.begin(), words_map_dup.end());
                        break;
                    }
                }
                if (words_map.size() == 0) { // 匹配到最后并且words已经完全匹配
                    result.push_back(s_len - w_len * words_nums + 1);
                }
                words_map.clear();
                words_map.insert(words_map_dup.begin(), words_map_dup.end());
            }
        }
        if (words_map.size() != 0 && result.size() == 0) return vector<int>();
        return result;
    }
};

L030SubstringWithConcatenationOfAllWords::L030SubstringWithConcatenationOfAllWords(/* args */) {}

L030SubstringWithConcatenationOfAllWords::~L030SubstringWithConcatenationOfAllWords() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L030SubstringWithConcatenationOfAllWords.cpp"
// using namespace std;

// int main()
// {
//     // string str = "wordgoodgoodgoodbestword";
//     // vector<string> words{"word", "good", "best", "word"};
//     string str = "barfoothefoobarman";
//     vector<string> words{"foo", "bar"};
//     L030SubstringWithConcatenationOfAllWords SubstringWithConcatenationOfAllWords;
//     vector<int> result = SubstringWithConcatenationOfAllWords.findSubstring(str, words);
//     for (auto v : result) cout << v << endl;
//     return 0;
// }