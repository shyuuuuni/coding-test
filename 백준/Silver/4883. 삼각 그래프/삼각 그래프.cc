/*
Time : 2022.02.16 (30 mins)
Problem : BOJ4883 (https://www.acmicpc.net/problem/4883)
Algorithm Type : DP
Outline :
이 문제는 삼각 그래프의 가장 위쪽 가운데 정점에서 가장 아래쪽 가운데 정점으로 가는 최단 경로를 찾는 문제이다.
그래프에 각 정점에는 점수가 매겨져 있고, 해당 정점을 지나면 비용을 지불한다.
해당 그래프를 통과하는데 필요한 최소 점수를 출력한다.
Method :

Example :
4
13 7 5
7 13 6
14 3 12
15 6 16
0
-------
1. 22
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

  ll pf[1000000+5] = {};
  ll nf[1000000+5] = {};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  int tc = 0;
  do {
    cin >> n;
    tc++;
    if (n == 0) break;
    int a[100000+5][3] = {};
    int d[100000+5][3] = {};
    for (int i=0; i<n; i++) {
      for (int j=0; j<3; j++) {
        cin >> a[i][j];
      }
    }
    d[0][0] = 10000000;
    d[0][1] = a[0][1];
    d[0][2] = a[0][1] + a[0][2];
    for (int i=1; i<n; i++) {
      d[i][0] = min(d[i-1][0], d[i-1][1]) + a[i][0];
      d[i][1] = min({d[i-1][0], d[i-1][1], d[i-1][2], d[i][0]}) + a[i][1];
      d[i][2] = min({d[i-1][1], d[i-1][2], d[i][1]}) + a[i][2];
    }

    cout << tc << ". " << d[n-1][1] << "\n";
  } while(1);
  return 0;
}