/*
Time : 2022.01.19 (25 min)
Problem : BOJ1600 (https://www.acmicpc.net/problem/1600)
Algorithm Type : BFS
Outline :
W*H 크기의 격자판에 장애물이 주어진다.
원숭이는 체스의 나이트와 같이 K번 움직일 수 있다.
격자판의 왼쪽 위에서 맨 오른쪽 아래까지 가는 최소 동작수를 출력한다.
Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int hx[8] = {1,2,2,1,-1,-2,-2,-1};
int hy[8] = {2,1,-1,-2,-2,-1,1,2};
void solve() {
  int k, w, h; // 나이트 횟수, 가로, 세로
  vector<vector<int> > tile(200+1, vector<int>(200+1));
  int dist[30+1][200+1][200+1];
  queue<pair<pii, int> > q; // ((x,y), jump)

  fill(&dist[0][0][0], &dist[30][200][201], -1);
  cin >> k;
  cin >> w >> h;
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> tile[i][j];
    }
  }

  dist[0][0][0] = 0;
  q.push(mp(mp(0,0),0));

  while(!q.empty()) {
    int x = q.front().first.X;
    int y = q.front().first.Y;
    int jump = q.front().second;
    // cout << x << " " << y << " " << jump << "\n";
    q.pop();
    if(jump < k) {
      for(int i=0; i<8; i++) {
        int xx = x + hx[i];
        int yy = y + hy[i];
        if(xx<0 || yy<0 || h<=xx || w<=yy) continue;
        if(tile[xx][yy] == 1) continue;
        if(dist[jump+1][xx][yy]!=-1 && dist[jump+1][xx][yy] <= dist[jump][x][y]+1) continue;
        dist[jump+1][xx][yy] = dist[jump][x][y]+1;
        q.push(mp(mp(xx,yy), jump+1));
      }
    }
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || yy<0 || h<=xx || w<=yy) continue;
      if(tile[xx][yy] == 1) continue;
      if(dist[jump][xx][yy]!=-1 && dist[jump][xx][yy] <= dist[jump][x][y]+1) continue;
      dist[jump][xx][yy] = dist[jump][x][y]+1;
      q.push(mp(mp(xx,yy), jump));
    }
  }

  int ans=100000000;
  for(int i=0; i<=k; i++) {
    if(dist[i][h-1][w-1] != -1) {
      ans = min(ans, dist[i][h-1][w-1]);
    }
  }

  cout << (ans==100000000?-1:ans);
  return;
}
