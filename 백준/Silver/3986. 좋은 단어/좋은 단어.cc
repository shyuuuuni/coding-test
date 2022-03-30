/*
Time : 2022.01.10 (10 min)
Problem : BOJ3986 (https://www.acmicpc.net/problem/3986)
Algorithm Type : Stack
Outline :
A와 B로 이루어진 문자열이 주어진다.
문자열의 각 문자 위로 아치형 곡선을 그어 같은 글자끼리 쌍을 짓기로 한다.
문자열의 모든 문자를 선끼리 교차하지 않고 짝 지을 수 있다면 좋은 문자라고 한다.
좋은 문자 수를 출력한다.
Method :

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
  int n, ans=0;
  string s;
  cin >> n;
  while(n--) {
    cin >> s;
    stack<char> stk;
    for(auto c : s) {
      if(stk.empty()) stk.push(c);
      else if(stk.top() == 'A') {
        if(c == 'A') {
          stk.pop();
        } else {
          stk.push(c);
        }
      } else if(stk.top() == 'B') {
        if(c == 'B') {
          stk.pop();
        } else {
          stk.push(c);
        }
      }
    }
    if(stk.empty()) ans++;
  }
  cout << ans;
  return;
}