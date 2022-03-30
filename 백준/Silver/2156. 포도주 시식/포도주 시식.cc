/*
Time : 2022.02.14 (30 mins)
Problem : BOJ2156 (https://www.acmicpc.net/problem/2156)
Algorithm Type : DP
Outline :
포도주가 들어있는 포도주 잔이 일렬로 놓여 있다.
포도주 시식을 위해 다음과 같은 규칙이 존재한다.
포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
효주는 가능한 많은 양의 포도주를 맛보기 위해서 적절한 포도주 잔을 선택할지 고민한다.
최대로 마실 수 있는 포도주의 양을 출력한다.
Method :
dp 배열을 dp[i] : i번째 포도주 잔 까지 확인했을 때 최대 합 으로 정의한다.
기본 조건으로 dp[0] = a[0], dp[1] = a[0] + a[1] 을 둔다. (조건 없이 최대한 집는 경우)
이후에는 문제에서 주어진 조건대로 3개 연속으로 마실 수 없다는 조건을 추가한다.
(i-4), (i-3), (i-2), (i-1), (i), (i+1), ... 이런식으로 확인하고 있을 때,
다음과 같은 세 가지 경우가 발생한다.
1. i번째 포도주를 마시지 않는 경우 -> dp[i-1]
2. (i-1)번째 포도주를 마시지 않는 경우 -> dp[i-2] + a[i]
3. (i-2)번째 포도주를 마시지 않는 경우 -> dp[i-3] + a[i-1] + a[i]
즉 위와 같은 경우를 단순 코딩하면 된다.
Example :
6
6
10
13
9
8
1
-------
33
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
  int a[10000+5] = {};
  int d[10000+5] = {};
  int n;

  cin >> n;
  for (int i=0; i<n; i++) {
    cin >> a[i];
  }

  // base condition
  d[0] = a[0];
  d[1] = a[0] + a[1];

  // dp
  for (int i=2; i<n; i++) {
    d[i] = max({d[i-1], d[i-2]+a[i], d[i-3]+a[i-1]+a[i]});
  }

  cout << d[n-1];

  return 0;
}