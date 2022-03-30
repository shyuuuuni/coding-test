/*
Time : 2022.01.12 (40 min)
Problem : BOJ5427 (https://www.acmicpc.net/problem/5427)
Algorithm Type : BFS
Outline :
상근이(@)가 빈공간(.)과 벽(#)으로 이루어진 건물에 갇혀있다.
건물에 불(*)이 났고, 불은 매 초마다 동서남북 방향의 빈 공간으로 퍼져나간다.
상근이도 매 초마다 동서남북 인접한 칸으로 이동할 수 있다.
상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.
상근이가 얼마나 빨리 빌딩을 탈출할 수 있는지 출력한다.
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
void solve() {
  int tc;
  cin >> tc;
  while(tc--) {
    int w, h;
    string arr[1000+1];
    int vis1[1000+1][1000+1], vis2[1000+1][1000+1];
    queue<pii> q1, q2;
    cin >> w >> h; // 너비(가로), 높이(세로)
    fill(&vis1[0][0], &vis1[0][0] + 1001*1001, -1);
    fill(&vis2[0][0], &vis2[0][0] + 1001*1001, -1);
    for(int i=0; i<h; i++) {
      cin >> arr[i];
      for(int j=0; j<w; j++) {
        if(arr[i][j] == '@') {
          q1.push(mp(i,j));
          vis1[i][j] = 0;
        } else if(arr[i][j] == '*') {
          q2.push(mp(i,j));
          vis2[i][j] = 0;
        }
      }
    }
    // 불을 먼저 진행시킴
    while(!q2.empty()) {
      int x = q2.front().X;
      int y = q2.front().Y;
      int d = vis2[x][y];
      q2.pop();
      for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx<0 || yy<0 || h<=xx || w<=yy) continue;
        if(vis2[xx][yy]!=-1 || arr[xx][yy]=='#') continue;
        q2.push(mp(xx,yy));
        vis2[xx][yy] = d+1;
      }
    }
    // 상근이를 이동시킴
    int ans = -1;
    while(!q1.empty()) {
      int x = q1.front().X;
      int y = q1.front().Y;
      int d = vis1[x][y];
      if(x==0 || x==h-1 || y==0 || y==w-1) {
        ans = d+1;
        break;
      }
      q1.pop();
      for(int i=0; i<4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx<0 || yy<0 || h<=xx || w<=yy) continue;
        if(vis1[xx][yy]!=-1 || arr[xx][yy]=='#' || arr[xx][yy]=='*' || (vis2[xx][yy]!=-1 && vis2[xx][yy]<=d+1)) continue;
        q1.push(mp(xx,yy));
        vis1[xx][yy] = d+1;
      }
    }
    if(ans==-1) cout << "IMPOSSIBLE\n";
    else cout << ans << "\n";
  }
  return;
}