/*
Time : 2022.01.11 (15 min)
Problem : BOJ7576 (https://www.acmicpc.net/problem/7576)
Algorithm Type : BFS
Outline :
NxM 크기의 창고에 토마토를 보관한다.
토마토는 잘 익은 토마토와 익지 않은 토마토가 있다.
잘 익은 토마토는 하루마다 주위(상하좌우) 토마토를 익도록 만든다.
창고에 보관한 토마토가 며칠만에 다 익는지 출력한다. 만약 모두 익히지 못하면 -1을 출력한다.
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

int dist[1000+2][1000+2], arr[1000+2][1000+2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, ans=0;
queue<pii> q;

void solve() {
  cin >> m >> n;
  for(int i=0; i<n; i++) {
    fill(dist[i], dist[i]+m, -1);
    for(int j=0; j<m; j++) {
      cin >> arr[i][j];
      if(arr[i][j] == 1) {
        dist[i][j] = 0;
        q.push(mp(i,j));
      }
    }
  }
  while(!q.empty()) {
    pii cur = q.front();
    q.pop();

    int x = cur.X;
    int y = cur.Y;
    int d = dist[x][y];
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || n<=xx || yy<0 || m<=yy) continue;
      if(arr[xx][yy] == -1 || dist[xx][yy] != -1) continue;
      dist[xx][yy] = d + 1;
      q.push(mp(xx,yy));
    }
  }

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      ans = max(ans, dist[i][j]);
      if(arr[i][j] == 0 && dist[i][j] == -1) {
        cout << "-1";
        return;
      }
    }
  }
  cout << ans;

  return;
}