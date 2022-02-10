#include <iostream>
#include <string>
#include <vector>
using namespace std;

class L071SimplifyPath
{
private:
    /* data */
public:
    L071SimplifyPath(/* args */);
    ~L071SimplifyPath();

    string simplifyPath(string path)
    {
        vector<string> dir;
        int len = path.size();
        for (int i = 1; i < len; i++) { // 绝对路径拆分成目录
            string d;
            while (i < len && path[i] != '/') { d += path[i++]; }
            if (d.size() > 0) dir.push_back(d);
        }
        for (int i = 0; i < dir.size(); i++) { cout << "i:" << i << " " << dir[i] << endl; }
        int i = 0;
        int end = dir.size() - 1;
        while (i <= end) { // 从0开始遍历到最后一个目录或文件
            cout << "i:" << i << " end:" << end << endl;
            if (dir[i] == ".") { // . 则表示当前目录
                dir.erase(dir.begin() + i);
                end = dir.size() - 1;
            } else if (dir[i] == "..") { // .. 则表示上一层目录
                if (i == 0) {
                    dir.erase(dir.begin() + i);
                    end = dir.size() - 1;
                } else {
                    // erase (iterator first, iterator last);
                    // 删除 [first,last) 之间的元素，注意不包含last
                    dir.erase(dir.begin() + i - 1, dir.begin() + i + 1);
                    end = dir.size() - 1;
                    i--;
                }
            } else { // 文件/目录名称
                i++;
            }
        }
        if (dir.size() == 0) return "/";
        string res; // 将目录拼接成绝对路径
        for (string s : dir) { res += "/" + s; }
        return res;
    }
};

L071SimplifyPath::L071SimplifyPath(/* args */) {}

L071SimplifyPath::~L071SimplifyPath() {}

// main.cpp
// 调试时将以下代码放入main.cpp文件
// #include <iostream>
// #include "L071SimplifyPath.cpp"
// using namespace std;

// int main()
// {
//     string path = "/a//b////c/d//././/..";
//     L071SimplifyPath SimplifyPath;
//     string res = SimplifyPath.simplifyPath(path);
//     cout << res << endl;
//     return 0;
// }