//
// Created by daniel.yyf on 2017/8/30.
//
#include <vector>
#include "iostream"

using namespace std;

#define INT_MAX 0x7FFFFFFF

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> mark(128, 0);
        for (auto c:t) mark[c]++;
        int counter = t.size(), begin = 0, end = 0, head = 0, length = INT_MAX;
        while (end < s.size()) {
            if (mark[s[end++]]-- > 0)counter--;
            while (0 == counter) {
                if (end - begin < length)length = end - (head = begin);
                if (mark[s[begin++]]++ == 0) counter++;
            }
        }
        return length == INT_MAX ? "" : s.substr(head, length);

    }
};