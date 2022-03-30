/*
Time : 2022.02.09 (10 mins)
Problem : BOJ1149 (https://www.acmicpc.net/problem/1149)
Algorithm Type : Dynamic Programming
Outline :
N개의 집이 일렬로 세워져 있다.
각각의 집은 R,G,B 중 하나의 색으로 칠해야한다.
색별로 칠하는 비용이 정해져 있고, 다음과 같은 규칙을 만족한다.
> N번째 집은 N-1번째 집과 색이 같지 않아야 한다.
비용의 최솟값을 출력한다.
Method :

Example :
3
26 40 83
49 60 57
13 89 99
-------
96
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

bool compare(const string &a, const string &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  return true;
}

// 셋 정렬용 구조체
struct setOrder {
  bool operator() (const string& left, const string& right) const {
    // 비교함수
    return true;
  }
};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  const int R=0, G=1, B=2;
  int d[1000+5][3] = {};
  cin >> n;
  cin >> d[1][R];
  cin >> d[1][G];
  cin >> d[1][B];

  for(int i=2; i<=n; i++) {
    int r,g,b;
    cin >> r >> g >> b;
    d[i][R] = min(d[i-1][G], d[i-1][B]) + r;
    d[i][G] = min(d[i-1][R], d[i-1][B]) + g;
    d[i][B] = min(d[i-1][G], d[i-1][R]) + b;
  }
  cout << min(min(d[n][R],d[n][G]),d[n][B]);
  return 0;
}