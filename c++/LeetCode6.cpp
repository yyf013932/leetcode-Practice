//
// Created by daniel.yyf on 2017/8/30.
//
#include "iostream"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int length = s.size();
        if(numRows==1)
            return s;
        string str(length, ' ');
        int index = 0;
        for (int i = 0; i < numRows; i++) {
            int j = 0;
            if (i != numRows - 1 && i != 0) {
                while (true) {
                    if (2 * j * (numRows - 1) + i >= length) {
                        break;
                    }
                    str[index++] = s[2 * j * (numRows - 1) + i];
                    if (2 * (j + 1) * (numRows - 1) - i >= length) {
                        break;
                    }
                    str[index++] = s[2 * (j + 1) * (numRows - 1) - i];
                    j++;
                }
            } else {
                while (true) {
                    if (2 * j * (numRows - 1) + i >= length)
                        break;
                    str[index++] = s[2 * j * (numRows - 1) + i];
                    j++;
                }
            }
        }
        return str;
    }
};