/*
Time : 2022.01.21 (15 min)
Problem : BOJ15663 (https://www.acmicpc.net/problem/15663)
Algorithm Type : Backtracking
Outline :
N개의 자연수가 주어졌을 때, M개를 M개를 고른 수열을 출력한다.
Method :
기존 문제에서 자연수를 입력받는다.
v라는 벡터에 모든 자연수를 입력받는다. 입력 이후 v를 오름차순 정렬한다.
ans는 크기 m의 벡터로, 가득 찼을 경우 수열을 출력하기 위한 벡터이다.
func(cur)는 cur개가 입력되어 있는 수열에서 새로운 원소를 추가한다.
for문을 이용하여 중복을 허용하므로 비내림차순인 노드를 추가로 탐색한다.
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

int n, m, cnt=0;
vector<int> v, ans, issued;
set<int> s;

void func(int cur) {
  // cur : 총 몇개 들어갔는지
  int prv = -1;
  if(cur == m) {
    for(int i=0; i<m; i++) cout << ans[i] << " ";
    cout << "\n";
    return;
  }
  for(int i=0; i<n; i++) {
    if(!issued[i] && prv!=v[i]) {
      issued[i] = 1;
      ans[cur] = v[i];
      prv=v[i];
      func(cur+1);
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
  sort(v.begin(),v.end());
  func(0);
  return;
}