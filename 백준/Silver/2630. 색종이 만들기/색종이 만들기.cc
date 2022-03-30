/*
Time : 2022.01.20 (20 min)
Problem : BOJ2630 (https://www.acmicpc.net/problem/2630)
Algorithm Type : Recursion
Outline :
NxN크기의 종이에 하얀색(0), 파란색(1)로 종이가 칠해져있다.
전체 종이가 같은 색으로 칠해지지 않았다면 같은 크기로 4등분한다.
조건에 맞을때까지 반복해서 나누었을 때, 하얀색 색종이와 파란색 색종이의 개수를 출력한다.
Method :
travel(n, x, y)를 (x,y) 점부터 가로,세로 nxn 크기를 확인하는 재귀함수로 정의한다.
해당 점부터 nxn크기의 각각의 종이를 확인하면서 (x,y)점과 다른 숫자가 하나라도 발견된다면 9등분으로 나눈다.
만약 발견되지 않았다면 해당 숫자의 카운트를 1 증가시킨다.
발견되었다면 재귀적으로 9등분한 좌표를 넣고, n의 값을 1/3로 줄여서 반복한다.
만약 n이 1이 되었다면 해당 종이는 1번 조건을 만족하므로 해당 숫자 카운트를 1 증가시킨다.
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

vector<int> ans(2,0);
vector<vector<int> > v(128+1, vector<int>(128+1));
// (x,y)에서부터 가로 n, 세로 n을 탐색, n은 2~128
void travel(int n, int x, int y) {
  int val = v[x][y], flag=1;
  int half = n/2;
  if(n == 1) {
    ans[val]++;
    return;
  }
  for(int i=0; flag&&i<n; i++) {
    for(int j=0; flag&&j<n; j++) {
      if(val != v[x+i][y+j]) {
        flag=0;
      }
    }
  }
  if(flag) {
    ans[val]++;
    return;
  }
  for(int i=0; i<2; i++) {
    for(int j=0; j<2; j++) {
      travel(half, x+i*half, y+j*half);
    }
  }
  
  return;
}

void solve() {
  int n;
  cin >> n;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> v[i][j];
    }
  }
  travel(n,0,0);
  for(auto i : ans) cout << i << "\n";
  return;
}