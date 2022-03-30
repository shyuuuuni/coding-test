/*
Time : 2022.02.09 (10 mins)
Problem : BOJ12852 (https://www.acmicpc.net/problem/12852)
Algorithm Type : Dynamic Programming
Outline :
정수 X에 다음과 같은 세가지 연산을 수행할 수 있다.
X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
N이 주어졌을 때, 연산의 수가 최소가 되는 횟수와 해당 수를 출력한다.
Method :

Example :
10
-------
3
10 9 3 1
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

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

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int x;
  int d[1000000+5] = {0, }; // d[i] : i가 1로 가는데 필요한 최소 연산 수
  int path[1000000+5] = {0, }; // path[i] : i가 1로 가는 경로에서, i 다음으로 가야 하는 수
  d[1] = 0;
  d[2] = 1;
  d[3] = 1;
  path[1] = 0;
  path[2] = 1;
  path[3] = 1;
  for(int i=4; i<=1000000; i++) {
    d[i] = 1000000+1000;
    if(i%3 == 0) {
      if(d[i/3]+1 < d[i]) {
        d[i] = d[i/3] + 1;
        path[i] = i/3;
      }
    }
    if(i%2 == 0) {
      if(d[i/2]+1 < d[i]) {
        d[i] = d[i/2] + 1;
        path[i] = i/2;
      }
    }
    if(d[i-1]+1 < d[i]) {
      d[i] = d[i-1] + 1;
      path[i] = i-1;
    }
  }
  cin >> x;
  cout << d[x] << "\n";
  while(1 <= x) {
    cout << x << " ";
    x = path[x];
  }
  return 0;
}