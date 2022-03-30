/*
Time : 2022.03.07
Problem : BOJ15684 (https://www.acmicpc.net/problem/15684)
Algorithm Type : Simulation
Outline :
N개의 세로선과 M개의 가로선으로 이루어진 선에서 사다리게임을 하려고 한다.
가로선과 세로선이 교차하는 부분을 선으로 이을 수 있다. (즉, 가로선은 인접한 두 세로선을 연결한다.)
그러나 두 가로선이 인접하거나, 접해서는 안된다.
가로선을 추가로 그어서 i번째 세로선이 i번째 세로선으로 도착할 수 있도록 만드는
가로선의 최소 개수를 출력한다.
Method :

Example :
5 5 6
1 1
3 2
2 3
5 1
5 4
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

int n, m, h; // 세로선, (현재)가로선, 높이
int lines[30+5][30+5]; // lines[i][j] : 위에서 i번째 가로줄에서, j~j+1번째 세로줄 사이의 가로줄 상태, 0-indexed
vector<pii> validlist;

bool isvalid(pii xy) {
  return !(lines[xy.X][xy.Y-1] || lines[xy.X][xy.Y] || lines[xy.X][xy.Y+1]);
}

void printline();

bool check() {
  // 현재 상태에서 사다리를 타서 모든 사다리가 각각 자기 번호로 오는지 리턴
  // printline();
  bool ret = true;
  for (int i=1; i<=n && ret; i++) {
    int cur = i;
    for (int j=1; j<=h; j++) {
      // cout << "ljc : " << lines[j][cur] << "\n";
      // cout << j << "from " << cur << "to ";
      if (lines[j][cur]) {
        cur = cur+1;
      } else if (lines[j][cur-1]) {
        cur = cur-1;
      } else {
        cur = cur;
      }
      // cout << cur << "\n";
    }
    if (cur != i) ret = false;
  }
  return ret;
}

void printline() {
  for (int i=1; i<=h; i++) {
    for (int j=1; j<=n-1; j++) {
      cout << lines[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "==\n";
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> h; // 세로, 가로, 높이

  // 입력
  for (int i=0; i<m; i++) {
    int a, b;
    cin >> a >> b;
    lines[a][b] = 1;
  }

  // printline();

  // 선택할 수 있는 사다리 리스트
  for (int i=1; i<=h; i++) {
    for (int j=1; j<=n-1; j++) {
      if (!isvalid(mp(i,j))) continue;
      else validlist.push_back(mp(i,j));
    }
  }

  // 0일때 체크
  if (check()) {
    cout << 0;
    return 0;
  }


  int ans = 100;

  // 1, 2, 3일때 체크 (백트래킹)
  for (int i=0; i<(int)validlist.size(); i++) {
    if (isvalid(validlist[i])) {
      lines[validlist[i].X][validlist[i].Y] = 1;
    } else {
      continue;
    }
    if (check()) {
      cout << 1;
      return 0;
    }
    for (int j=i+1; j<(int)validlist.size(); j++) {
      if (isvalid(validlist[j])) {
        lines[validlist[j].X][validlist[j].Y] = 1;
      } else {
        continue;
      }
      if (check()) {
        ans = min(ans, 2);
      }
      for (int k=j+1; k<(int)validlist.size(); k++) {
        if (isvalid(validlist[k])) {
          lines[validlist[k].X][validlist[k].Y] = 1;
        } else {
          continue;
        }
        if (check()) {
          ans = min(ans, 3);
        }
        lines[validlist[k].X][validlist[k].Y] = 0;
      }
      lines[validlist[j].X][validlist[j].Y] = 0;
    }
    lines[validlist[i].X][validlist[i].Y] = 0;
  }

  cout << (ans==100?-1:ans);

  return 0;
}