//
// Created by daniel.yyf on 2017/8/29.
//
#include "iostream"
#include "string"
#include "vector"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> v;
        int count1, count2, count3;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    v.push_back(s[i]);
                    break;
                case ')':
                case '}':
                case ']':
                    if (v.empty() || v.back() != (s[i] - s[i] / 90 - 1))
                        return false;
                    v.pop_back();
                    break;
                default:
                    return false;
            }
        }
        return v.empty();
    }
};