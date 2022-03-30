/*
Time : 2022.01.06 (1 min)
Problem : BOJ2490 (https://www.acmicpc.net/problem/2490)
Algorithm Type : Simulation
Outline :
윷놀이의 윷을 배(0), 등(1) 으로 입력받아서 도(A),개(B),걸(C),윷(D),모(E)를 출력한다.
총 세번의 윷을 던진다.
Method :
입력받은 값을 조건문을 이용하여 비교하여 케이스를 나눠서 처리한다.
세번째 케이스를 처리할때 최대값을 STL max_element 함수를 이용하여 포인터의 값을 얻는 *를 사용하여 처리한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int tc = 0;

  while(tc < 3) {
    int x, cnt = 0;
    for(int i=0; i<4; i++) {
      cin >> x;
      if(x) cnt++;
    }
    if(cnt==0) cout << "D";
    else if(cnt==1) cout << "C";
    else if(cnt==2) cout << "B";
    else if(cnt==3) cout << "A";
    else cout << "E";
    cout << "\n";
    tc++;
  }
  
  return 0;
}