/*
Time : 2022.01.12 (15 min)
Problem : BOJ2468 (https://www.acmicpc.net/problem/2468)
Algorithm Type : BFS
Outline :
크기가 NxN인 지도에 높이정보가 주어진다.
장마철에 비가 내리면 일정한 높이 이하의 모든 지점이 물이 잠긴다.
안전한 영역을 "위,아래,왼쪽,오른쪽에 인접해 있는 물에 잠기지 않은 지점들"로 정의한다.
높이 정보가 주어졌을 때, 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.
Method :
일차원 배열에서의 BFS로 생각한다.
층을 벗어나면 이동하지 않는것으로 처리하므로 배열의 범위는 0~F이다.
Failed :
0층은 존재하지 않으므로 인덱스 처리를 해주어야한다!!
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
  int n, mx=0, mn=10000001, ans=1;
  int arr[100+1][100+1]={0};
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> arr[i][j];
      mx = max(mx, arr[i][j]);
      mn = min(mn, arr[i][j]);
    }
  }
  // i : 장마시 잠기는 높이
  for(int h=mn; h<mx; h++) {
    int cur = 0;
    int vis[100+1][100+1]={0};
    queue<pii> q;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(arr[i][j]-h > 0 && vis[i][j]==0) {
          q.push(mp(i,j));
          vis[i][j]=1;
          cur++;
        } else {
          continue;
        }
        while(!q.empty()) {
          int x = q.front().X;
          int y = q.front().Y;
          q.pop();
          for(int k=0; k<4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(xx<0 || yy<0 || n<=xx || n<=yy) continue;
            if(vis[xx][yy]!=0 || arr[xx][yy]-h<=0) continue;
            q.push(mp(xx,yy));
            vis[xx][yy]=1;
          }
        }
      }
    }
    ans = max(ans, cur);
  }
  cout << ans;
  return;
}