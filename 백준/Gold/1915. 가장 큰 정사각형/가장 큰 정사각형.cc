/*
Time : 2022.02.16
Problem : BOJ1915 (https://www.acmicpc.net/problem/1915)
Algorithm Type : DP
Outline :
n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.
Method :

Example :
4 4
0100
0111
1110
0010
-------
4
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
  int n, m;
  cin >> n >> m;
  int a[1000+5][1000+5] = {};
  int d[1000+5][1000+5] = {};
  for (int i=1; i<=n; i++) {
    string s;
    cin >> s;
    for (int j=1; j<=m; j++) {
      a[i][j] = (s[j-1]=='0'?0:1);
    }
  }
  // d[i][j] : a[i][j]를 오른쪽 아래 꼭짓점으로 하는 정사각형의 한 변의 길이
  /*
  0000
  1110
  1111 -> 1 2 2 1
  111x -> 1 2 3 x

  0000
  0111
  0011 -> 0 0 1 2
  011x -> 0 1 1 x
  */
  int ans = 0;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=m; j++) {
      if (a[i][j] == 0) {
        d[i][j] = 0;
      } else {
        if (d[i][j-1] && d[i-1][j-1] && d[i-1][j]) d[i][j] = min({d[i][j-1], d[i-1][j-1], d[i-1][j]}) + 1;
        else d[i][j] = 1;
      }
      ans = max(ans, d[i][j]);
    }
  }

  cout << ans*ans;

  return 0;
}