/*
Time : 2022.02.15 (30 mins)
Problem : BOJ2302 (https://www.acmicpc.net/problem/2302)
Algorithm Type : DP
Outline :
1번부터 N번까지 좌석 번호와 공연을 보러 온 사람의 좌석 번호가 주어진다.
좌석 번호가 주어지면 해당 사람은 그 번호 뿐만 아니라 양 옆의 번호에도 앉을 수 있다.
VIP 자리는 해당 VIP만 앉을 수 있다.
사람들이 좌석에 앉는 서로다른 가짓수를 출력한다.
Method :

Example :
9
2
4
7
-------
12
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

int n, m;
int a[40+5];
int d[40+5][2]; // 0일 경우 i번째 자리에 i번째 사람이

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  cin >> m;

  for (int i=0; i<m; i++) {
    int vip;
    cin >> vip;
    a[vip] = 1;
  }

  d[1][0] = 1;
  d[1][1] = 0;

  for (int i=2; i<=n; i++) {
    d[i][0] = d[i-1][0] + d[i-1][1];
    if (a[i]) {
      // VIP석일 경우
      d[i][1] = 0; // 무조건 VIP가 앉음
    } else {
      // 일반석일 경우
      d[i][1] = (a[i-1] ? 0 : d[i-1][0]);
    }
  }

  /*
  1 2 3 (4) 5
  */

  int ans = 0;
  for (int i=1; i<=n; i++) {
    int cur = 0;
    for (int j=0; j<2; j++) {
      cur += d[i][j];
      // cout << d[i][j] << " " ;
    }
    // cout << '\n';
    ans = max(ans, cur);
  }

  cout << ans;

  return 0;
}