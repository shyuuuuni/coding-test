/*
Time : 2022.01.21 (30 min)
Problem : BOJ15649 (https://www.acmicpc.net/problem/15649)
Algorithm Type : Backtracking
Outline :
N과 M이 주어졌을 때 1~N의 수 중에서 중복 없이 M개를 고른 수열을 모두 출력한다.
Method :

*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
using ll = long long;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void solve();

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n,ans=0;
// int chess[15+1][15+1];
int issued1[15+1]; // issued1[i] : i번째 열이 사용되었는지
int issued2[30+1]; // issued2[i] : i번째 대각선(왼쪽위->오른쪽아래) 사용되었는지
int issued3[30+1]; // issued3[i] : i번째 대각선(오른쪽위->왼쪽아래) 사용되었는지

// (x-세로,y-가로) 좌표가 놓을 수 있는 위치인지 체크
// 1. issued1[y] == 0 : 해당 열에 다른 퀸이 존재하지 않음.
// 2. issued2[x-y+n-1] == 0 : 해당 대각선에 다른 퀸이 존재하지 않음.
// 3. issued3[x+y] == 0 : 해당 대각선에 다른 퀸이 존재하지 않음.

void func(int x) { // cur번째 행을 보는 경우
  if(x==n) {
    ans++;
    return; // 0~n-1 : 총 n줄을 봄, cur==n이면 종료
  }
  for(int y=0; y<n; y++) {
    if(!issued1[y] && !issued2[x-y+n-1] && !issued3[x+y]) {
      issued1[y] = 1;
      issued2[x-y+n-1] = 1;
      issued3[x+y]= 1;
      func(x+1);
      issued1[y] = 0;
      issued2[x-y+n-1] = 0;
      issued3[x+y]= 0;
    }
  }
  return;
}

void solve() {
  cin >> n;
  func(0);
  cout << ans;
  return;
}