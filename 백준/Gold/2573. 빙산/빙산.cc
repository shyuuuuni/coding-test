/*
Time : 2022.01.14 (45 min)
Problem : BOJ2573 (https://www.acmicpc.net/problem/2573)
Algorithm Type : BFS
Outline :
NxM 정수 배열에 빙산이 입력된다.
빙산의 높이는 0부터 10 사이의 정수로 주어지며,
높이가 0이라는 의미는 다 녹아서 바닷물이 되었다는 것을 의미한다.
매 년마다 빙산은 주위에 있는 0의 개수만큼의 높이를 잃게된다.
빙산이 두 덩이 이상으로 분리되는 최초의 시간을 출력한다.
Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
void solve();
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void solve1() {
  int n, m;
  int height[300+1][300+1];
  int vis[300+1][300+1] = {0};
  int n_mount=0, y_cnt=0;
  int mx=0;
  pii mx_idx;
  fill(&height[0][0], &height[0][0]+301*301, -1);
  queue<pair<pii,int> > q; // ((i,j), year)
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> height[i][j];
      if(height[i][j] == 0) {
        q.push(mp(mp(i,j), 0));
      } else {
        n_mount++;
        if(mx < height[i][j]) {
          mx_idx = mp(i,j);
          mx = height[i][j];
        }
      }
    }
  }
  
  queue<pii> qq;
  while(!q.empty()) {
    int x = q.front().first.X;
    int y = q.front().first.Y;
    int year = q.front().second;
    // cout << x << " " << y << " " << year << "\n";
    q.pop();

    // 새로운 년이 나오면 빙산이 갈라졌는지 체크
    if(year == y_cnt) {
      // cout << "check!\n";
      // cout << "mx : " << mx_idx.first << " " << mx_idx.second << "\n";
      // for(int i=0; i<n; i++) {
      //   for(int j=0; j<m; j++) {
      //     cout << height[i][j] << " ";
      //   } cout << "\n";
      // }
      int cnt = 0;
      if(height[mx_idx.first][mx_idx.second]) {
        qq.push(mx_idx);
        vis[mx_idx.first][mx_idx.second] = y_cnt+1;
      }
      while(!qq.empty()) {
        int xxx = qq.front().X;
        int yyy = qq.front().Y;
        // cout << "check : " << xxx << " " << yyy << "\n";
        cnt++;
        qq.pop();
        if(height[mx_idx.first][mx_idx.second] < height[xxx][yyy]) {
          mx_idx = mp(xxx,yyy);
        }
        for(int i=0; i<4; i++) {
          int xxxx = xxx + dx[i];
          int yyyy = yyy + dy[i];
          if(xxxx<0 || yyyy<0 || n<=xxxx || m<=yyyy) continue;
          if(height[xxxx][yyyy] == 0) {
            // cout << xxxx << " " << yyyy << "!!\n";
            continue;
          }
          if(vis[xxxx][yyyy] != y_cnt) {
            // cout << "already visit" << xxxx << " " << yyyy << "\n";
            continue;
            }
          vis[xxxx][yyyy] = y_cnt+1;
          qq.push(mp(xxxx,yyyy));
        }
      }
      // cout << "check result : year=" << year << " " << cnt << " " << n_mount << "\n";
      if(cnt == 0) break;
      if(cnt != n_mount) {
        // cout << "갈라짐!!\n";
        cout << year << "\n";
        return;
      } else {
        // cout << "아직 하나임!\n";
      }
      y_cnt++;
    }
    int flag = 0;
    for(int i=0; i<4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if(xx<0 || yy<0 || n<=xx || m<=yy) continue;
      if(height[xx][yy] == 0) continue;
      if(0 < height[xx][yy]) {
        height[xx][yy]--;
        flag = 1;
        if(height[xx][yy] == 0) {
          q.push(mp(mp(xx,yy),year+1));
          n_mount--;
        }
      }
    }
    if(flag) q.push(mp(mp(x,y),year+1));
  }
  cout << 0 << "\n";
  return;
}