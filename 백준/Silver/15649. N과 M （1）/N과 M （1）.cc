/*
Time : 2022.01.21 (30 min)
Problem : BOJ15649 (https://www.acmicpc.net/problem/15649)
Algorithm Type : Backtracking
Outline :
N과 M이 주어졌을 때 1~N의 수 중에서 중복 없이 M개를 고른 수열을 모두 출력한다.
Method :
재귀를 사용한 백트래킹 알고리즘을 사용하였다.
btacking(cur) 함수에서 cur는 현재 수열에 저장한 수의 숫자를 의미한다.
만약 cur == m 이라는 뜻은 수열이 꽉 찼으므로 출력하고 리턴한다.
그렇지 않으면 1~N사이의 수 중에서 방문하지 않은(!vis[i]) 번호에 대하여
1. 해당 번호를 수열에 포함시킨다.
2. 해당 번호를 수열에 포함시키지 않는다.
두 경우를 백트래킹을 이용하여 모두 탐색한다.
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
int vis[8+1];
int out[8+1];
void btracking(int cur) {
  // cur : 저장할 인덱스
  if(cur == m) {
    for(int i=0; i<m; i++) {
      cout << out[i] << " ";
    }
    cout << "\n";
    return;
  }
  for(int i=1; i<=n; i++) {
    if(vis[i]) continue;
    vis[i] = 1;
    out[cur] = i;
    btracking(cur+1);
    vis[i] = 0;
  }
}
void solve() {
  cin >> n >> m;
  btracking(0);
  return;
}