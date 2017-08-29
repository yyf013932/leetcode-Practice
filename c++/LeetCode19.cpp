//
// Created by daniel.yyf on 2017/8/29.
//
#include "iostream"

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *node1;
        ListNode *node2;
        node1 = head;
        for (int i = 0; i < n; i++) {
            node1 = node1->next;
        }
        if (node1 == NULL) {
            return head->next;
        }
        node1 = node1->next;
        node2 = head;
        while (node1 != NULL) {
            node1 = node1->next;
            node2 = node2->next;
        }
        node2->next = node2->next->next;
        return head;
    }
};