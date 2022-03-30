/*
Time : 2022.02.09 (10 mins)
Problem : BOJ9095 (https://www.acmicpc.net/problem/9095)
Algorithm Type : Dynamic Programming
Outline :
정수 n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성한다.
연산의 최소 횟수를 출력한다.
Method :

Example :
3
4
7
10
-------
7
44
274
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
  int tc;
  int d[10+5] = {}; // 정수 i를 만드는 경우의 수
  d[1] = 1; // 1
  d[2] = 2; // 11, 2
  d[3] = 4; // 111, 12, 21, 3
  for(int i=4; i<12; i++) {
    // d[i-3] + '3'
    // d[i-2] + '2'
    // d[i-1] + '1'
    d[i] = d[i-3] + d[i-2] + d[i-1];
  }
  cin >> tc;
  while(tc--) {
    int x;
    cin >> x;
    cout << d[x] << "\n";
  }
  return 0;
}