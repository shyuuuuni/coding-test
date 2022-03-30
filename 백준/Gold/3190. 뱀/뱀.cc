/*
Time : 2022.02.05 (30 mins)
Problem : BOJ3190 (https://www.acmicpc.net/problem/3190)
Algorithm Type : Simulation
Outline :

Method :

Example :
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D
-------
9
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

int n;
int k;
int l, idx;
int t=0, d=1;
int x=0, y=0; // head
vector<pii> v;
int board1[100+1][100+1];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool oob(int x, int y, int nn, int mm) { // out of bound check
  return (x<0 || y<0 || nn<=x || mm<=y);
}

void pm() {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cout << board1[i][j] << " ";
    }
    cout << "\n";
  }
}

void solve() {
  cin >> n;
  cin >> k;
  while(k--) {
    int r, c;
    cin >> r >> c;
    board1[r-1][c-1] = 1; // apple
  }
  cin >> l;
  while(l--) {
    int ti;
    char dir;
    cin >> ti >> dir;
    v.push_back(mp(ti, (dir=='L'?-1:1)));
  }

  deque<pii> baaam;
  baaam.push_back(mp(0,0));
  board1[0][0] = -1;
  
  while(1) {
    // pm();
    // cout << t << "---------------\n";
    t++;
    int x = baaam.front().X;
    int y = baaam.front().Y;
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(oob(nx,ny,n,n) || board1[nx][ny]==-1) {
      break;
    }
    baaam.push_front(mp(nx,ny));
    if(board1[nx][ny] == 1) {
      // apple here
      board1[nx][ny] = -1;
    } else {
      // just move
      int xx = baaam.back().X;
      int yy = baaam.back().Y;
      board1[nx][ny] = -1;
      board1[xx][yy] = 0;
      baaam.pop_back();
    }
    if(idx < v.size() && t == v[idx].first) {
      // change dir
      d = (4 + d + v[idx++].second) % 4;
    }
  }

  cout << t;

  return;
}