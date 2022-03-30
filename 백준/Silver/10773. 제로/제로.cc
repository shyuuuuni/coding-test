/*
Time : 2022.01.07 (5 min)
Problem : BOJ10773 (https://www.acmicpc.net/problem/10773)
Algorithm Type : Stack
Outline :
재현이가 잘못된 수를 부를때마다 0을 외치면 가장 최근에 쓴 수를 지운다.
모든 수를 받아 적은 후 그 수의 합을 출력한다.
Method :
스택을 이용하여 정수를 저장한다. 0이 들어오면 맨 위의 정수를 pop 하고,
모든 연산이 끝나고 스택에서 모든 정수를 빼서 더한다.
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
  long long ans=0;
  stack<long long> stk;
  cin >> tc;
  while(tc--) {
    long long num;
    cin >> num;
    if(num) stk.push(num);
    else stk.pop();
  }
  while(!stk.empty()) {
    ans+=stk.top();
    stk.pop();
  }
  cout << ans;
  return;
}