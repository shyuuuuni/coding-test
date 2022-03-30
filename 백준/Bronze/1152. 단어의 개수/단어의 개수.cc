/*
Time : 2022.02.11 (10 mins)
Problem : BOJ1152 (https://www.acmicpc.net/problem/1152)
Algorithm Type : Dynamic Programming
Outline :
단어가 공백으로 구분되어 입력된다.
단어의 개수를 출력한다.
Method :
연속해서 들어오는 공백은 없으므로 공백의 개수 + 1 을 출력한다.
Example :
The Curious Case of Benjamin Button
-------
6
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

int splitStringByToken(vector<string> &v, string &s, const char &del) {
  v.clear();
  if(s.empty()) return 0;
  
  istringstream ss(s);
  string stringBuffer;
  while (getline(ss, stringBuffer, del))
  {
    if(!stringBuffer.empty()) v.push_back(stringBuffer);
  }  

  return v.size();
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  vector<string> tokens;
  getline(cin,s);
  cout << splitStringByToken(tokens, s, ' ');
  return 0;
}