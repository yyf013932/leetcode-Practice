//
// Created by daniel.yyf on 2017/8/29.
//
#include "iostream"
#include<algorithm>
#include "vector"

using namespace std;

class Solution {
    void solution() {
        int data[100][100][2];
        int testCases, n;
        int m[100];
        cin >> testCases;
        for (int i = 0; i < testCases; i++) {
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> m[j];
                for (int k = 0; k < m[j]; k++) {
                    cin >> data[j][k][0] >> data[j][k][1];
                }
            }
            solve(data, n, m);
        }
    }

    void solve(int data[100][100][2], int n, int m[]) {

    }

};

