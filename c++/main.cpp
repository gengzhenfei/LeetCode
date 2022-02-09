// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L065ValidNumber.cpp"
using namespace std;

int main()
{
    string s = "005047e+6";
    L065ValidNumber ValidNumber;
    bool result = ValidNumber.isNumber(s);
    cout << "true=" << true << " " << result << endl;
    return 0;
}