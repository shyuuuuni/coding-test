/*
Time : 2022.02.14 (10 mins)
Problem : BOJ10501 (https://www.acmicpc.net/problem/14501)
Algorithm Type : DP
Outline :
N일동안 하루에 하나씩 상담 요청이 들어온다.
상담은 걸리는 시간 T와 받을 수 있는 비용 P로 구분되어 들어온다.
만약 상담 중 N일이 지나면 해당 상담은 받을 수 없다.
상담을 적절히 했을 때, 받을 수 있는 최대 비용을 계산한다.
Method :

Example :
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200
-------
45
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
  cin >> n;
  pii arr[15+5] = {};
  int dp[15+5] = {};
  for(int i=0; i<n; i++) {
    int t, p;
    cin >> t >> p;
    arr[i] = mp(t,p);
  }
  for(int i=n-1; 0<=i; i--) {
    int t = arr[i].first;
    int p = arr[i].second;
    if(n < i+t) {
      dp[i] = dp[i+1];
      continue;
    }
    dp[i] = max(dp[i+1], p + dp[i+t]);
  }
  cout << *max_element(dp, dp+n);
  return 0;
}