/*
Time : 2022.01.20 (30 min)
Problem : BOJ1074 (https://www.acmicpc.net/problem/1074)
Algorithm Type : Recursion
Outline :
2^N x 2^N 크기의 2차원 배열을 Z모양으로 탐색한다.
좌표가 주어졌을 때, 해당 위치를 몇번째로 탐색하는지 출력한다.
Method :
먼저 하노이탑을 옮기는 경우를 셀수도 있지만 2^n - 1개이므로 출력을 먼저 한다.
이후 하노이탑을 다음과 같이 생각하여 재귀함수로 구현한다.
N개의 원판 중 위의 N-1개의 원판을 (출발지/도착지) 가 아닌 장대로 옮긴다.
맨 밑의 원판 하나를 도착지로 옮긴다.
이전에 옮긴 N-1개의 원판을 도착지로 옮긴다.
n=1일때를 base condition으로 두고 재귀함수로 구현하였다.
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

// 2^n x 2^n 크기에서 (r,c) 위치 방문 순서를 리턴
int travel(int n, int r, int c) {
  if(n == 0) return 0; // base condition
  int half = (1<<n) / 2;
  if(r<half && c<half) {
    // 왼쪽-위(1)
    return travel(n-1, r, c);
  } else if(r<half && half<=c) {
    // 오른쪽-위(2)
    return half*half + travel(n-1, r, c-half);
  } else if(half<=r && c<half) {
    // 왼쪽-아래(3)
    return 2*half*half + travel(n-1, r-half, c);
  } else {
    // 오른쪽-아래(4)
    return 3*half*half + travel(n-1, r-half, c-half);
  }
}

void solve() {
  int n, r, c;
  cin >> n >> r >> c; // (r,c)가 몇번째 탐색인지 출력
  cout << travel(n,r,c);
  return;
}