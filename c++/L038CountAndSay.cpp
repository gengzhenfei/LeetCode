#include <string>
using namespace std;

class L038CountAndSay
{
private:
    /* data */
public:
    L038CountAndSay(/* args */);
    ~L038CountAndSay();

    string countAndSay(int n)
    {
        string result = "1";
        int nums = 1; // 计数
        while (nums < n) {
            string tmp = "";
            int len = result.size();
            int count = 1;
            char say = result[0];
            for (int i = 0; i < len; i++) {
                if (i + 1 < len) {
                    if (result[i] == result[i + 1]) {
                        count++;
                    } else {
                        tmp += to_string(count) + say;
                        count = 1;
                        say = result[i + 1];
                    }
                } else {
                    tmp += to_string(count) + say;
                }
            }
            result = tmp;
            nums++;
        }
        return result;
    }
};

L038CountAndSay::L038CountAndSay(/* args */) {}

L038CountAndSay::~L038CountAndSay() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L038CountAndSay.cpp"
// using namespace std;

// int main()
// {
//     int n = 4;
//     L038CountAndSay CountAndSay;
//     string result = CountAndSay.countAndSay(n);
//     cout << result << endl;
//     return 0;
// }