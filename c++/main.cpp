// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L091DecodeWays.cpp"
using namespace std;

int main()
{
    string s = "10";
    L091DecodeWays DecodeWays;
    int res = DecodeWays.numDecodings(s);
    cout << res << endl;
    return 0;
}