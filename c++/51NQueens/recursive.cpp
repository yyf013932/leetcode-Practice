
class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> re;
        vector<int> info;
        putIn(0, n, info, re);
        return re;
    }

    void putIn(int row, int n, vector<int> &info, vector<vector<string>> &re) {
        for (int i = 0; i < n; i++) {
            if (check(info, row, i)) {
                info.push_back(i);
                //最后一行
                if (row == n - 1) {
                    addRe(info, re, n);
                } else {
                    putIn(row + 1, n, info, re);
                }
                info.pop_back();
            }
        }
    }

    bool check(vector<int> &info, int x, int y) {
        int s = info.size();
        for (int i = 0; i < s; i++) {
            if (y == info[i] || (abs(x - i) == abs(y - info[i])))
                return false;
        }
        return true;
    }

    void addRe(vector<int> &info, vector<vector<string>> &re, int n) {
        vector<string> tem;
        for (vector<int>::iterator i1 = info.begin(); i1 != info.end(); i1++) {
            tem.push_back(createRow(n, *i1));
        }
        re.push_back(tem);
    }

    string createRow(string::size_type length, string::size_type index) {
        string base(length, '.');
        base[index] = 'Q';
        return base;
    }
};
