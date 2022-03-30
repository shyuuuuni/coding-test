/*
Time : 2022.02.10 (10 mins)
Problem : BOJ1932 (https://www.acmicpc.net/problem/1932)
Algorithm Type : Dynamic Programming
Outline :
삼각형에 숫자가 쓰여져서 주어진다.
맨 윗줄부터 아래에 있는 수 중 하나를 선택하여 내려올 때, 합이 최대가 되는 경로의 합을 출력한다.
(아래 : 현재 위치의 왼쪽대각선,오른쪽대각선 위치)
Method :
기존의 연산수만 저장하는 dp에 path라는 배열을 추가한다.
path[i]는 i라는 수가 1로 이동할때, 다음 수를 의미한다.
ex) 10 -> 9 -> 3 -> 1에서 path[10] = 9, path[9] = 3, ...
Example :
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
-------
30
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
  int tri[500+5][500+5] = {};
  int dp[500+5][500+5] = {}; // dp[i][j] : i번째 줄의 j번째를 선택했을 때 최대값
  cin >> n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      cin >> tri[i][j];
    }
  }
  dp[0][0] = tri[0][0];
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=i; j++) {
      if(j==1) dp[i][j] = dp[i-1][j] + tri[i][j];
      else if(j==i) dp[i][j] = dp[i-1][j-1] + tri[i][j];
      else dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];
    }
  }
  int ans = 0;
  for(int i=1; i<=n; i++) ans = max(ans, dp[n][i]);
  cout << ans;
  return 0;
}