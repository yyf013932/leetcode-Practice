//
// Created by daniel.yyf on 2017/8/30.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return head;
        ListNode *p1 = head, *p2 = head, *p3 = head, *p4, *p5;
        int length = 0;
        while (p2 != NULL) {
            p2 = p2->next;
            length++;
        }
        k %= length;
        p2 = head;
        if (k == 0)
            return head;
        for (int i = 0; i < k; i++) {
            p2 = p2->next;
            if (p2 == NULL)
                return p1;
        }
        while (p2 != NULL) {
            p5 = p2;
            p2 = p2->next;
            p4 = p3;
            p3 = p3->next;
        }
        p5->next = p1;
        p4->next = NULL;
        return p3;
    }
};