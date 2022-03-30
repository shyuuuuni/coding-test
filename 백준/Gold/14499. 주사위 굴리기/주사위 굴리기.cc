/*
Time : 2022.01.27 (1h 30 mins)
Problem : BOJ14499 (https://www.acmicpc.net/problem/14499)
Algorithm Type : Simulation
Outline :

Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void solve();
bool oob(int, int);
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, m, x, y, k, c;
int board[25][25];
int dice[7];
/*
   [2]
[4][1][3] <- [1]이 맨 위, [3]이 동쪽
   [5]
   [6] <- 바닥
{empty, 1(맨위), 2, 3, 4, 5, 6(맨아래)} 
*/

bool oob(int x, int y) { // out of bound check
  return (x<0 || y<0 || n<=x || m<=y);
}

void roll(int command) {
  if(command == 1) {// 동쪽으로 roll 
    int afterroll[7] = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  } else if(command == 2) {// 서쪽으로 roll
    int afterroll[7] = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  } else if(command == 3) {// 북쪽으로 roll
    int afterroll[7] = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  } else {// 남쪽으로 roll
    int afterroll[7] = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
    for(int i=0; i<7; i++) dice[i] = afterroll[i];
  }
  return;
}

void solve() {
  cin >> n >> m >> x >> y >> k;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      cin >> board[i][j];
  
  while(k--) {
    cin >> c;
    int nx = x + dx[c-1];
    int ny = y + dy[c-1];
    if(!oob(nx, ny)) {
      x = nx; y = ny;
      roll(c);
      if(board[x][y] == 0)
        board[x][y] = dice[6];
      else {
        dice[6] = board[x][y];
        board[x][y]=0;
      }
      cout << dice[1] << "\n";
    }
  }
  return;
}