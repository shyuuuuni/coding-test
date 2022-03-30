/*
Time : 2022.02.19
Problem : BOJ2482 (https://www.acmicpc.net/problem/2482)
Algorithm Type : DP, 백트래킹
Outline :
N개의 색을 나열한 색상환에서 K개의 색을 선택하려고 한다.
인접한 색은 구분이 잘 가지 않으므로 선택하지 않으려고 한다.
N색상환에서 K개의 색을 선택하는 경우의 수를 출력한다.
Method :

Example :
4 2
-------
2
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

ll dx[6] = {1,-1,0,0,0,0};
ll dy[6] = {0,0,1,-1,0,0};
ll dz[6] = {0,0,0,0,1,-1};

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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}


bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}



  ll d[2][2][1000+5][1000+5] = {}; // [현재꺼 선택여부, 1 선택여부, 총합, i번째]
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n,k;
  ll div =  1000000003LL;
  ll ans = 0;
  cin >> n >> k;
  if (n/2 < k) {
    cout << 0;
    return 0;
  }
  d[1][1][1][1] = 1;
  d[0][0][0][1] = 1;
  for (int i=2; i<=n; i++) {
    d[0][0][0][i] = 1;
    d[0][1][0][i] = 0;
    d[1][0][0][i] = d[1][1][0][i] = 0;
    for (int j=1; j<=k && j<=i; j++) {
      if (i == n) {
        // 첫번째꺼가 선택된 경우 마지막꺼는 선택할 수 없음.
        d[0][1][j][i] = (d[0][1][j][i-1] + d[1][1][j][i-1]) % div;
        d[1][1][j][i] = 0;  
        d[0][0][j][i] = (d[0][0][j][i-1] + d[1][0][j][i-1]) % div;
        d[1][0][j][i] = d[0][0][j-1][i-1];
      } else {
        // 첫번재꺼를 선택하지 않은 경우
        d[0][0][j][i] = (d[0][0][j][i-1] + d[1][0][j][i-1]) % div; // i번째를 선택하지 않음
        d[1][0][j][i] = d[0][0][j-1][i-1]; // i번째를 선택함
        // 첫번째꺼를 선택한 경우
        d[0][1][j][i] = (d[0][1][j][i-1] + d[1][1][j][i-1]) % div; // i번째를 선택하지 않음
        d[1][1][j][i] = d[0][1][j-1][i-1]; // i번째를 선택함
      }
      // cout << "i, j : " << i << " " << j << "\n";
      // cout << d[0][0][j][i] << " " << d[1][0][j][i] << " " << d[0][1][j][i] << " " << d[1][1][j][i] << "\n";
    }
  }

  ans = (ans + d[0][0][k][n]) % div;

  // cout << ans << "\n";
  ans = (ans + d[0][1][k][n]) % div;

  // cout << ans << "\n";
  ans = (ans + d[1][0][k][n]) % div;

  // cout << ans << "\n";

  ans = (ans + d[1][1][k][n]) % div;
  cout << ans << "\n";

  

  
  return 0;
}