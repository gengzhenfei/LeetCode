// main.cpp
// 调试时将以下代码放入main.cpp文件
#include <iostream>
#include "L071SimplifyPath.cpp"
using namespace std;

int main()
{
    string path = "/a//b////c/d//././/..";
    L071SimplifyPath SimplifyPath;
    string res = SimplifyPath.simplifyPath(path);
    cout << res << endl;
    return 0;
}