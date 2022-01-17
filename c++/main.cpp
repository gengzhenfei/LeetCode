// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L038CountAndSay.cpp"
using namespace std;

int main()
{
    int n = 4;
    L038CountAndSay CountAndSay;
    string result = CountAndSay.countAndSay(n);
    cout << result << endl;
    return 0;
}