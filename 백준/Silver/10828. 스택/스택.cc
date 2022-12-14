/*
Time : 2022.01.07 (15 min)
Problem : BOJ10828 (https://www.acmicpc.net/problem/10828)
Algorithm Type : Stack
Outline :
스택을 구현한 후 입력으로 주어지는 명령을 처리한다.
Method :
STL 스택을 이용하여 구현하였다.
pop과 top 명령어시 -1을 출력하는 부분만 추가로 신경쓰면 되는 간단한 구현이다.
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
  int tc, n;
  string s;
  stack<int> stk;
  cin >> tc;
  while(tc--) {
    cin >> s;
    if(s == "push") {
      cin >> n;
      stk.push(n);
    } else if(s == "pop") {
      if(stk.empty()) cout << -1 << "\n";
      else {
        cout << stk.top() << "\n";
        stk.pop();
      }
    } else if(s == "size") {
      cout << stk.size() << "\n";
    } else if(s == "empty") {
      cout << (int)stk.empty() << "\n";
    } else {
      if(stk.empty()) cout << -1 << "\n";
      else cout << stk.top() << "\n";
    }
  }
  return;
}