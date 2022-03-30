/*
Time : 2022.02.10 (10 mins)
Problem : BOJ2910 (https://www.acmicpc.net/problem/2910)
Algorithm Type : Sort
Outline :
N명의 학생의 국/영/수 점수가 주어진다. 다음과 같은 조건으로 학생의 성적을 정렬한다.
국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
정렬한 데로 학생의 이름을 출력한다.
Method :
STL sort의 비교함수를 위 조건에 맞추어 구현한다.
Example :
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90
-------
Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
#define mt make_tuple
typedef long long ll;

bool compare(const tuple<string,int,int,int> &a, const tuple<string,int,int,int> &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b); // 국어 성적 내림차순
  else if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b); // 영어 성적 오름차순
  else if(get<3>(a) != get<3>(b)) return get<3>(a) > get<3>(b); // 영어 성적 내림차순
  return get<0>(a) < get<0>(b);
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
  int n;
  tuple<string,int,int,int> arr[100000+5] = {};
  cin >> n;
  for(int i=0; i<n; i++) {
    string name;
    int k, e, m;
    cin >> name >> k >> e >> m;
    arr[i] = make_tuple(name,k,e,m);
  }
  sort(arr, arr+n, compare);
  for(int i=0; i<n; i++) cout << get<0>(arr[i]) << "\n";
  return 0;
}