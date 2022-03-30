/*
Time : 2022.02.10 (10 mins)
Problem : BOJ2910 (https://www.acmicpc.net/problem/2910)
Algorithm Type : Sort
Outline :
문자열 S의 모든 접미사를 사전순으로 출력한다.
Method :
STL의 substr을 이용하여 정렬용 벡터에 모든 접미사를 넣고,
사전순으로 정렬한 후 출력한다.
Example :
baekjoon
-------
aekjoon
baekjoon
ekjoon
joon
kjoon
n
on
oon
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define ll long long

bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b) {
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
  string s;
  cin >> s;
  vector<string> arr;
  for(int i=0; i<(int)s.size(); i++) {
    string tmp = s.substr(i);
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());
  for(int i=0; i<(int)arr.size(); i++) cout << arr[i] << "\n";
  return 0;
}