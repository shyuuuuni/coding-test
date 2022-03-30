/*
Time : 2022.01.06 (6 min)
Problem : BOJ10804 (https://www.acmicpc.net/problem/10804)
Algorithm Type : Simulation
Outline :
정수가 적혀진 카드 1~20이 각 번호의 위치에 존재한다.
10줄의 명령마다 각 줄에 범위 a, b가 주어진다.
위 범위는 a부터 b 위치의 카드를 뒤집는 명령을 나타낸다.
10개의 명령에 대해서 모두 시행했을때 마지막 카드의 배치를 한줄에 출력한다.
Method :
명령의 수가 10개로 적고, 카드도 20개기 때문에 STL의 reverse함수를 사용하여
모든 명령에 대해서 시뮬레이션한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int card[100], a, b, tc=0;
  for(int i=1; i<21; i++) card[i]=i;
  while(tc < 10) {
    cin >> a >> b;
    reverse(card+a, card+b+1);
    tc++;
  }
  for(int i=1; i<21; i++) cout << card[i] << " ";
  return 0;
}