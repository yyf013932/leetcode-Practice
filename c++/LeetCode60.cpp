//
// Created by daniel.yyf on 2017/8/30.
//
#include "iostream"

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string str(n, ' ');
        int convertTem = k - 1;
        for (int i = 1; i <= n; i++) {
            str[n - i] = convertTem % i + '1';
            convertTem /= i;
        }
        for (int i = str.size() - 2; i >= 0; i--) {
            for (int j = i + 1; j < str.size(); j++) {
                if (str[j] >= str[i])
                    str[j]++;
            }
        }
        return str;
    }
};