/*
Time : 2022.03.09
Problem : BOJ13168 (https://www.acmicpc.net/problem/13168)
Algorithm Type : 플로이드-와샬 알고리즘
Outline :
N개의 도시가 있고, 그 중에서 M개의 도시를 여행하기로 결정하였다.
이때 여행을 시작하는 도시와 끝내는 도시가 같아야 한다.
여행을 위한 K개의 교통수단이 있으며, 내일로 티켓이라는 것이 존재한다.
내일로 티켓을 구매하면 무궁화호, ITX호는 무료로 / S,V-Train은 50퍼센트 할인된 가격으로 탈 수 있다.
내일로 티켓을 구매하는 것이 더 저렴하면 YES를, 아니면 NO를 출력한다.
Method :

Example :
14 40000
Boseong Busan Changwon Cheonan Chuncheon Daegu Daejeon Gwangju Jeonju Jinju Masan Seoul Suncheon Yeosu
9
Seoul Jeonju Suncheon Yeosu Suncheon Boseong Jinju Busan Seoul
23
KTX Seoul Busan 20000
KTX Seoul Gwangju 12000
KTX Gwangju Yeosu 8000
KTX Seoul Jinju 17000
ITX-Saemaeul Seoul Cheonan 7000
ITX-Cheongchun Seoul Chuncheon 3000
V-Train Chuncheon Daegu 10000
Subway Seoul Cheonan 2000
ITX-Saemaeul Cheonan Daejeon 4000
ITX-Saemaeul Daejeon Daegu 10000
ITX-Saemaeul Daegu Busan 7000
Mugunghwa Daejeon Daegu 6000
Mugunghwa Daejeon Gwangju 5000
Mugunghwa Gwangju Jeonju 1500
Mugunghwa Jeonju Suncheon 4000
Mugunghwa Suncheon Yeosu 1500
S-Train Busan Changwon 3000
S-Train Changwon Masan 1000
S-Train Masan Jinju 2000
S-Train Jinju Suncheon 2000
S-Train Suncheon Boseong 1000
Bus Busan Jinju 1500
Bus Suncheon Jinju 4000
-------
Yes
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

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

const ll N = 200;
const ll INF = 0x7f7f7f7f;
ll n, r, m, k;
ll dist1[N][N], dist2[N][N];
map<string,ll> ct;
vector<string> track;

int main(void) {
  cin >> n >> r;
  for (int i=1; i<=n; i++) {
    string city;
    cin >> city;
    ct[city] = i;
  }
  cin >> m;
  while (m--) {
    string city;
    cin >> city;
    track.push_back(city);
  }
  fill(&dist1[0][0], &dist1[N-1][N], INF);
  fill(&dist2[0][0], &dist2[N-1][N], INF);
  for (int i=1; i<=n; i++) {
    dist1[i][i] = 0;
    dist2[i][i] = 0;
  }
  cin >> k;
  while (k--) {
    string tp, st, ed;
    ll price;
    cin >> tp >> st >> ed >> price;
    int s = ct[st];
    int e = ct[ed];
    price = price * 2;
    dist1[e][s] = dist1[s][e] = min(dist1[s][e], price);
    if (tp == "Mugunghwa" || tp == "ITX-Saemaeul" || tp == "ITX-Cheongchun") price = 0;
    else if (tp == "S-Train" || tp == "V-Train") price = price / 2;
    dist2[e][s] = dist2[s][e] = min(dist2[s][e], price);
  }
  for (int k=1; k<=n; k++) {
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=n; j++) {
        dist1[i][j] = min(dist1[i][j], dist1[i][k]+dist1[k][j]);
        dist2[i][j] = min(dist2[i][j], dist2[i][k]+dist2[k][j]);
      }
    }
  }
  ll ans1 = 0, ans2 = 0;
  for (int i=1; i<(int)track.size(); i++) {
    int s = ct[track[i-1]];
    int e = ct[track[i]];
    ans1 += dist1[s][e];
    ans2 += dist2[s][e];
  }

  ans2 += 2*r;
  if (ans2 < ans1) cout << "Yes";
  else cout << "No";

  return 0;
}
