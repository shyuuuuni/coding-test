/*
Time : 2022.01.20 (30 min)
Problem : BOJ1074 (https://www.acmicpc.net/problem/1074)
Algorithm Type : Recursion
Outline :
2^N x 2^N 크기의 2차원 배열을 Z모양으로 탐색한다.
좌표가 주어졌을 때, 해당 위치를 몇번째로 탐색하는지 출력한다.
Method :
재귀 함수를 구현하여 해결하였다.
travle(n,r,c)는 2^n x 2^n 크기에서 (r,c) 위치의 방문 횟수를 리턴한다.
타일을 4등분내면 왼쪽위(1)->오른쪽위(2)->왼쪽아래(3)->오른쪽아래(4) 순서로 방문한다.
(r,c)의 위치를 판단하여 1~4의 위치를 생각하고,
1번일 경우 n을 1 줄인 travel(n-1,r,c)를 리턴한다.
2번일 경우 1번을 들렸다 왔으므로 (1번의 타일 개수) + travle(n-1,r,c-half)를 리턴한다.
3번일 경우 1,2번을 들렸다 왔으므로 (1,2번의 타일 개수) + ...
이런식으로 재귀적으로 해결한다.
base condition은 n=0일 경우로, 이때는 0을 리턴한다.
*/
#include <bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
using namespace std;
using ll = long long;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
void solve();

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve();
  return 0;
}

void chatbot(int n, int lim) {
  if(lim < n) return;
  const string chat[5] = {"\"재귀함수가 뭔가요?\"\n", "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", "라고 답변하였지.\n"};
  if(n<lim) {
    for(int i=0; i<4; i++) {
      for(int j=0; j<n; j++) {
        cout << "____";
      }
      cout << chat[i];
    }
  } else {
    for(int j=0; j<n; j++) {
      cout << "____";
    }
    cout << "\"재귀함수가 뭔가요?\"\n";

    for(int j=0; j<n; j++) {
      cout << "____";
    }
    cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
  }
  
  chatbot(n+1,lim);
  for(int j=0; j<n; j++) {
    cout << "____";
  }
  cout << chat[4];
  return;
}

void solve() {
  int n;
  cin >> n;
  cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
  chatbot(0, n);
  return;
}