/*
Time : 2022.01.21 (15 min)
Problem : BOJ15654 (https://www.acmicpc.net/problem/15654)
Algorithm Type : Backtracking
Outline :
N개의 자연수가 주어졌을 때, M개를 고른 수열을 출력한다.
Method :
기존 문제에서 자연수를 입력받는다.
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
vector<int> v, ans, issued;

void func(int cur) {
  // cur : 총 몇개 들어갔는지
  if(cur == m) {
    for(int i=0; i<m; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  
  for(int i=0; i<n; i++) {
    if(!issued[i]) {
      issued[i] = 1;
      ans[cur] = v[i];
      func(cur+1);
      ans[cur] = 0;
      issued[i] = 0;
    }
  }

  return;
}

void solve() {
  cin >> n >> m;
  v.resize(n);
  issued.resize(n);
  ans.resize(m);
  for(int i=0; i<n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  func(0);
  return;
}