/*
Time : 2022.02.03 (30 mins)
Problem : BOJ13335 (https://www.acmicpc.net/problem/13335)
Algorithm Type : Simulation
Outline :
Method :
Example :
4 2 10
7 4 5 6
-------
8
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void solve();
bool oob(int, int);
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

int n, w, l;
int curl, complete, t; // 현재 부하, 완료한 차량 수, 걸린 시간
queue<int> q;

// bool oob(int x, int y) { // out of bound check
//   return (x<0 || y<0 || n<=x || m<=y);
// }

void solve() {
  cin >> n >> w >> l; // 차량수, 다리길이, 최대하중
  for(int i=0; i<w; i++) q.push(0); // 처음 큐(다리)에 빈 칸 w개

  for(int i=0; i<n; i++) {
    int car;
    cin >> car;
    while(l < car + curl - q.front()) {
      // 한칸 옮겨도 다리에 부하가 커서 차량을 올릴 수 없는 경우
      int out = q.front();
      if(out) complete++;
      q.pop();
      q.push(0);
      curl -= out;
      t++;
    }
    int out = q.front();
    if(out) complete++;
    q.pop();
    curl -= out;
    curl += car;
    q.push(car);
    t++;
    // cout << "       >out:" << out << "\n";
    // cout << q.size() << "\n";
  }
  while(complete < n) {
    if(q.front()) complete++;
    q.pop();
    t++;
  }
  cout << t;
  return;
}