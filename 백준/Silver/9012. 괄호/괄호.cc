/*
Time : 2022.01.10 (10 min)
Problem : BOJ9012 (https://www.acmicpc.net/problem/9012)
Algorithm Type : Stack
Outline :
두개의 괄호 기호 '(' 와 ')' 로 구성되는 문자열이 주어진다.
이때 괄호의 모양이 올바르게 구성된 문자열을 VPS라고 한다.
주어진 문자열이 VPS인지 출력한다.
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
  int tc;
  cin >> tc;
  while(tc--) {
    string s;
    stack<char> stk;
    bool flag=true;
    cin >> s;
    for(auto c : s) {
      if(c == '(') {
        stk.push(c);
      } else {
        if(stk.empty()) {
          flag = false;
          break;
        } else {
          stk.pop();
        }
      }
    }
    flag = flag && stk.empty();
    cout << (flag?"YES":"NO") << "\n";
  }
  return;
}