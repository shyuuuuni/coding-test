/*
Time : 2022.02.14 (10 mins)
Problem : BOJ10844 (https://www.acmicpc.net/problem/10844)
Algorithm Type : DP
Outline :
계단수란, 어떤 수의 각 요소에 대해서 각 자릿수별로 인접한 수의 차이가 1인 수를 계단수라고 한다.
N이 주어졌을 때, 길이가 N인 계단수의 개수를 출력한다.
Method :

Example :
2
-------
17
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

// 문자열을 구분자를 기준으로 나눠서 벡터에 저장
int splitStringByToken(vector<string> &v, string &s, const char &del) {
  if(s.empty()) return 0;
  istringstream ss(s);
  string token;

  v.clear();
  while (getline(ss, token, del)) {
    if(!token.empty()) v.push_back(token);
  }

  return v.size();
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  ll dp[100+5][10] = {};
  ll div = 1000000000LL;
  int n;
  cin >> n;
  dp[1][0] = 0;
  for(int i=1; i<=9; i++) dp[1][i] = 1;
  for(int i=2; i<=n; i++) {
    dp[i][0] = dp[i-1][1] % div;
    dp[i][9] = dp[i-1][8] % div;
    for(int j=1; j<9; j++) {
      dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j+1] ) %div;
    }
  }

  ll ans = 0;
  for(int i=0; i<=9; i++) ans = (ans + dp[n][i]) % div;

  cout << ans;
  
  return 0;
}