/*
Time : 2022.02.14 (10 mins)
Problem : BOJ2748 (https://www.acmicpc.net/problem/2748)
Algorithm Type : DP
Outline :
N번째 피보나치 수를 출력한다.
Method :
크기에 주의하며 DP로 구현한다.
Example :
10
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
  ll fib[100] = {};
  fib[1] = fib[2] = 1;
  int n;
  cin >> n;
  for(int i=3; i<100; i++) {
    fib[i] = fib[i-1] + fib[i-2];
  }
  cout << fib[n];
  return 0;
}