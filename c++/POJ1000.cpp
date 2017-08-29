//
// Created by daniel.yyf on 2017/8/29.
//

#include <iostream>

using namespace std;

string multiply(const string &op1, const string &op2) {
    size_t totalSize = op1.size() + op2.size();
    string re(totalSize, 0);

    for (int i = 0; i < op1.size(); i++) {
        for (int j = 0; j < op2.size(); j++) {
            re[totalSize - i - j - 1] += op1[op1.size() - i - 1] * op2[op2.size() - j - 1];
            re[totalSize - i - j - 2] += re[totalSize - i - j - 1] / 10;
            re[totalSize - i - j - 1] %= 10;
        }
    }
    return re;
}

string integerPow(const string &op1, int op2) {
    string base = op1;
    string re = "\1";
    while (op2 > 0) {
        if (op2 & 1) {
            re = multiply(re, base);
        }
        base = multiply(base, base);
        op2 = op2 >> 1;
    }
    return re.substr(1);
}

void pow(string &op1, const int op2) {
    size_t index = op1.find_last_not_of('0');
    if (index != -1)
        op1 = op1.substr(0, index + 1);

    index = op1.find('.');
    string integerPart, decimalPart;
    if (index == -1) {
        integerPart = op1;
        decimalPart = "";
    } else {
        integerPart = op1.substr(0, index);
        decimalPart = op1.substr(index + 1);
    }
    string num = integerPart + decimalPart;
    for (int i = 0; i < num.size(); i++) {
        num[i] -= '0';
    }
    string re = integerPow(num, op2);
    for (int i = 0; i < re.size(); i++) {
        re[i] += '0';
    }
    string reIntPart, reDecPart;
    int pointPosition = decimalPart.size() * op2;
    int noZeroIndex = re.find_first_not_of('0');
    if (noZeroIndex + pointPosition >= re.size()) {
        reIntPart = "";
    } else {
        reIntPart = re.substr(noZeroIndex, re.size() - pointPosition - noZeroIndex);
    }
    reDecPart = re.substr(re.size() - pointPosition);
    cout << reIntPart;
    if (!reDecPart.empty())
        cout << '.' << reDecPart;
    cout << endl;
}

