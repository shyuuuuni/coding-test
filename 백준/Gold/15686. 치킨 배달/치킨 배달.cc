/*
Time : 2022.01.27 (1 hour)
Problem : BOJ15686 (https://www.acmicpc.net/problem/15686)
Algorithm Type : Simulation
Outline :
NxN 크기의 도시가 1x1 크기의 칸들로 나누어져있다.
각 칸에는 빈 칸(0), 집(1), 치킨집(2) 으로 구성되어 있다.
(r,c)는 r행 c열 (위에서 r번째, 왼쪽에서 c번째, 1<=r,c)로 부른다.
치킨거리는 집에서 가장 가까운 치킨집과의 거리라고 한다.
도시의 치킨거리는 모든 집의 치킨 거리의 합이다.
거리는 |r1-r2| + |c1-c2| 로 구한다.
도시의 치킨집 중 최대 M개를 고르고, 나머지 치킨집을 폐업시킨다.
어떻게 골랐을 때 도시의 치킨 거리가 가장 작게 되는지 구하시오. (치킨 거리의 최솟값을 출력하라)
Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, m;
int board1[51][51];
vector<pii> home, chicken;

bool oob(int x, int y) {
  // out of bound check
  return (x<0 || y<0 || n<=x || n<=y);
}

void solve() {
  int mn = 100000000;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> board1[i][j];
      if(board1[i][j]==1) home.push_back(mp(i,j));
      else if(board1[i][j]==2) chicken.push_back(mp(i,j));
    }
  }
  vector<int> v(chicken.size(), 1); // 1이면 폐업
  for(int i=0; i<m; i++) v[i]=0; // 전체 치킨 중 m개만 0(운영)
  do {
    int distance = 0;
    for(pii h : home) {
      int chicken_dis = 100000000;
      for(int i=0; i<chicken.size(); i++) {
        if(v[i]) continue;
        chicken_dis = min(chicken_dis, abs(h.X-chicken[i].X)+abs(h.Y-chicken[i].Y));
      }
      distance += chicken_dis;
    }
    mn = min(mn, distance);
  } while(next_permutation(v.begin(), v.end()));
  cout << mn;
  return;
}