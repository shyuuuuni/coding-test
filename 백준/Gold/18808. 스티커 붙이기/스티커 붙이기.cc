/*
Time : 2022.01.06 (1 hour)
Problem : BOJ18808 (https://www.acmicpc.net/problem/18808)
Algorithm Type : Simulation
Outline :
모눈종이에 스티커를 붙이려고 한다.
1. 스티커는 상하좌우에 불필요한 모눈종이를 포함하지 않는다.
2. 스티커의 각 칸은 상하좌우로 연결되어 있다.
혜윤이는 이러한 성질의 스티커를 격자에 맞춰서 붙이려고 한다.
1. 스티커를 붙일 수 있는 위치를 왼쪽 위쪽부터 찾는다. (위->왼쪽 순)
2. 선택한 위치에 스티커를 붙인다. 만약 붙일 수 없다면 스티커를 시계방향으로 90도 회전한 후 2번을 시행한다.
3. 위 과정을 반복해서 0도/90도/180도/270도 회전시켰을때 붙이지 못하면 버린다.
모든 스티커를 붙인 후 노트북에서 스티커가 붙은 칸의 개수를 출력한다.
Method :
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n,m,k; // 세로, 가로, 스티커 개수
int sn,sm; // 스티커 세로,가로 길이
int notebook[45][45], sticker[12][12]; // 노트북, 스티커
vector<pii> cctv; // cctv (x,y) 좌표

bool oob(int x, int y) {
  // out of bound check
  return (x<0 || y<0 || n<=x || m<=y);
}

void swing() {
  // 스티커를 90도 시계방향으로 회전
  int tmp[12][12];
  for(int i=0; i<sn; i++)
    for(int j=0; j<sm; j++)
      tmp[j][sn-1-i] = sticker[i][j];
  for(int i=0; i<sm; i++)
    for(int j=0; j<sn; j++)
      sticker[i][j] = (tmp[i][j]==1);
  swap(sn,sm);
  return;
}

bool check(int x, int y) {
  for(int i=0; i<sn; i++) {
    for(int j=0; j<sm; j++) {
      int xx = x + i;
      int yy = y + j;
      if(sticker[i][j]==0) continue;
      else if(oob(xx,yy) || notebook[xx][yy]==1) {
        // cout << "false at : " << x << " " << y << " " << i << " " << j << " " << xx << " " << yy << "\n";
        return false;
      }
    }
  }
  for(int i=0; i<sn; i++) {
    for(int j=0; j<sm; j++) {
      int xx = x + i;
      int yy = y + j;
      if(notebook[xx][yy]==0 && sticker[i][j]==1)
        notebook[xx][yy] = sticker[i][j];
    }
  }
  return true;
}

void solve() {
  int ans=0;
  cin >> n >> m >> k;
  while(k--) {
    bool put = false;
    cin >> sn >> sm;
    for(int i=0; i<sn; i++)
      for(int j=0; j<sm; j++)
        cin >> sticker[i][j];
    for(int k=0; k<4 && !put; k++) {
      if(k) swing(); // 0,90,180,270도 회전
      // cout << k << " " << sn << " " << sm << "\n";
      // for(int ii=0; ii<sn; ii++) {
      //   for(int jj=0; jj<sm; jj++) {
      //     cout << sticker[ii][jj] << " ";
      //   }cout << "\n";
      // }
      for(int i=0; i<n && !put; i++) {
        for(int j=0; j<m && !put; j++) {
          // 붙일 수 있는 위치인지 확인
          put = check(i,j);
        }
      }
    }
    // cout << "result : \n";
    // for(int i=0; i<n; i++) {
    //   for(int j=0; j<m; j++) {
    //     cout << notebook[i][j] << " ";
    //   } cout << "\n";
    // }
    
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      ans += (notebook[i][j]==1);
    }
  }
  cout << ans;
  return;
}