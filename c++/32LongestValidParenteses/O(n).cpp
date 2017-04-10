class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> leftParenthesInfo, sizeInfo;
        string::iterator iterator1 = s.begin(), endIt = s.end();
        int temSize = 0;
        int maxSize;
        int mainSize=0;
        while (iterator1 != s.end()) {
            if (*iterator1 == ')') {
                if (mainSize==0) {
                    sizeInfo.push_back(temSize);
                    temSize = 0;
                    iterator1++;
                    while (iterator1 != endIt && *iterator1 == ')') {
                        iterator1++;
                    }
                } else {
                    mainSize--;
                    temSize += 2;
                    if (!leftParenthesInfo.empty() && mainSize == leftParenthesInfo.back()) {
                        leftParenthesInfo.pop_back();
                        temSize += sizeInfo.back();
                        sizeInfo.pop_back();
                    }
                    iterator1++;
                }
            } else {
                sizeInfo.push_back(temSize);
                temSize = 0;
                leftParenthesInfo.push_back(mainSize);
                while (iterator1 != endIt && *iterator1 == '(') {
                    mainSize++;
                    iterator1++;
                }
            }
        }
        maxSize = temSize;
        for (auto size:sizeInfo) {
            maxSize = max(size, maxSize);
        }
        return maxSize;
    }
};