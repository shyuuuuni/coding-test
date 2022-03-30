/*
Time : 2022.01.27 (1 hour)
Problem : BOJ14891 (https://www.acmicpc.net/problem/14891)
Algorithm Type : Simulation
Outline :
4개의 톱니바퀴에 각각 8개의 극이 달린 톱니가 있다.
톱니바퀴를 회전시켰을 때, 톱니바퀴간 인접한 톱니의 극이 같다면 인접한 톱니바퀴는 회전하지 않는다.
만약 인접한 톱니의 극이 다르다면 톱니바퀴가 회전한 방향의 반대방향으로 회전하게 된다.
초기 톱니바퀴의 상태와 회전시킨 방법이 주어졌을 때 최종 톱니바퀴의 상태를 구한다.
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

string clk[4];
pii lr[4];
int check[4];
int k;
int n, dir;

bool oob(int x, int y) {
  // out of bound check
  return (x<0 || y<0 || n<=x || n<=y);
}

void printClk() {
  for(int i=0; i<4; i++) {
    int l = lr[i].first;
    int r = lr[i].second;
    int head = (l+2)%8;
    for(int j=head; j<8; j++) {
      if(j == l)
        cout << "(" << clk[i][j] << ")";
      else if(j == r)
        cout << "[" << clk[i][j] << "]";
      else
        cout << clk[i][j];
    }
    for(int j=0; j<head; j++) {
      if(j == l)
        cout << "(" << clk[i][j] << ")";
      else if(j == r)
        cout << "[" << clk[i][j] << "]";
      else
        cout << clk[i][j];
    }
    cout << "\n";
  }
  return;
}

void swing(int n, int dir) {
  int l, r;
  char le, ri;

  l = lr[n].first;
  r = lr[n].second;
  le = clk[n][l];
  ri = clk[n][r];
  
  // 톱니바퀴 n 회전
  if(dir==1) {
    // SN<S>NSS(S)S -> SS[N]<S>NSS(S)
    l = (l-1+8)%8;
    r = (r-1+8)%8;
  } else {
    l = (l+1)%8;
    r = (r+1)%8;
  }
  lr[n] = mp(l,r);

  if(n != 0) {
    if(!check[n-1] && (clk[n-1][lr[n-1].second] != le)) {
      check[n-1] = 1;
      swing(n-1, dir*(-1));
    }
  }
  if(n != 3) {
    if(!check[n+1] && (clk[n+1][lr[n+1].first] != ri)) {
      check[n+1] = 1;
      swing(n+1, dir*(-1));
    }
  }
  return;
}

void solve() {
  int ans = 0;
  for(int i=0; i<4; i++) cin >> clk[i];
  lr[0] = lr[1] = lr[2] = lr[3] = mp(6,2);
  cin >> k;
  // printClk();
  while(k--) {
    cin >> n >> dir;
    n--;
    fill(check, check+4, 0);
    check[n] = 1;
    swing(n,dir);
    // printClk();
  }
  for(int i=0; i<4; i++) {
    int mul = (1<<i);
    if(clk[i][(lr[i].first+2)%8]=='1')
      ans += mul;
  }
  cout << ans;
  return;
}