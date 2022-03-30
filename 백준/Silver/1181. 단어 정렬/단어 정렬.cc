/*
Time : 2022.02.08 (10 mins)
Problem : BOJ1181 (https://www.acmicpc.net/problem/1181)
Algorithm Type : Sort
Outline :
N개의 문자열을 다음과 같은 조건으로 정렬하여 출력한다.
1. 길이가 짧은 것 부터
2. 길이가 같다면 사전 순으로
Method :
compare함수를 조건에 맞춰 구현하여 해결한다.
중복을 막기 위해 set을 이용한다.
Example :
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
-------
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
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
  if(a.size() != b.size()) return a.size() < b.size();
  return a < b;
}

// 셋 정렬용 구조체
struct setOrder {
  bool operator() (const string& left, const string& right) const {
    // 비교함수
    if(left.size() != right.size()) return left.size() < right.size();
    return left < right;
  }
};

int n;
string arr[20000+5];
set<string, setOrder> ans;

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) {
    string s;
    cin >> s;
    ans.insert(s);
  }
  for(auto s : ans) cout << s << "\n";
  return 0;
}