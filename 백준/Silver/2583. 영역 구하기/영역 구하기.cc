/*
Time : 2022.01.12 (15 min)
Problem : BOJ2583 (https://www.acmicpc.net/problem/2583)
Algorithm Type : BFS
Outline :
MxN 크기의 모눈종이가 있다.
모눈종이 위에 K개의 직사각형을 그릴 때, 직사각형을 제외한 부분이 몇 개의 분리된 영역으로 나뉜다.
분리된 영역의 개수와 각 영역의 넓이를 출력한다.
Method :
먼저 BFS를 통해 불을 전파시킨다.
vis2배열에 불이 몇초에 도달하는지 저장한다.
이후 상근이가 가는 위치도 BFS를 통해 계산한다.
이때 기본적인 BFS 조건 이외에, 상근이가 이동하려는 칸에 불이 이미 옮겨붙었다면
이동할 수 없으므로 해당 조건을 추가한다.
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
  int m, n, k, cnt=0;
  int arr[100+1][100+1]={0}, vis[100+1][100+1]={0};
  vector<int> ans;
  queue<pii> q;
  cin >> m >> n >> k;
  while(k--) {
    int i1, j1, i2, j2;
    cin >> j1 >> i1 >> j2 >> i2;
    for(int i=i1; i<i2; i++) {
      for(int j=j1; j<j2; j++) {
        arr[i][j] = 1;
      }
    }
  }
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      int tmp = 0;
      if(arr[i][j]==0 && vis[i][j]==0) {
        cnt++;
        q.push(mp(i,j));
        vis[i][j]=1;
      } else {
        continue;
      }
      while(!q.empty()) {
        tmp++;
        int x = q.front().X;
        int y = q.front().Y;
        q.pop();
        for(int k=0; k<4; k++) {
          int xx = x + dx[k];
          int yy = y + dy[k];
          if(xx<0 || yy<0 || m<=xx || n<=yy) continue;
          if(vis[xx][yy]!=0 || arr[xx][yy]!=0) continue;
          q.push(mp(xx,yy));
          vis[xx][yy]=1;
        }
      }
      ans.push_back(tmp);
    }
  }
  sort(ans.begin(), ans.end());
  cout << cnt << "\n";
  for(auto i : ans) cout << i << " ";
  return;
}