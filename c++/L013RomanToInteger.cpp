#include <string>

using namespace std;

class L013RomanToInteger
{
private:
    /* data */
public:
    L013RomanToInteger(/* args */);
    ~L013RomanToInteger();

    /**
     * 罗马数字转int 思路
     * 根据罗马数字规则，总共7个符号，指针i依次访问罗马数字的每一位符号，符号分为两类分别处理：
     * 第一类，I(1)，X(10)，C(100)，这三个符号在数字表示过程中有两个种情况：
     *   1. 后面没有符号或后一位符号代表的数值小于当前符号的数值，则该数值直接加入结果，指针i++；
     *   2. 后面有符号且后面符号的数值大于当前符号的数值，则后面数值减去当前数值之后，加入结果，指针i+=2；
     * 第二类，V(5)，L(50)，D(500)，M(1000)，这四个符号的数值可直接加入结果即可，指针i++；
     * 直到指针p将罗马数字依次访问完，即可得到最终结果
     */
    int romanToInt(string s)
    {
        int s_len = s.size();
        int result = 0;
        for (int i = 0; i < s_len; i++) {
            int i_val = mapR2I(s[i]);
            if (s[i] == 'I' || s[i] == 'X' || s[i] == 'C') {
                if (i == s_len - 1) { // 最后一位了 直接加即可
                    result += i_val;
                } else {
                    int next_val = mapR2I(s[i + 1]);
                    if (next_val > i_val) { // 后一位的值大于当前位的值，则后减去前
                        result += next_val - i_val;
                        i++; // 多前进一位
                    } else { // 后一位的值小于当前位的值，则直接加
                        result += i_val;
                    }
                }
            } else { // 当前位为 V L D M，则直接加即可
                result += i_val;
            }
        }
        return result;
    }

    int mapR2I(char c)
    {
        switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
    }
};

L013RomanToInteger::L013RomanToInteger(/* args */) {}

L013RomanToInteger::~L013RomanToInteger() {}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "L012IntegerToRoman.cpp"
// #include "L013RomanToInteger.cpp"
// using namespace std;

// int main()
// {
//     int num = 1994;
//     L012IntegerToRoman IntegerToRoman;
//     string roman = IntegerToRoman.intToRoman(num);
//     cout << roman << endl;
//     L013RomanToInteger RomanToInteger;
//     cout << RomanToInteger.romanToInt(roman) << endl;

//     return 0;
// }