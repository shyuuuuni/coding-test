/*
Time : 2022.02.16 (30 mins)
Problem : BOJ1904 (https://www.acmicpc.net/problem/1904)
Algorithm Type : DP
Outline :
타일에 숫자가 [1], [00] 이 써져 있다.
이러한 타일을 붙여서 이진수열을 만들 때, 길이가 N인 이진수열의 개수를 출력한다.
Method :

Example :
4
-------
5
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

  /*
  n=1
  1
  
  n=2
  00 11

  n=3
  001 111 100

  n=4
  0011 1111 1001 / 0000 1100

  */

  int d[1000000+5] = {};
  d[0] = 0;
  d[1] = 1;
  d[2] = 2;
  for (int i=3; i<=n; i++) {
    d[i] = (d[i-1] + d[i-2]) % 15746;
  }

  cout << d[n];

  return 0;
}