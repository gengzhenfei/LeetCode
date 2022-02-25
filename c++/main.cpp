// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L093RestoreIpAddresses.cpp"
using namespace std;

int main()
{
    string s = "000256";
    L093RestoreIpAddresses RestoreIpAddresses;
    vector<string> res = RestoreIpAddresses.restoreIpAddresses(s);
    for (string s : res) cout << s << endl;
    return 0;
}