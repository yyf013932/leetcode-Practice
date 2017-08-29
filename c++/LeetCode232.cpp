//
// Created by daniel.yyf on 2017/8/29.
//
#include <vector>
#include "iostream"


using namespace std;

class MyQueue {
    vector<int> stack;
    vector<int> mediaStack;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push_back(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!stack.empty()){
            int out = stack.back();
            mediaStack.push_back(out);
            stack.pop_back();
        }
        int rt = mediaStack.back();
        mediaStack.pop_back();
        while(!mediaStack.empty()){
            int out = mediaStack.back();
            stack.push_back(out);
            mediaStack.pop_back();
        }
        return rt;
    }

    /** Get the front element. */
    int peek() {
        return stack.front();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */