#include "header.h"
#include "math.h"

int getNum(string& s, int& i){
    string tmp = "";
    while(s[i] != '.'){
        if(tmp != "" && s[i] == '0') tmp += s[i];
        i++;
    }

    i++;
    return stoi(tmp);
}

int traverse(string& s1, string& s2, int& i, int& j){
    if(i == s1.size() && j == s2.size()) return 0;

    int n1 = getNum(s1, i);
    int n2 = getNum(s2, j);

    if(n1 == n2) return traverse(s1, s2, i, j);
    else return n1 > n2 ? 1 : -1;
}

int solution(string s1, string s2){
    int i = 0;
    int j = 0;
    return traverse(s1, s2, i, j);
}