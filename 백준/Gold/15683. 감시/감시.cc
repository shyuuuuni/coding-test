/*
Time : 2022.01.06 (1 min)
Problem : BOJ15683 (https://www.acmicpc.net/problem/15683)
Algorithm Type : Simulation
Outline :
NxM 크기의 직사각형 사무실에 총 K개의 CCTV가 설치되어 있다.
CCTV는 감시할 수 있는 방향이 서로 다른 5개의 종류가 있다.
1번(1방향), 2번(2방향,180도 차이), 3번(2방향,90도 차이), 4번(3방향), 5번(4방향)
CCTV는 90도 방향으로 회전시킬 수 있다.
CCTV가 감시할 수 있는 위치는 해당 방향으로부터 나가서 벽에 닿기 전까지 모든 빈 칸을 감시할 수 있다.
또한 CCTV는 CCTV를 통과하여 (벽과 다르게) 감시할 수 있다.
CCTV 방향에 따라서 사각지대의 크기가 달라진다. 최소 사각 지대의 크기를 출력한다.
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

int n,m; // 세로, 가로
int board1[10][10], board2[10][10]; // 원본, 복사본
vector<pii> cctv; // cctv (x,y) 좌표

bool oob(int x, int y) {
  // out of bound check
  return (x<0 || y<0 || n<=x || m<=y);
}

void check(pii xy, int dir) {
  // dir : 하(0) 좌(1) 상(2) 우(3) 순서
  // 좌표이동 : dx, dy 배열에 넣으면 됨
  int x = xy.X;
  int y = xy.Y;
  dir = dir%4;
  board2[x][y] = 7; // cctv가 있는곳은 감시됨
  while(1) {
    int xx = x + dx[dir];
    int yy = y + dy[dir];
    if(oob(xx,yy) || board1[xx][yy]==6) break;
    board2[xx][yy] = 7; // 감시 체크(7)
    x = xx;
    y = yy;
  }
  return;
}
void solve() {
  int mn = 99999999;
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> board1[i][j];
      if(0< board1[i][j] && board1[i][j]<6) cctv.push_back(mp(i,j));
    }
  }
  for(int tmp=0; tmp < (1<<2*cctv.size()); tmp++) {
    // tmp : 0~4^k, 4진법으로 각 자릿수별로 방향 정함.
    int dir = tmp;
    int cnt=0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        board2[i][j] = board1[i][j];
      }
    }
    for(int i=0; i<cctv.size(); i++) {
      int d = dir%4;
      dir = dir/4;
      switch (board1[cctv[i].X][cctv[i].Y])
      {
      case 1:
        check(cctv[i],d);
        break;
      case 2:
        check(cctv[i],d);
        check(cctv[i],d+2);
        break;
      case 3:
        check(cctv[i],d);
        check(cctv[i],d+1);
        break;
      case 4:
        check(cctv[i],d);
        check(cctv[i],d+1);
        check(cctv[i],d+2);
        break;
      case 5:
        check(cctv[i],d);
        check(cctv[i],d+1);
        check(cctv[i],d+2);
        check(cctv[i],d+3);
      default:
        break;
      }
    }
    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
        cnt += (board2[i][j]==0);
    mn = min(mn, cnt);
  }
  cout << mn;
  return;
}