/*
Time : 2022.01.12 (15 min)
Problem : BOJ6593 (https://www.acmicpc.net/problem/6593)
Algorithm Type : BFS
Outline :
삼범이가 정육면체 모양의 빌딩에 갇혀있다.
빌딩은 L층의 RxC 모양으로 이루어져 있다.
RxC의 각 칸은 벽(#)과 이동할 수 있는 칸(.), 시작지점(S), 출구(E)로 구성되어있따.
탈출할 수 있는 시간을 출력한다.
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

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,-1,0,1,0,0};
int dz[6] = {0,0,0,0,1,-1};
void solve() {
  while(1) {
    int l, r, c; // 높이, 세로, 가로
    int dist[30+1][30+1][30+1];
    int ans=-1;
    string arr[30+1][30+1];
    pair<pii,int> dest;
    queue<pair<pii, int> > q;
    cin >> l >> r >> c;
    if(l==0 && r==0 && c==0) break;
    fill(&dist[0][0][0], &dist[0][0][0] + 31*31*31, -1);
    for(int i=0; i<l; i++) {
      for(int j=0; j<r; j++) {
        cin >> arr[i][j];
        for(int k=0; k<c; k++) {
          if(arr[i][j][k] == 'S') {
            dist[i][j][k] = 0;
            q.push(mp(mp(j,k),i));
          } else if(arr[i][j][k] == 'E') {
            dest = mp(mp(j,k),i);
          }
        }
      }
    }
    while(!q.empty()) {
      int x = q.front().first.X;
      int y = q.front().first.Y;
      int z = q.front().second;
      int d = dist[z][x][y];
      if(z==dest.second && x==dest.first.first && y==dest.first.second) {
        ans = d;
        break;
      }
      q.pop();
      for(int i=0; i<6; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        int zz = z + dz[i];
        if(xx<0 || yy<0 || zz<0 || r<=xx || c<=yy || l<=zz) continue;
        if(dist[zz][xx][yy]!=-1 || arr[zz][xx][yy]=='#') continue;
        q.push(mp(mp(xx,yy),zz));
        dist[zz][xx][yy]=d+1;
      }
    }
    if(ans==-1) {
      cout << "Trapped!\n";
    } else {
      cout << "Escaped in " << ans << " minute(s).\n";
    }
  }
  return;
}