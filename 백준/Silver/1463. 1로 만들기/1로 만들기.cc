/*
Time : 2022.02.09 (10 mins)
Problem : BOJ1463 (https://www.acmicpc.net/problem/1463)
Algorithm Type : Dynamic Programming
Outline :
정수 N이 주어졌을 때, 다음과 같은 연산을 적절히 사용하여 1로 만드려고 한다.
1. X가 3으로 나눌 수 있으면 3으로 나눈다.
2. X가 2로 나눌 수 있으면 2로 나눈다.
3. 1을 뺀다.
연산의 최소 횟수를 출력한다.
Method :

Example :
10
-------
3
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
  int x;
  int d[1000000+5] = {0};
  cin >> x;
  d[1] = 0;
  d[2] = 1;
  d[3] = 1;
  for(int i=4; i<=x; i++) {
    d[i] = 1000000+10;
    if(i%3 == 0) d[i] = d[i/3] + 1;
    if(i%2 == 0) d[i] = min(d[i], d[i/2] + 1);
    d[i] = min(d[i], d[i-1] + 1);
  }
  cout << d[x];
  return 0;
}