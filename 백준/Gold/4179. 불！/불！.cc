/*
Time : 2022.01.11 (20 min)
Problem : BOJ4179 (https://www.acmicpc.net/problem/4179)
Algorithm Type : BFS
Outline :
미로에 지훈이와 불이 매 분마다 수평 혹은 수직으로 이동한다.
불은 각 지점의 상하좌우로 확산한다.
지훈이가 미로에서 탈출하려면 미로에 가장자리에 접한 공간으로 가야 한다.
벽(#), 지나갈 수 있는 공간(.), 지훈이(J), 불이 난 공간(F)으로 주어졌을 때
가장 빠른 탈출시간을 출력한다.
Method :
BFS를 이용하여 해결한다.
dist[i][j] : (i,j) 위치의 토마토가 다 익는데 필요한 일 수 (또는 -1)
입력으로 들어온 토마토에서 만약 익은 토마토가 들어있다면 해당 좌표를 큐에 넣고 BFS를 시행한다.
이때 해당 위치의 dist는 0으로 초기화한다.
이런식으로 반복하면 각각의 익은 토마토에서 주변의 익지 않은 토마토를 익게 하는 최소 일수가
dist 배열에 저장된다.
모든 BFS가 끝나면 이중 배열을 순회하면서 모든 토마토가 익는 최소 일수를 계산하면서
만약 익지 않은 토마토가 존재한다면 -1을 출력한다.
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

int df[1000+2][1000+2], dj[1000+2][1000+2];
string arr[1000+2];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, ans=0;
queue<pii> jq, fq;

void solve() {
  int flag = 0;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    fill(df[i], df[i]+m, -1);
    fill(dj[i], dj[i]+m, -1);
    cin >> arr[i];
    for(int j=0; j<m; j++) {
      if(arr[i][j] == 'J') {
        jq.push(mp(i,j));
        dj[i][j] = 1;
      } else if(arr[i][j] == 'F') {
        fq.push(mp(i,j));
        df[i][j] = 1;
      }
    }
  }
  while(!fq.empty()) {
    pii cur = fq.front();
    fq.pop();
    int x = cur.X;
    int y = cur.Y;
    int d = df[x][y];
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || n<=xx || yy<0 || m<=yy) continue;
      if(arr[xx][yy]=='#' || df[xx][yy]!=-1) continue;
      df[xx][yy] = d + 1;
      fq.push(mp(xx,yy));
    }
  }
  while(!jq.empty()) {
    pii cur = jq.front();
    jq.pop();
    int x = cur.X;
    int y = cur.Y;
    int d = dj[x][y];
    if(x==0 || x==n-1 || y==0 || y==m-1) {
      cout << d;
      return;
    }
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || n<=xx || yy<0 || m<=yy) continue;
      if(arr[xx][yy]=='#' || dj[xx][yy]!=-1) continue;
      if(df[xx][yy] != -1 && df[xx][yy] <= d+1) continue;
      dj[xx][yy] = d + 1;
      jq.push(mp(xx,yy));
    }
  }
  cout << "IMPOSSIBLE";
  return;
}