#include <string>
#include <vector>
#include <iostream>
using namespace std;

class L043MultiplyStrings
{
private:
    /* data */
public:
    L043MultiplyStrings(/* args */);
    ~L043MultiplyStrings();

    string multiply(string num1, string num2)
    {
        int num1_len = num1.size(), num2_len = num2.size();
        // 两个乘数其中之一为0
        if ((num1_len == 1 && c2i(num1[0]) == 0) || (num2_len == 1 && c2i(num2[0]) == 0)) { return "0"; }
        vector<int> result; // 相乘结果 result[0]个位,result[1]十位,result[2]百位,result[3]千位...
        for (int i1 = num1_len - 1; i1 >= 0; i1--) {
            vector<int> tmp; // 中间结果
            int carry = 0; // 进位
            int result_len = result.size();
            for (int i = num1_len - 1; i > i1; i--) { // 补0
                if (num1_len - 1 - i < result_len) {
                    tmp.push_back(result[num1_len - 1 - i]);
                } else {
                    tmp.push_back(0);
                }
            }
            for (int i2 = num2_len - 1; i2 >= 0; i2--) { // num1[i1]与num2各位相乘
                if (num2_len - 1 - i2 + num1_len - 1 - i1 < result_len) { carry += result[num2_len - 1 - i2 + num1_len - 1 - i1]; } // 加上前一位相乘的结果
                tmp.push_back((c2i(num2[i2]) * c2i(num1[i1]) + carry) % 10); // 相乘结果个位数
                carry = (c2i(num2[i2]) * c2i(num1[i1]) + carry) / 10; // 进位
            }
            while (carry != 0) { // 进位非0继续进位
                tmp.push_back(carry % 10);
                carry /= 10;
            }
            result = tmp;
            // cout << "c2i(num1[i1]) " << c2i(num1[i1]) << endl;
            // for (auto i : result) cout << i << endl;
        }
        string str = "";
        for (int i = result.size() - 1; i >= 0; i--) str += i2c(result[i]);
        return str;
    }

    int c2i(char c)
    {
        if (c > '9' || c < '0') return 0;
        return c - '0';
    }

    char i2c(int i)
    {
        if (i > 9 || i < 0) return '0';
        return i + '0';
    }
};

L043MultiplyStrings::L043MultiplyStrings(/* args */) {}

L043MultiplyStrings::~L043MultiplyStrings() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L043MultiplyStrings.cpp"
// using namespace std;

// int main()
// {
//     string num1 = "2";
//     string num2 = "3";
//     L043MultiplyStrings MultiplyStrings;
//     string result = MultiplyStrings.multiply(num1, num2);
//     cout << result << endl;
//     return 0;
// }