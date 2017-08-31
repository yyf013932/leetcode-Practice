//
// Created by daniel.yyf on 2017/8/30.
//
#include "iostream"
#include "queue"
#include "unordered_map"

using namespace std;

struct Node {
    char val;
    size_t index;

    Node(char c, size_t index) {
        val = c;
        this->index = index;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        queue<Node> window;
        unordered_map<char, bool> table;
        unordered_map<char, int> tableCount;
        unordered_map<char, int> windowCount;
        for (int i = 0; i < t.size(); i++) {
            table[t[i]] = true;
            tableCount[t[i]]++;
        }
        int currentCount = 0;
        size_t startIndex = 0;
        size_t length = s.size();
        for (size_t i = 0; i < s.size(); i++) {
            if (table[s[i]]) {
                windowCount[s[i]]++;
                Node node(s[i], i);
                window.push(node);
                if (currentCount < t.size()) {
                    if (windowCount[s[i]] <= tableCount[s[i]]) {
                        currentCount++;
                    }
                }
                while (windowCount[window.front().val] > tableCount[window.front().val]) {
                    windowCount[window.front().val]--;
                    window.pop();
                }
                if (currentCount == t.size() && length > (window.back().index - window.front().index)) {
                    startIndex = window.front().index;
                    length = window.back().index - startIndex + 1;
                }
            }
        }
        if (currentCount < t.size()) {
            return "";
        }
        return s.substr(startIndex, length);
    }
};