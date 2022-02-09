#include <iostream>
#include <string>
using namespace std;

class L065ValidNumber
{
private:
    /* data */
public:
    L065ValidNumber(/* args */);
    ~L065ValidNumber();

    bool isNumber(string s)
    {
        int len = s.size();
        int point = 0; // 小数点数量
        int digit = 0; // 数字数量
        for (int i = 0; i < len; i++) {
            cout << "i:" << i << " s[i]:" << s[i] << endl;
            if (s[i] == '+' || s[i] == '-') { // 正负号
                if (i != 0) { return false; }
            } else if (s[i] == '.') { // 小数点
                cout << "digit:" << digit << " point:" << point << endl;
                if (point == 0) { // 第一个小数点
                    if (digit == 0 && (i == len - 1 || s[i + 1] == 'e' || s[i + 1] == 'E')) { return false; }
                    point++;
                } else { // 已经有小数点了
                    return false;
                }
            } else if (s[i] >= '0' && s[i] <= '9') { // 数字
                digit++;
            } else if (s[i] == 'e' || s[i] == 'E') { // e E
                if (digit == 0 || i >= len - 1) { // e9 false, 即e前必须有数字
                    return false;
                } else {
                    // e 之后的整数部分
                    digit = 0; // 数字数量重置为0
                    for (int j = i + 1; j < len; j++) {
                        cout << "j:" << j << " s[j]:" << s[j] << endl;
                        if (s[j] == '+' || s[j] == '-') { // 正负号
                            if (i + 1 != j) { return false; }
                        } else if (s[j] == '.') { // 小数点
                            return false;
                        } else if (s[j] >= '0' && s[j] <= '9') { // 数字
                            digit++;
                        } else {
                            return false;
                        }
                    }
                    if (digit == 0) return false;
                    return true;
                }
            } else { // 其他
                return false;
            }
        }
        return true;
    }
};

L065ValidNumber::L065ValidNumber(/* args */) {}

L065ValidNumber::~L065ValidNumber() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L065ValidNumber.cpp"
// using namespace std;

// int main()
// {
//     string s = "005047e+6";
//     L065ValidNumber ValidNumber;
//     bool result = ValidNumber.isNumber(s);
//     cout << "true=" << true << " " << result << endl;
//     return 0;
// }