/*
Time : 2022.02.14 (30 mins)
Problem : BOJ15988 (https://www.acmicpc.net/problem/15988)
Algorithm Type : DP
Outline :
정수 N을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.
수가 커질 수 있으므로 1000000009로 나눈 나머지를 출력한다.
Method :
정수 4를 1,2,3의 합으로 나타내는 경우는 다음과 같이 나눌 수 있다.
1. (1을 합으로 나타내는 경우의 수) + (3을 붙임)
2. (2를 합으로 나타내는 경우의 수) + (2를 붙임)
3. (3을 합으로 나타내는 경우의 수) + (1을 붙임)
위와 같이 세 가지의 합으로 경우의 수를 표현할 수 있다.
따라서 이를 확장하여 정수 n은 n-1, n-2, n-3번째 dp배열을 이용하여 구할 수 있다.
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
  int n;
  ll d[1000000+5] = {};

  d[0] = 0LL;
  d[1] = 1LL;
  d[2] = 2LL;
  d[3] = 4LL;
  
  for (int i=4; i<=1000000; i++) {
    d[i] = ((d[i-1] + d[i-2]) % 1000000009LL + d[i-3]) % 1000000009LL;
  }

  int tc;
  cin >> tc;

  while (tc--) {
    cin >> n;
    cout << d[n] << "\n";
  }

  return 0;
}