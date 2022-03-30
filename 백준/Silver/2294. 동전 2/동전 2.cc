/*
Time : 2022.02.17
Problem : BOJ2294 (https://www.acmicpc.net/problem/2294)
Algorithm Type : DP
Outline :
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다.
그러면서 동전의 개수가 최소가 되도록 하려고 한다.
각각의 동전은 몇 개라도 사용할 수 있다.
필요한 동전의 최소 개수를 출력한다.
(동전 1과 다른점은, 각 동전의 가치가 같을 수도 있다. 또한 출력하는 답은 동전의 최소 개수이다.)
Method :

Example :
3 15
1
5
12
-------
3
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
  int a[100+5] = {};
  int d[100000+5] = {};
  int n, k;
  cin >> n >> k;
  fill(d, d+100000+5, 100000+5);
  d[0] = 0;
  for (int i=0; i<n; i++) {
    cin >> a[i];
    d[a[i]] = 1; // 입력된 동전 하나로 가능
  }
  for (int i=0; i<n; i++) {
    int coin = a[i];
    for (int j=coin; j<=k; j++) {
      d[j] = min(d[j-coin]+1, d[j]); // j원을 만드는데 필요한 코인의 최소 개수
    }
  }
  cout << (d[k]==100000+5?-1:d[k]);
  return 0;
}