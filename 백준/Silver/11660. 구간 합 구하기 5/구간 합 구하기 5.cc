/*
Time : 2022.02.17
Problem : BOJ11660 (https://www.acmicpc.net/problem/11660)
Algorithm Type : DP
Outline :
NxN 배열에 수가 주어져있다.
M개의 구간합을 출력하라는 명령이 주어졌을때, 명령을 처리하는 프로그램을 작성한다.
Method :

Example :
4 3
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7
2 2 3 4
3 4 3 4
1 1 4 4
-------
27
6
64
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


int a[1024+5][1024+5] = {};
int d[1024+5][1024+5] = {}; // d[i][j] : i번째 row에서 1번째부터 j번째 원소까지의 합

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> a[i][j];
      d[i][j] = d[i][j-1] + a[i][j];
    }
  }
  while (m--) {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = 0;
    for (int i=x1; i<=x2; i++) {
      ans += (d[i][y2] - d[i][y1-1]);
    }
    cout << ans << "\n";
  }
  return 0;
}