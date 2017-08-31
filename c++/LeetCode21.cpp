//
// Created by daniel.yyf on 2017/8/30.
//
#include "iostream"

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *head, *toConcat, *other, *tem;
        if (l1->val > l2->val) {
            head = toConcat = l2;
            other = l1;
        } else {
            head = toConcat = l1;
            other = l2;
        }
        while (true) {
            if (other == NULL) {
                return head;
            }
            if (toConcat->next == NULL) {
                toConcat->next = other;
                return head;
            }
            if (toConcat->next->val > other->val) {
                tem = toConcat->next;
                toConcat->next = other;
                other = other->next;
                toConcat = toConcat->next;
                toConcat->next = tem;
            } else {
                toConcat = toConcat->next;
            }
        }
    }
};