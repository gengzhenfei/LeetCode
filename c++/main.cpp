// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L028ImplementStrstr.cpp"
using namespace std;

int main()
{
    string str1 = "aabaaabaaac";
    string str2 = "aabaaac";
    L028ImplementStrstr ImplementStrstr;
    int index = ImplementStrstr.strStr(str1, str2);
    cout << index << endl;
    return 0;
}