//
// Created by daniel.yyf on 2017/8/29.
//
#include "iostream"
#include "regex"

using namespace std;

#define INT_MAX 2147483647
#define INT_MIN -2147483648
const regex pattern("\\s*([+-]?[0-9]+).*");

class Solution {
public:
    int myAtoi(string str) {
        smatch s;
        if (!regex_match(str, s, pattern)) {
            return 0;
        }
        str = s.str(1);
        bool negative = false;
        int limit = -INT_MAX;
        int result = 0;
        int currentLimit;
        int i = 0;
        int digit;

        if (str.size() > 0) {
            char c = str[0];
            if (c < '0') {
                if (c == '-') {
                    negative = true;
                    limit = INT_MIN;
                } else if (c != '+') {
                    return 0;
                }
                if (str.size() == 1)
                    return 0;
                i++;
            }
            currentLimit = limit / 10;
            while (i < str.size()) {
                digit = str[i++] - '0';
                if (digit < 0 || digit > 9)
                    return 0;
                if (result < currentLimit)
                    return negative ? limit : -limit;
                result *= 10;
                if (result < limit + digit)
                    return negative ? limit : -limit;
                result -= digit;
            }
        } else {
            return 0;
        }
        return negative ? result : -result;
    }
};