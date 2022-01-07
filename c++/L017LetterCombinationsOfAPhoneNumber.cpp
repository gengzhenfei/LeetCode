#include <vector>
#include <string>
#include <iostream>
using namespace std;

class L017LetterCombinationsOfAPhoneNumber
{
private:
    /* data */
public:
    L017LetterCombinationsOfAPhoneNumber(/* args */);
    ~L017LetterCombinationsOfAPhoneNumber();

    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        int len = digits.size();
        if (len == 0) return result; // 长度为0 直接返回空
        // 处理第一个数字
        string letters = phoneNumber2Letters(stoi(digits.substr(0, 1)));
        for (int i = 0; i < letters.size(); i++) { result.push_back(letters.substr(i, 1)); }
        // 处理后续数字
        for (int j = 1; j < len; j++) {
            letters = phoneNumber2Letters(stoi(digits.substr(j, 1)));
            vector<string> v_letters; // 数字键对应字母
            vector<string> v_result; // 临时结果存放
            for (int i = 0; i < letters.size(); i++) { v_letters.push_back(letters.substr(i, 1)); }
            for (auto str : result) {
                // 逐个拼接
                for (auto letter : v_letters) { v_result.push_back(str + letter); }
            }
            result = v_result; // 转移结果
            // result.assign(v_result.begin(), v_result.end()); // 转移结果
            v_result.clear(); // 临时容器清空
        }
        return result;
    }

    string phoneNumber2Letters(int num)
    {
        switch (num) {
        case 2: return "abc";
        case 3: return "def";
        case 4: return "ghi";
        case 5: return "jkl";
        case 6: return "mno";
        case 7: return "pqrs";
        case 8: return "tuv";
        case 9: return "wxyz";
        default: return "";
        }
    }
};

L017LetterCombinationsOfAPhoneNumber::L017LetterCombinationsOfAPhoneNumber(/* args */) {}

L017LetterCombinationsOfAPhoneNumber::~L017LetterCombinationsOfAPhoneNumber() {}

// #include <iostream>
// #include "L017LetterCombinationsOfAPhoneNumber.cpp"
// using namespace std;

// int main()
// {
//     string digits = "234";
//     L017LetterCombinationsOfAPhoneNumber LetterCombinationsOfAPhoneNumber;
//     vector<string> result = LetterCombinationsOfAPhoneNumber.letterCombinations(digits);
//     for (auto i : result) cout << i << endl;

//     return 0;
// }