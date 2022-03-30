/*
Time : 2022.02.14 (10 mins)
Problem : BOJ14003 (https://www.acmicpc.net/problem/14003)
Algorithm Type : DP, Binary Search
Outline :
수열이 주어졌을 때, 수열 내에서 가장 긴 증가하는 부분수열을 구하는 프로그램을 작성한다.
출력으로 LIS의 길이와, 그 LIS중 하나를 아무거나 출력한다.
Method :
dp배열은 각 i<j 에 대해, dp[i] < dp[j] 가 되도록 유지하는 배열이다.
만약 현재 보는 원소가 dp의 마지막 원소보다 크다면 그냥 dp[++len] 자리에 해당 원소를 추가하면 된다.
하지만 그렇지 않다면 해당 원소의 lower_bound index에 입력하게 된다.
이때 lower bound를 구할 때 O(log n)이 걸리고, 전체가 O(n) 이므로 O(n log n)에 해결 가능하다.
(원리)
n = 3
{10, 30, 20} 인 경우
dp = {10} len = 1
dp = {10, 30} len = 2 (마지막 dp보다 크므로 추가)
dp = {10, 20} len = 2 (20의 lower bound 자리에 삽입)
이 경우 30을 20이 대체하게 되는데, {10, 30}도 증가하는 부분수열이지만, 이후 수열에 25와 같은 숫자가 있다면
{10, 20, 25}는 가능하지만 {10, 30, 25}는 불가능하기 때문에 대체해준다.
그러나 위 dp 배열은 LIS를 저장하는 배열이 아니기 때문에
idx 배열을 하나 추가해서, 해당 원소가 dp배열의 몇번째 인덱스에 들어갔는지 입력한다.
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

int arr[1000000+5] = {};
int idx[1000000+5] = {-1, };
int dp[1000000+5] = {-1000000000-5, };

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, len=0;
  
  cin >> n;
  for (int i=1; i<=n; i++) cin >> arr[i];

  for (int i=1; i<=n; i++) {
    if (dp[len] < arr[i]) {
      dp[++len] = arr[i];
      idx[i] = len;
      continue;
    }

    int point = lower_bound(dp+1, dp+len+1, arr[i]) - (dp); // 삽입 위치
    dp[point] = arr[i];
    idx[i] = point;
  }

  cout << len << "\n";

  stack<int> ans;
  for (int i=n; 1<=i; i--) {
    if (len == 0) break;
    if (idx[i] == len) {
      if (ans.empty()) {
        ans.push(arr[i]);
        len--;
      } else if (ans.top() < arr[i]) {
        continue;
      } else {
        ans.push(arr[i]);
        len--;
      }
    }
  }

  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }

  

  return 0;
}