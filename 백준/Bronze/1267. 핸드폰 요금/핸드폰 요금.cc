/*
Time : 2022.01.06 (10 min)
Problem : BOJ1267 (https://www.acmicpc.net/problem/1267)
Algorithm Type : Simulation
Outline :
N개의 통화 시간이 주어진다.
통화 시간에 따라 다음과 같이 두 요금제에서 요금을 청구한다.
1. 영식요금제 : 30초마다 10원이 청구된다. (ex 29초->10원, 30초->20원)
2. 민식요금제 : 60초마다 15원이 청구된다. (ex 59초->15원, 60초->30원)
저렴한 요금제와 그 요금을 출력한다.
Method :
금액이 청구된 횟수를 시간을 30과 60으로 나눈 몫으로 표현할 수 있다.
위와 같이 시간을 계산하고, 조건문을 통해서 더 싼 요금제를 출력한다.
Failed :
두 요금제가 같을 경우의 조건을 신경써서 코딩해야 한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m=0, y=0, t[20];
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> t[i];
    y += (t[i]/30+1) * 10;
    m += (t[i]/60+1) * 15;
  }
  if(y == m) cout << "Y M " << y;
  else if (y < m) cout << "Y " << y;
  else cout << "M " << m;
  return 0;
}