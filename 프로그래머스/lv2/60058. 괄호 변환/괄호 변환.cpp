#include <bits/stdc++.h>

using namespace std;

bool solve(string &s, int st, int en) {
    // 3번-4번 조건 (올바른 괄호 문자열 체크)
    if (en <= st) return "";
    bool result = true;
    stack<char> stk;
    for (int i=st; i<=en; i++) {
        char c = s[i];
        if (stk.empty()) {
            if (c == ')') {
                result = false;
                break;
            } else {
                stk.push(c);
            }
        } else {
            if (c == ')') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
    }
    if (!result) {
        for (int i=st+1; i<=en-1; i++) {
            if (s[i] == '(') s[i] = ')';
            else s[i] = '(';
        }
    }
    return result;
}

// [st,en] 범위를 처리
// [0, 5] : 0,1,2,3,4,5 -> 길이 = 5 - 0 + 1 = 6
string divide_and_conqure(string &s, int st, int en) {
    string result = "";
    
    // 1번 조건
    if (en-st+1 <= 0) {
        return result;
    }
    
    // 2번 조건
    int le = 0, ri = 0;
    int mid = en;
    for (int i=st; i<=en; i++) {
        if (s[i] == '(') le++;
        else if (s[i] == ')') ri++;
        if (le && ri && le==ri) {
            mid = i;
            break;
        }
    }
    
    // [st, mid] [mid, en]으로 분리
    bool res = solve(s, st, mid);
    string u, v;
    
    if (res) {
        u = s.substr(st, le+ri);
        v = divide_and_conqure(s, mid+1, en);
        return u + v;
    } else {
        u = s.substr(st+1, le+ri-2);
        v = divide_and_conqure(s, mid+1, en);
        return "(" + v + ")" + u;
    }
}

string solution(string p) {
    string answer = "";
    
    answer = divide_and_conqure(p, 0, (int)p.size()-1);
    
    return answer;
}