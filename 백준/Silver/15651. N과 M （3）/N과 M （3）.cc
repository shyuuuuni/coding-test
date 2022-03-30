/*
Time : 2022.01.21 (15 min)
Problem : BOJ15651 (https://www.acmicpc.net/problem/15651)
Algorithm Type : Backtracking
Outline :
1~N까지 자연수 중에서 중복을 허용하여 M개를 고른 수열을 모두 출력한다.
Method :
이전 문제와 다르게 {1,2} = {2,1}로 생각한다.
즉 한번 방문한 숫자를 다시 방문하지 않는다고 생각하고 백트래킹한다.
따라서 func함수의 보고있는 숫자를 순서대로 1,2,3,...,N까지 보면 된다.
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
int ans[8+1];

void func(int cur) {
  if(cur==m) {
    for(int i=0; i<m; i++)
      cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  for(int i=1; i<=n; i++) {
    ans[cur] = i;
    func(cur+1);
  }
  return;
}

void solve() {
  cin >> n >> m;
  func(0);
  return;
}