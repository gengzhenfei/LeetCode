#include <string>
#include <iostream>
#include <regex>
using namespace std;

class L008StringToIntegerAtoi
{
private:
    /* data */
public:
    L008StringToIntegerAtoi(/* args */);
    ~L008StringToIntegerAtoi();

    int myAtoi(string s)
    {
        int s_len = s.size();
        int neg = false;
        char nums[20];
        long double result = 0;
        for (int i = 0; i < s_len; i++) {
            if (s[i] == ' ') { // 过滤前面 空字符
                continue;
            } else if (isdigit(s[i]) || ((s[i] == '-' || s[i] == '+') && i + 1 < s_len && isdigit(s[i + 1]))) { // 遇到数字或正负号
                if (s[i] == '-') {
                    neg = true;
                    i++;
                } else if (s[i] == '+')
                    i++;
                // 最多取11个连续数字（不以0开头），因为2^31为10位，如果超过11位则字符串中包含的数字必定超出int范围
                while (isdigit(s[i]) && s[i] == '0') i++; // 过滤前缀0字符
                int j = 0;
                while (i < s_len && isdigit(s[i]) && j < 11) {
                    result = result * 10 + charToDigit(s[i]);
                    i++;
                    j++;
                }
                break;
            } else // 读入字符并非数字，终止
                break;
        }
        if (neg == false && result > 2147483647) // 超过int正
            return 2147483647;
        else if (neg == true && result > 2147483648) { // 超过int负
            return -2147483648;
        } else if (neg == true)
            return -result;
        else
            return result;
    }

    int charToDigit(char c)
    {
        switch (c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return 0;
        }
    }
};

L008StringToIntegerAtoi::L008StringToIntegerAtoi(/* args */) {}

L008StringToIntegerAtoi::~L008StringToIntegerAtoi() {}

// #include <iostream>
// #include <string>
// #include "L008StringToIntegerAtoi.cpp"
// using namespace std;

// int main()
// {
//     string s = "  0000000000012345678";
//     L008StringToIntegerAtoi StringToInteger;
//     int result = StringToInteger.myAtoi(s);
//     cout << result << endl;

//     return 0;
// }