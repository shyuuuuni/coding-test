/*
Time : 2022.01.12 (25 min)
Problem : BOJ10026 (https://www.acmicpc.net/problem/10026)
Algorithm Type : BFS
Outline :
NxN 그리드에 R,G,B로 이루어진 그림이 있다.
적록색약은 R과 G를 구분하지 못한다.
따라서 같은 그림이여도 적록색약이 아닌사람과 적록색약인 사람이 보는 구역의 수가 다르다.
각각이 보는 구역의 수를 출력한다.
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void solve() {
  int n, ans=0;
  string arr1[100+1], arr2[100+1];
  int vis1[100+1][100+1]={0}, vis2[100+1][100+1]={0};
  queue<pair<pii,char> > q;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> arr1[i];
    arr2[i] = arr1[i];
    for(int j=0; j<n; j++) {
      if(arr1[i][j] == 'B')
        continue;
      else
        arr2[i][j] = 'R';
    }
  }
  // 적록색약이 아닌 사람 기준
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(vis1[i][j] == 0) {
        // cout << i << " " << j << "\n";
        ans++;
        q.push(make_pair(mp(i,j), arr1[i][j]));
        vis1[i][j] = 1;
      } else {
        continue;
      }
      while(!q.empty()) {
        pii cur = q.front().first;
        char c = q.front().second;
        int x = cur.X;
        int y= cur.Y;
        q.pop();
        for(int k=0; k<4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if(xx<0 || n<=xx || yy<0 || n<=yy) continue;
          if(vis1[xx][yy] || arr1[xx][yy]!=c) continue;
          vis1[xx][yy]=1;
          q.push(make_pair(mp(xx,yy), c));
        }
      }
    }
  }
  cout << ans << " ";
  ans = 0;
  // 적록색약인 사람 기준
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(vis2[i][j] == 0) {
        // cout << i << " " << j << "\n";
        ans++;
        q.push(make_pair(mp(i,j), arr2[i][j]));
        vis2[i][j] = 1;
      } else {
        continue;
      }
      while(!q.empty()) {
        pii cur = q.front().first;
        char c = q.front().second;
        int x = cur.X;
        int y= cur.Y;
        q.pop();
        for(int k=0; k<4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if(xx<0 || n<=xx || yy<0 || n<=yy) continue;
          if(vis2[xx][yy] || arr2[xx][yy]!=c) continue;
          vis2[xx][yy]=1;
          q.push(make_pair(mp(xx,yy), c));
        }
      }
    }
  }
  cout << ans;
  return;
}