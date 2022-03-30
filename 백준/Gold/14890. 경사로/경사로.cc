/*
Time : 2022.03.07
Problem : BOJ14890 (https://www.acmicpc.net/problem/14890)
Algorithm Type : Simulation,
Outline :
NxN 크기의 지도의 각 칸에 그 높이가 적혀있다.
지도의 한쪽 끝에서 반대쪽 끝으로 길을 따라 이동하려고 한다.
길을 지나갈 수 있으려면, 길에 속한 모든 길의 높이가 같아야 한다.
또는 경사로를 놓아서 길을 만들 수 있는데 경사로는 다음과 같은 특성을 갖는다.
1. 경사로의 높이는 1이며 길이는 L이다. (경사로의 개수는 부족함이 없다.)
2. 경사로는 높이가 낮은 칸에 놓아서, L개의 연속된 칸에 놓아야 한다.
3. 경사로를 놓는 칸의 높이는 같아야 한다.
즉, 다음과 같은 경우 경사로를 놓을 수 없다.
1. 경사로인 곳에 또 경사로를 놓는 경우
2. 낮은 칸과 높은 칸의 높이차가 1이 아닌 경우
3. 낮은 칸의 높이가 모두 같지 않거나, L칸이 연속되지 않은 경우
4. 경사로를 놓다가 범위를 벗어나는 경우
지나갈 수 있는 길의 개수를 출력한다.
Method :

Example :
6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2
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

int n, l;
int a[100+1][100+1];

// 왼->오 검사
int checkrow(int r, int x, int is_jump) {
  if (x == n-1) return 1;

  int flag = 0;
  int nx;
  int prev;

  // 경사로가 필요한지 확인
  nx = x + l;
  if (!outOfBound0(nx,r,n,n)) {
    int cur_flag = 1;
    if (a[r][x]-a[r][nx] == 1) {
      // 현재 위치가 nx보다 한칸 높음 -> x+1부터 nx까지 내리막 경사로 설치
      for (int i=x+1; i<=x+l; i++) {
        if (i == x+1) prev = a[r][i];
        else if (prev != a[r][i]) cur_flag = 0;
      }
      if (cur_flag) { // 경사로 가능
        flag += checkrow(r, nx, 1);
      }
    } else if (a[r][x]-a[r][nx] == -1 && !is_jump) {
      // 현재 위치가 nx보다 한칸 낮음 -> x부터 x+l-1까지 오르막 경사로 설치
      for (int i=x; i<x+l; i++) {
        if (i == x) prev = a[r][i];
        else if (prev != a[r][i]) cur_flag = 0;
      }
      if (cur_flag) {
        flag += checkrow(r, nx, 0);
      }
    } else {
      // 경사로 필요 없음
    }
  } else {

  }
  
  // 한칸 앞으로 걸어감
  nx = x + 1;
  if (!outOfBound0(nx,r,n,n) && a[r][x] == a[r][nx]) {
    flag += checkrow(r, nx, 0);
  }

  return flag;
}


// 위->아래 검사
int checkcol(int c, int x, int is_jump) {
  if (x == n-1) return 1;

  int flag = 0;
  int nx;
  int prev;

  // 경사로가 필요한지 확인
  nx = x + l;
  if (!outOfBound0(c,nx,n,n)) {
    int cur_flag = 1;
    if (a[x][c]-a[nx][c] == 1) {
      // 현재 위치가 nx보다 한칸 높음 -> x+1부터 nx까지 내리막 경사로 설치
      for (int i=x+1; i<=x+l; i++) {
        if (i == x+1) prev = a[i][c];
        else if (prev != a[i][c]) cur_flag = 0;
      }
      if (cur_flag) { // 경사로 가능
        flag += checkcol(c, nx, 1);
      }
    } else if (a[x][c]-a[nx][c] == -1 && !is_jump) {
      // 현재 위치가 nx보다 한칸 낮음 -> x부터 x+l-1까지 오르막 경사로 설치
      for (int i=x; i<x+l; i++) {
        if (i == x) prev = a[i][c];
        else if (prev != a[i][c]) cur_flag = 0;
      }
      if (cur_flag) {
        flag += checkcol(c, nx, 0);
      }
    } else {
      // 경사로 필요 없음
    }
  } else {

  }
  
  // 한칸 앞으로 걸어감
  nx = x + 1;
  if (!outOfBound0(c,nx,n,n) && a[x][c] == a[nx][c]) {
    flag += checkcol(c, nx, 0);
  }

  return flag;
}


int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> l;
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      cin >> a[i][j];
    }
  }
  
  int ans = 0;

  // 왼->오, 오->왼 체크
  for (int row=0; row<n; row++) {
    // int cur = checkrow(row,0,0) + checkrow(row,n-1,1);
    int cur = checkrow(row,0,0);
    if (cur) {
      ans++;
    }
  }

  // 위->아래, 아래->위 체크
  for (int col=0; col<n; col++) {
    int cur = checkcol(col,0,0);
    if (cur) {
      ans++;
    }
  }

  cout << ans;
  return 0;
}