/*
Time : 2022.02.09 (10 mins)
Problem : BOJ2579 (https://www.acmicpc.net/problem/2579)
Algorithm Type : Dynamic Programming
Outline :
점수가 각각 적혀져 있는 계단이 주어진다.
계단은 한번에 1개 혹은 2개의 계단을 오를 수 있다.
그러나 연속된 3개의 계단은 밟을 수 없으며, 마지막 계단은 밟아야한다.
마지막 계단까지 밟았을 때, 점수의 합의 최댓값을 출력한다.
Method :

Example :
6
10
20
15
25
10
20
-------
75
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
  int n; // 계단수
  int score[300+5] = {}; // 계단의 점수
  int d[300+5][3] = {}; // d[i][j] : i번째 계단까지 갈때 최대 합, j번 연속 밟는중 
  cin >> n;
  for(int i=1; i<=n; i++) {
    cin >> score[i];
  }
  d[1][1] = score[1];
  d[2][1] = score[2];
  d[2][2] = score[1] + score[2];
  for(int i=3; i<=n; i++) {
    d[i][1] = max(d[i-2][1], d[i-2][2]) + score[i];
    d[i][2] = d[i-1][1] + score[i];
  }
  cout << max(d[n][1], d[n][2]);
  return 0;
}