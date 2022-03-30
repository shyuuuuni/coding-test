/*
Time : 2022.01.10 (10 min)
Problem : BOJ10799 (https://www.acmicpc.net/problem/10799)
Algorithm Type : Stack
Outline :
쇠막대기를 레이저로 자르는 모양을 괄호로 표현한다.
레이저는 인접한 괄호쌍 () 로 표현한다.
쇠막대기는 시작점이 여는 괄호, 끝점이 닫는 괄호로 표현한다.
괄호 표현이 주어졌을 때, 쇠막대기가 총 몇개로 조각나는지 표현한다.
Method :
스택을 이용하여 해결한다.
스택에는 여는 괄호 '('를 저장한다.
만약 문자열을 순회하면서 닫는 괄호를 만난다면 스택을 pop한다.
만약 스택이 비어있을 때 닫는 괄호를 만나거나,
모든 문자열을 순회했을 때 스택이 비어있지 않는다면 VPS가 아닌 것으로 판단한다.
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
  int ans=0;
  string s;
  stack<char> stk;
  char prv = 'x';
  cin >> s;
  for(auto c : s) {
    if(c == '(') {
      stk.push(c);
    } else {
      if(stk.empty()) continue;
      else if(stk.top() == '(') {
        stk.pop();
        if(prv == '(') ans += stk.size();
        if(prv == ')') ans++;
      }
    }
    prv = c;
  }
  cout << ans;
  return;
}