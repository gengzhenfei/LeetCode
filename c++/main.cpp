#include <iostream>
#include <string>
#include <vector>
#include "L012IntegerToRoman.cpp"
using namespace std;

int main()
{
    int num = 3000;
    L012IntegerToRoman IntegerToRoman;
    cout << IntegerToRoman.intToRoman(num) << endl;

    return 0;
}