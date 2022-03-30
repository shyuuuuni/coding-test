/*
Time : 2022.02.05 (30 mins)
Problem : BOJ14503 (https://www.acmicpc.net/problem/14503)
Algorithm Type : Simulation
Outline :
세로N x 가로M 크기의 직사각형 위에 로봇 청소기가 놓여있다.
직사각형은 빈 칸(0)과 벽(1) 으로 구성되어 있다.
로봇 청소기는 (r,c)에 위치하며, 처음에 d방향을 바라본다. (d = 0북, 1동, 2남, 3서)
로봇 청소기는 다음과 같이 작동한다.
1.현재 위치를 청소한다.
2.현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 차례대로 인접한 칸을 탐색한다.
    왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
    왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
    네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
    네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
로봇 청소기가 청소하는 빈칸의 수를 출력한다.
Method :
Example :
3 3
1 1 0
1 1 1
1 0 1
1 1 1
-------
1
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
// int dz[6] = {0,0,0,0,-1,1};
// int dx[6] = {-1,1,0,0,0,0};
// int dy[6] = {0,0,-1,1,0,0};
void solve();
bool oob(int, int);
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n,m;
int r,c,d;
int cnt, dir;
int board1[50+1][50+1];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool oob(int x, int y, int nn, int mm) { // out of bound check
  return (x<0 || y<0 || nn<=x || mm<=y);
}

void run() {
  // 현재 위치를 청소한다
  // cout << "(" << r << " " << c << ")\n";
  if(board1[r][c] == 0) {
    board1[r][c] = -1;
    cnt++;
  }

  // 현재 방향을 기준으로 인접한 칸을 탐색한다.
  for(int i=0; i<4; i++) {
    int le = (4 + d - 1) % 4;
    int nx = r + dx[le];
    int ny = c + dy[le];
    d = le;

    // cout << "  (" << r << " " << c << " " << d << ") " << nx << " " << ny  << "\n";
    // cout << "  jump :" << dx[le] << " " << dy[le] << "\n";
    if(!oob(nx, ny, n, m) && board1[nx][ny]==0) {
      r = nx;
      c = ny;
      // cout << "    (" << r << " " << c << "\n";
      run();
      return;
    }
  }

  // 이동할 곳이 없다면 후진한다.
  int bk = (4 + d + 2) % 4;
  int nx = r + dx[bk];
  int ny = c + dy[bk];
  if(!oob(nx,ny,n,m) && board1[nx][ny]!=1) {
    r = nx;
    c = ny;
    run();
    return;
  }
  return;
}

void solve() {
  cin >> n >> m;
  cin >> r >> c >> d;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> board1[i][j];
  dir = d;
  run();
  cout << cnt;
  return;
}