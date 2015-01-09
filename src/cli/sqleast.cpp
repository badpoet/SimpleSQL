#ifndef CLI_SQLEAST_H
#define CLI_SQLEAST_H

#include <string>
#include <iostream>

#include "sm/dbmanager.h"
#include "ql/parser.h"

using namespace std;
using namespace sqleast;

ql::Parser parser;

string beautiful(string &s) {
    string t = "";
    int k = -1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r') {
            if (k == -1 || t[k] == ' ') {

            } else {
                t += ' ';
                k += 1;
            }
        } else {
            t += s[i];
            k += 1;
        }
    }
    return t;
}

int main() {
    cout << "WELCOME TO SQLEAST" << endl;
    while (true) {
        cout << "[SQLEAST] $ " << endl;
        string s = "";
        char c;

        while ((c = getchar()) != ';') s += c;
        if (beautiful(s) == "QUIT") {
            cout << "Bye" << endl;
            break;
        }

        ql::StructuredQuery *q = parser.parse(beautiful(s));
        if (q == nullptr) {
            std::cout << "ERROR: can not parse";
        } else {
            q->execute();
        }
    }
    return 0;
}

#endif