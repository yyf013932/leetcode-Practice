//
// Created by daniel.yyf on 2017/8/15.
//

#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> m;
        int max = 0;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (m[*it])
                continue;
            int before = m[*it - 1];
            int after = m[*it + 1];
            int tem;
            tem = m[*it] = m[*it - before] = m[*it + after] = before + after + 1;
            if (tem > max)
                max = tem;
        }
        return max;
    }
};