/*
Time : 2022.02.14 (10 mins)
Problem : BOJ9461 (https://www.acmicpc.net/problem/9461)
Algorithm Type : DP
Outline :
삼각형이 나선 모양으로 이어져 있는 삼각형의 각 변의 길이를 나타내는 파도반 수열이 있다.
삼각형의 개수 n이 주어졌을 때, n번째 삼각형의 변의 길이를 출력한다.
Method :
수열의 규칙은 DP[i] = DP[i-2] + DP[i-3] 이므로, base condition만 잘 설정하고
다이나믹 프로그래밍으로 해결한다.
Example :
2
6
12
-------
3
16
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
  ll dp[100 + 5] = {};
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  for(int i=4; i<=100; i++) dp[i] = dp[i-2] + dp[i-3];
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    cout << dp[n] << "\n";
  }
  return 0;
}