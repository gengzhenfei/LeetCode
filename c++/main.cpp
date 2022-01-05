#include <iostream>
#include <string>
#include <vector>
#include "L012IntegerToRoman.cpp"
#include "L013RomanToInteger.cpp"
using namespace std;

int main()
{
    int num = 1994;
    L012IntegerToRoman IntegerToRoman;
    string roman = IntegerToRoman.intToRoman(num);
    cout << roman << endl;
    L013RomanToInteger RomanToInteger;
    cout << RomanToInteger.romanToInt(roman) << endl;

    return 0;
}