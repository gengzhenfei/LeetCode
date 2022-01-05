#include <string>
#include <vector>
#include <cmath>
using namespace std;

class L012IntegerToRoman
{
private:
    /* data */
public:
    L012IntegerToRoman(/* args */);
    ~L012IntegerToRoman();

    string intToRoman(int num)
    {
        // 先将整数每一位提取
        vector<int> v_nums;
        while (num > 0) {
            v_nums.push_back(num % 10);
            num /= 10;
        }
        // 整数位数
        int v_len = v_nums.size();
        if (v_len > 4) return "";
        // 转化
        string result = "";
        for (int i = 0; i < v_len; i++) {
            int tmp = v_nums[i] * pow(10, i);
            result = mapFromIntToRoman(tmp) + result;
        }

        return result;
    }

    string mapFromIntToRoman(int i)
    {
        switch (i) {
        case 1: return "I";
        case 2: return "II";
        case 3: return "III";
        case 4: return "IV";
        case 5: return "V";
        case 6: return "VI";
        case 7: return "VII";
        case 8: return "VIII";
        case 9: return "IX";
        case 10: return "X";
        case 20: return "XX";
        case 30: return "XXX";
        case 40: return "XL";
        case 50: return "L";
        case 60: return "LX";
        case 70: return "LXX";
        case 80: return "LXXX";
        case 90: return "XC";
        case 100: return "C";
        case 200: return "CC";
        case 300: return "CCC";
        case 400: return "CD";
        case 500: return "D";
        case 600: return "DC";
        case 700: return "DCC";
        case 800: return "DCCC";
        case 900: return "CM";
        case 1000: return "M";
        case 2000: return "MM";
        case 3000: return "MMM";

        default: return "";
        }
    }
};

L012IntegerToRoman::L012IntegerToRoman(/* args */) {}

L012IntegerToRoman::~L012IntegerToRoman() {}

// #include <iostream>
// #include <string>
// #include <vector>
// #include "L012IntegerToRoman.cpp"
// using namespace std;

// int main()
// {
//     int num = 3000;
//     L012IntegerToRoman IntegerToRoman;
//     cout << IntegerToRoman.intToRoman(num) << endl;

//     return 0;
// }