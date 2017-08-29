//
// Created by daniel.yyf on 2017/8/14.
//
#include "iostream"
#include "unordered_map"
#include "string"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

inline int max(int a, int b) {
    return a > b ? a : b;
}

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int re = 0x80000000;
        maxPathSumToRoot(root, re);
        return re;
    }

    int maxPathSumToRoot(TreeNode *root, int &re) {
        if (!root)
            return 0;
        int lv = maxPathSumToRoot(root->left, re);
        int rv = maxPathSumToRoot(root->right, re);
        lv = max(lv, 0);
        rv = max(rv, 0);
        re = max(re, lv + rv + root->val);
        return max(lv,rv)+root->val;
    }
};