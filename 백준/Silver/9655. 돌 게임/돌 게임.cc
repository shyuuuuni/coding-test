/*
Time : 2022.02.16
Problem : BOJ9655 (https://www.acmicpc.net/problem/9655)
Algorithm Type : DP
Outline :
상근이->창영이 순서로 돌을 1개 혹은 3개 가져가는 게임이 있다.
돌이 N개 있을 때, 게임을 완벽하게 할 경우 승자를 구하시오.
Method :
Example :
7
1 2 1 3 1 2 1
4
1 3
2 5
3 3
5 7
-------
1
0
1
1
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


int a[2000+5] = {};
int d[2000+5][2000+5] = {};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  /*
  SY,CY
  n=1
  S
  n=2
  S C
  n=3
  SSS
  n=4
  S CCC or SSS C
  n=5
  S C SSS or S CCC S or SSS C S
  n=6
  SSS CCC or S C SSS C or S CCC S C or 
  항상 돌이 +1 or +3이므로
  선영이가 가져가면 홀수번째, 창영이가 가져가면 짝수번째임
  승자 = n-1 or n-3에 도착할 수 있는 사람
  -> n이 홀수면 선영이, n이 짝수면 창영이
  */
  if (n%2==0) cout << "CY";
  else cout << "SK";
  return 0;
}