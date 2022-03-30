/*
Time : 2022.02.10 (10 mins)
Problem : BOJ2193 (https://www.acmicpc.net/problem/2193)
Algorithm Type : Dynamic Programming
Outline :
0과 1로만 이루어진 수를 이진수라 한다. 그 중 다음 성질을 가지면 이친수라고 한다.
이친수는 0으로 시작하지 않는다.
이친수에서는 1이 두 번 연속으로 나타나지 않는다. 즉, 11을 부분 문자열로 갖지 않는다.
N(1 ≤ N ≤ 90)이 주어졌을 때, N자리 이친수의 개수를 구하는 프로그램을 작성하시오.
Method :

Example :
3
-------
2
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

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
  cin >> n;
  ll dp[2][90+5] = {};
  dp[0][1] = 0;
  dp[1][1] = 1;
  for(int i=2; i<=90; i++) {
    dp[0][i] = dp[0][i-1] + dp[1][i-1];
    dp[1][i] = dp[0][i-1];
  }
  cout << dp[0][n] + dp[1][n];
  return 0;
}