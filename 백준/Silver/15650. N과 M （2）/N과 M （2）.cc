/*
Time : 2022.01.21 (15 min)
Problem : BOJ15650 (https://www.acmicpc.net/problem/15650)
Algorithm Type : Backtracking
Outline :
1~N까지 자연수 중에서 중복없이 M개를 골랐을 때,
오름차순인 수열을 모두 출력한다.
Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
using ll = long long;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void solve();

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, m;
int issued[8+1];

void func(int num, int cur) {
  
  if(m == cur) {
    for(int i=1; i<=n; i++) {
      if(issued[i]) cout << i << " ";
    }
    cout << "\n";
    return;
  }
  if(n < num) return;
  issued[num] = 1;
  func(num+1, cur+1);
  issued[num] = 0;
  func(num+1, cur);
  return;
}

void solve() {
  cin >> n >> m;
  func(1, 0);
  return;
}