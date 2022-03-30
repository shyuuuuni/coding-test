/*
Time : 2022.01.07 (15 min)
Problem : BOJ1158 (https://www.acmicpc.net/problem/1158)
Algorithm Type : Linked List, Queue
Outline :
1번부터 N번까지의 사람이 원형으로 앉아있다.
순서대로 K번째 사람을 제거한다. 이때 제거된 순서를 요세푸스 순열이라고 한다.
요세푸스 순열을 출력한다.
Method :
Queue를 이용하여 K번째를 구하기 위해서 push와 pop을 반복해도 되지만,
list 자료구조를 연습하기 위해서 list를 사용하였다.
stl의 list에서는 마지막 원소가 첫번째 원소로 이어지지 않았으므로 그 부분만 추가했다.
*/
#include <bits/stdc++.h>
using namespace std;
void solve1();
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  solve1();
  return 0;
}

void solve1() {
  int n, k, tmp;
  list<int> list;
  cin >> n >> k;
  for(int i=1; i<=n; i++) list.push_back(i);
  auto iter = list.begin();
  cout << "<";
  while(!list.empty()) {
    tmp = k;
    while(tmp--) {
      if(iter == list.end()) iter = list.begin();
      iter++;
    }
    if(iter == list.begin()) iter = list.end();
    iter--;
    cout << *iter;
    iter = list.erase(iter);
    if(!list.empty()) cout << ", ";
  }
  cout << ">";
  return;
}