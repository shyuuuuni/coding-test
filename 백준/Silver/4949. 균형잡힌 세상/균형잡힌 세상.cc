/*
Time : 2022.01.10 (10 min)
Problem : BOJ4949 (https://www.acmicpc.net/problem/4949)
Algorithm Type : Stack
Outline :
주어진 문자열에 대해서 괄호가 잘 열고 닫히는지 확인한다.
Method :
스택을 이용해서 해결하였다.
스택에는 가장 마지막으로 나온 여는 괄호 '(', '[' 를 보관하는데,
만약 문자열을 읽어가다가 닫는 괄호 ')', ']'가 나온다면, 해당 스택의 Top을 확인한다.
잘 열고 닫히는 괄호는 마지막에 나온 괄호의 종류가 같아야 한다.
또한 모든 문자열을 읽었을 때 스택에 닫히지 않은 괄호가 존재하면 안된다.
*/
#include <bits/stdc++.h>
using namespace std;
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

void solve1() {
  string s;
  
  do {
    getline(cin, s);
    stack<char> stk;
    bool flag = true;
    if(s == ".") break;
    for(auto c : s) {
      if(!flag) break;
      if(c == '(' || c == '[') stk.push(c);
      else if(c == ')') {
        flag = (!stk.empty() && stk.top()=='(');
        if(flag) stk.pop();
      } else if(c == ']') {
        flag = (!stk.empty() && stk.top()=='[');
        if(flag) stk.pop();
      } else if(c == '.') break;
    }
    flag = flag && stk.empty();
    cout << (flag?"yes":"no") << "\n";
  } while(s != ".");
  return;
}