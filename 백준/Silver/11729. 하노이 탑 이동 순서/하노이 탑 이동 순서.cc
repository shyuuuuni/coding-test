/*
Time : 2022.01.20 (30 min)
Problem : BOJ11729 (https://www.acmicpc.net/problem/11729)
Algorithm Type : Recursion
Outline :
3개의 장대에 N개의 원판이 쌓여있다.
하노이탑의 규칙에 따라서 첫번째 장대에서 세번째 장대로 원판을 옮기려고 한다.
옮기는 과정을 출력한다.
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

// n개의 원판을 stt 장대에서 dst 장대로 옮긴다.
void hanoi(int stt, int dst, int n) {
  if(n == 1) {  // base condition
    cout << stt << " " << dst << "\n";
    return;
  }

  // 먼저 바닥을 제외한 n-1개의 장대를 stt, dst가 아닌 장대에 옮긴다.
  // ex) stt=1, dst=3 -> 6-1-3=2. 2번 장대에 옮김
  hanoi(stt, 6-stt-dst, n-1);
  // 다음으로 바닥에 있는 장대를 dst로 옮긴다.
  hanoi(stt, dst, 1);
  // 마지막으로 n-1개의 장대를 dst로 옮긴다.
  hanoi(6-stt-dst, dst, n-1);
  return;
}

void solve() {
  int n;
  cin >> n;
  cout << (1<<n)-1 << "\n";
  hanoi(1, 3, n);
  return;
}