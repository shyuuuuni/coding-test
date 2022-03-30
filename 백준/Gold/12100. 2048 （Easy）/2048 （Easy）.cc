/*
Time : 2022.01.27 (1 hour)
Problem : BOJ12100 (https://www.acmicpc.net/problem/12100)
Algorithm Type : Simulation
Outline :
NxN 크기의 보드에서 2048 게임을 하려고 한다.
2048게임은 보드 위의 전체 블록을 상하좌우 네 방향 중 하나로 몰아서 이동시킬 수 있다.
이때 같은 값을 갖는 블록이 충돌하면 하나로 합쳐지게 되고, 합쳐진 블록은 해당 시행에서 다시 합쳐지지 않는다.
게임판의 초기 상태와 보드의 크기(N)가 주어질 때, 최대 5번 보드를 이동시켜 얻을 수 있는 가장 큰 블록을 출력한다.
Method :
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
void solve();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, mx=0; // 세로 = 가로
int board1[25][25], board2[25][25];

bool oob(int x, int y) {
  // out of bound check
  return (x<0 || y<0 || n<=x || n<=y);
}

void change() {
  // 시계 방향으로 90도 회전시킨다.
  // (0,0) (0,1)     [0,0] [0,1] [0,2] [0,3] [0,4]
  // (1,0) (1,1)     (4,0) (3,0) (2,0) (1,0) (0,0)
  // (2,0) (2,1)  -> (4,1) (3,1) (2,1) (1,1) (0,1)
  // (3,0) (3,1)     [1,0] [1,1] [2,1] [3,1] [4,1]
  // (4,0) (4,1)
  // (x,y) -> (y,5-1-x)
  int tmp[25][25] = {};
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      tmp[j][n-1-i] = board2[i][j];
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      board2[i][j] = tmp[i][j];
  return;
}

void move(int dir) {
  // dir -> 0:상, 1:하, 2:좌, 3:우
  // dir2에서 90도 회전 -> 상 -> 우 -> 하
  int numOfChange[4] = {1,3,0,2};
  for(int i=0; i<numOfChange[dir]; i++) change();
  for(int i=0; i<n; i++) {
    int tmp[25] = {0}; // 밀었을 때 생성되는 줄
    int idx = 0; // tmp 배열에 넣을 인덱스
    for(int j=0; j<n; j++) {
      if(board2[i][j] == 0) continue;
      if(tmp[idx]==0) tmp[idx] = board2[i][j];
      else if(tmp[idx]==board2[i][j]) tmp[idx++] += board2[i][j];
      else if(tmp[idx]!=board2[i][j]) tmp[++idx] = board2[i][j];
    }
    for(int j=0; j<n; j++)
      board2[i][j] = tmp[j];
  }
  for(int i=0; i<(4-numOfChange[dir])%4; i++) change();
  return;
}

void solve() {
  cin >> n;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin >> board1[i][j]; // 원본 입력
  for(int p=0; p<(1<<2*5); p++) {
    // 보드를 5번 이동시킬 수 있음.
    // 각 이동별로 상하좌우(4가지)를 선택할 수 있음.
    // 이를 4진법 숫자를 이용하여 4진법 각 자릿수로 표현
    // 0:상, 1:하, 2:좌, 3:우
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        board2[i][j] = board1[i][j];
    int tmp = p;
    for(int i=0; i<5; i++) {
      // 4진법의 각 자릿수를 꺼내옴
      int dir = tmp % 4;
      tmp = tmp / 4;
      move(dir);
    }
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        mx = max(mx, board2[i][j]);
  }
  cout << mx;
  return;
}