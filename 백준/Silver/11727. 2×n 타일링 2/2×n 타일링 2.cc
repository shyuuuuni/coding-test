/*
Time : 2022.02.10 (10 mins)
Problem : BOJ11727 (https://www.acmicpc.net/problem/11727)
Algorithm Type : Dynamic Programming
Outline :
2xn 직사각형을 1x2, 2x1, 2x2 사각형으로 채우는 경우의 수를 출력한다.
Method :
n번째 경우의 수는 다음과 같은 경우의 수의 합으로 나타낼 수 있다.
1. n-1번째 경우의 수에 2x1 짜리 세로 블록을 하나 붙인 경우
2. n-2번째 경우의 수에 (1x2 2개/2x2 1개) 블록을 붙인 경우
따라서 위 경우의 수를 점화식으로 나타내면
dp[i] = dp[i-1] + 2*dp[i-2] 로 표현할 수 있고, 구현을 그대로 하면 된다.
Example :
8
-------
171
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
  int dp[1000+5] = {};
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 3;
  for(int i=3; i<=1000; i++) {
    dp[i] = dp[i-1]%10007 + 2*dp[i-2]%10007;
    dp[i] %= 10007;
  }
  cin >> n;
  cout << dp[n];
  return 0;
}