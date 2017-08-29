//
// Created by daniel.yyf on 2017/8/29.
//
#include <vector>
#include "iostream"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int ip = -1, sp = 0;
        while (sp < nums.size()) {
            if (ip == -1 || nums[sp] != nums[ip]) {
                nums[++ip] = nums[sp];
            }
            sp++;
        }
        return ip + 1;
    }
};