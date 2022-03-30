/*
Time : 2022.02.15 (30 mins)
Problem : BOJ9465 (https://www.acmicpc.net/problem/9465)
Algorithm Type : DP
Outline :
2XN 판에 스티커가 붙어있다.
각 스티커에는 점수가 있고, 그 스티커를 떼면 점수를 얻을 수 있다.
해당 스티커를 때면 스티커 상하좌우의 스티커는 망가져서 뗄 수 없다.
얻을 수 있는 최대 점수를 구하시오.
Method :

Example :
2
5
50 10 100 20 40
30 50 70 10 60
7
10 30 10 50 100 20 40
20 40 30 50 60 20 80
-------
260
290
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

  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    int ans = 0;
    int a[3][100000+5] = {};
    int d[3][100000+5] = {};

    cin >> n;

    for (int i=0; i<2; i++) {
      for (int j=0; j<n; j++) {
        cin >> a[i][j];
      }
    }

    // d[i][j] : j번째 column까지 봤을 때
    // d[0][j] : 0번째 줄을 선택했을 때 최댓값, d[1][j] : 1번째 "", d[2][j] : 해당 col에서 선택X

    d[0][0] = a[0][0];
    d[1][0] = a[1][0];
    d[2][0] = 0;

    ans = max(d[0][0], d[1][0]);

    for(int i=1; i<n; i++) {
      d[0][i] = max(d[1][i-1], d[2][i-1]) + a[0][i];
      d[1][i] = max(d[0][i-1], d[2][i-1]) + a[1][i];
      d[2][i] = max(d[0][i-1], d[1][i-1]);
      ans = max(ans, d[0][i]);
      ans = max(ans, d[1][i]);
      ans = max(ans, d[2][i]);
    }

    cout << ans << "\n";

  }
  return 0;
}