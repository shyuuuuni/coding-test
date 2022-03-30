/*
Time : 2022.01.07 (20 min)
Problem : BOJ2493 (https://www.acmicpc.net/problem/2493)
Algorithm Type : Stack
Outline :

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

int ans[500000+1];
void solve1() {
  int tc, n;
  stack<pair<int,int> > towers, buf;
  cin >> tc;
  for(int i=1; i<=tc; i++) {
    cin >> n;
    towers.push(make_pair(n, i));
  }
  while(!towers.empty()) {
    pair<int,int> cur = towers.top();
    towers.pop();
    if(buf.empty() || cur.first < buf.top().first) {
      buf.push(cur);
    } else {
      while(!buf.empty() && buf.top().first < cur.first) {
        ans[buf.top().second] = cur.second;
        buf.pop();
      }
      buf.push(cur);
    }
  }
  for(int i=1; i<=tc; i++) {
    cout << ans[i] << " ";
  }
  return;
}