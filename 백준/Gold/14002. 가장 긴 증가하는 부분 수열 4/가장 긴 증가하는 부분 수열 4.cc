/*
Time : 2022.02.14 (10 mins)
Problem : BOJ14002 (https://www.acmicpc.net/problem/14002)
Algorithm Type : DP, Binary Search
Outline :
수열이 주어졌을 때, 수열 내에서 가장 긴 증가하는 부분수열을 구하는 프로그램을 작성한다.
출력으로 LIS의 길이와, 그 LIS중 하나를 아무거나 출력한다.
Method :

Example :
6
10 20 10 30 20 50
-------
4
10 20 30 50
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

const int arrlen = 1000+5;
const int wlen = 30+5;
int arr[arrlen];
int d[arrlen][wlen][3];

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, len=0;
  int arr[1000+5] = {};
  int idx[1000+5] = {};
  int dp[1000+5] = {};

  cin >> n;
  for (int i=1; i<=n; i++) cin >> arr[i];

  for (int i=1; i<=n; i++) {
    if (dp[len] < arr[i]) {
      dp[++len] = arr[i];
      idx[i] = len;
      continue;
    }

    int point = lower_bound(dp+1, dp+len+1, arr[i]) - (dp); // 삽입 위치
    // cout << arr[i] << " " << point << "\n";
    dp[point] = arr[i];
    idx[i] = point;
  }

  cout << len << "\n";

  // for(int i=1; i<=n; i++) cout << idx[i] << " ";
  // cout << "\n";

  stack<int> ans;
  for (int i=n; 1<=i; i--) {
    if (idx[i] == len) {
      ans.push(arr[i]);
      len--;
    }
  }

  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }

  

  return 0;
}