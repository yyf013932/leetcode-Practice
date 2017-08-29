//
// Created by daniel.yyf on 2017/8/16.
//

#include "vector"

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        heights.push_back(0);
        int re = 0;
        vector<int> modifyHeightsIndex;
        for (int i = 0; i < heights.size(); i++) {
            int k = heights[i];
            while (!modifyHeightsIndex.empty() && k <= heights[modifyHeightsIndex.back()]) {
                int index = modifyHeightsIndex.back();
                int h = heights[index];
                modifyHeightsIndex.pop_back();

                int wid = modifyHeightsIndex.empty() ? i : i - modifyHeightsIndex.back() - 1;
                if (h * wid > re)
                    re = h * wid;
            }
            modifyHeightsIndex.push_back(i);
        }
        return re;
    }
};

