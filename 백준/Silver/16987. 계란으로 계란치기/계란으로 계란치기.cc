/*
Time : 2022.02.22
Problem : BOJ16987 (https://www.acmicpc.net/problem/16987)
Algorithm Type : Backtracking
Outline :
계란들이 일렬로 놓아져있다.
각 계란별로 무게와 내구도가 정해져있다.
계란으로 계란을 치는 경우 각 계란의 내구도는 상대 계란의 무게만큼 깎이게 된다.
그리고 내구도가 0 이하가 될 경우 계란이 깨지게 된다.
가장 왼쪽에 있는 계란부터 들어서 다른 계란을 깨려고 한다.
계란별로 다른 계란을 한번씩 칠 수 있다.
이후에는 방금 들었던 계란의 오른쪽 계란을 들고 위와 같은 과정을 반복한다.
최대 몇개의 계란을 깰 수 있는지 출력한다.
Method :

Example:
3
8 5
1 100
3 5
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

ll dx[6] = {1,-1,0,0,0,0};
ll dy[6] = {0,0,1,-1,0,0};
ll dz[6] = {0,0,0,0,1,-1};

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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

int charToInt(char c) {
  if ('A' <= c && c <= 'Z')
    return (int)(c - 'A');
  else if ('a' <= c && c <= 'z')
    return (int)(c - 'a');
  else if ('0' <= c && c <= '9')
    return (int)(c - '0');
  return -1;
}

int n;
int s[10]; // 내구도
int w[10]; // 무게
int ans = 0;

void dfs(int idx, int bk) {
  if (n < idx) {
    ans = max(ans, bk);
    return;
  }

  if (s[idx] <= 0) { // 현재 계란이 부셔진 경우
    dfs(idx+1,bk);
    return;
  }
  
  int flag = 0;

  for (int i=1; i<=n; i++) { // idx번째 계란을 들고 i번째 계란을 한번 친다.
    if (i == idx) continue; // 다른 계란을 쳐야 함.
    if (s[i] <= 0) continue; // 해당 계란은 부셔져서 칠 수 없음.
    // i번째 계란을 친다.
    int bki = bk;
    s[i] -= w[idx];
    s[idx] -= w[i];
    if (s[i] <= 0) bki++;
    if (s[idx] <= 0) bki++;
    dfs(idx+1, bki);
    s[i] += w[idx];
    s[idx] += w[i];
  }

  if (!flag) { // 다른 계란을 칠 수 없는 경우
    dfs(n+1, bk);
  }
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i=1; i<=n; i++) {
    cin >> s[i] >> w[i];
  }

  dfs(1,0);

  cout << ans;

  return 0;
}