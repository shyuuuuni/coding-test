/*
Time : 2022.02.08 (10 mins)
Problem : BOJ2910 (https://www.acmicpc.net/problem/2910)
Algorithm Type : Sort
Outline :
N개의 숫자로 이루어진 메세지가 주어진다. (숫자는 모두 C보다 작거나 같다)
해당 메세지의 수를 빈도순으로 정렬하려고 한다.
먼저 두 수중에 더 많이 등장하는 수가 앞에 위치한다.
만약 등장하는 횟수가 같다면 먼저 나온 것이 앞에 있어야 한다.
Method :
compare함수를 조건에 맞춰 구현하여 해결한다.
중복을 막기 위해 set을 이용한다.
Example :
5 2
2 1 2 1 2
-------
2 2 2 1 1
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

ll n, c, cnt=0;
map<ll,ll> seq;
vector<pair<ll,ll> > v(1000+5);

bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  if(a.second != b.second) return (b.second < a.second);
  return seq[a.first] < seq[b.first];\
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
  cin >> n >> c;
  for(int i=0; i<n; i++) {
    ll tmp;
    cin >> tmp;
    if(seq.find(tmp) == seq.end()) {
      seq[tmp] = cnt++;
      v[seq[tmp]] = mp(tmp,0);
    }
    v[seq[tmp]].second++;
  }
  sort(v.begin(), v.begin()+cnt, compare);
  for(int i=0; i<cnt; i++) {
    pair<ll,ll> pll = v[i];
    for(int j=0; j<pll.second; j++) cout << pll.first << " ";
  }
  return 0;
}