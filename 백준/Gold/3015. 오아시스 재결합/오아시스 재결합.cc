/*
Time : 2022.01.08 (10+ hours)
Problem : BOJ3015 (https://www.acmicpc.net/problem/3015)
Algorithm Type : Stack
Outline :
N명이 한줄로 서서 기다리고 있다.
사람 A와 B 사이에 둘중 하나보다 키가 큰 사람이 없으면 서로 볼 수 있다.
줄에 서있는 사람의 키들이 주어졌을 때, 서로 불 수 있는 쌍의 수를 출력한다.
Method :
*/
#include <bits/stdc++.h>
using namespace std;
int solve1();
int solve2();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  return solve1();
}

int solve1() {
  long long ans=0, cnt, n, i, h;
  stack<pair<int,int> > stk;
  // stk : 지금까지 본 사람들 중에서 stk.top()보다 큰 값이 없도록 유지.
  // stk : [5 5 4 4 1(top)] 이런식, 만약 2라는 값이 들어오면 1을 빼고 2를 넣어준다.
  cin >> n;
  for(i=0; i<n; i++) {
    cin >> h;
    cnt = 1;
    while(!stk.empty() && stk.top().first <= h) {
      ans += stk.top().second; // top -> 현재 사람 보는 경우 처리
      if(stk.top().first == h) { // top과 현재 사람의 키가 같은 경우
        cnt += stk.top().second;
      } else {
        cnt = 1;
      }
      stk.pop();
    }
    if(!stk.empty()) ans++;
    stk.push(make_pair(h, cnt));
  }
  cout << ans;
  return 0;
}