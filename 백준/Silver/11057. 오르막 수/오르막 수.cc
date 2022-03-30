/*
Time : 2022.02.15 (30 mins)
Problem : BOJ11057 (https://www.acmicpc.net/problem/11057)
Algorithm Type : DP
Outline :
오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다. 이때, 인접한 수가 같아도 오름차순으로 친다.
수의 길이 N이 주어졌을 때, 오르막 수의 개수를 구하는 프로그램을 작성하시오. 수는 0으로 시작할 수 있다.
Method :

Example :
2
-------
55
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

  int d[1000+1][10] = {}; // d[i][j] : 길이가 i이고, 끝이 j로 끝나는 오르막 수의 개수
  for (int i=0; i<10; i++) d[1][i] = 1;
  for (int i=2; i<=n; i++) {
    for (int j=0; j<10; j++) {
      for (int k=j; k<10; k++) {
        d[i][k] = (d[i][k] + d[i-1][j]) % 10007;
      }
    }
  }

  ll ans = 0;
  for (int i=0; i<10; i++) {
    ans = (ans + d[n][i]) % 10007;
  }

  cout << ans;
  

  return 0;
}