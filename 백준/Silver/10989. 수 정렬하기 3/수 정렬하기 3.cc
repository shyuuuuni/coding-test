/*
Time : 2022.02.07 (10 mins)
Problem : BOJ2751 (https://www.acmicpc.net/problem/2751)
Algorithm Type : Sort
Outline :
N개의 수가 주어졌을 때 오름차순으로 정렬한다.
Method :
전체 원소의 길이가 10000000 (10^7) 까지 늘어남에 주의한다.
메모리제한이 8MB인데, 8MB = 약 8 x 10^6 바이트를 사용할 수 있다.
int형으로 선언할 경우 int형은 4바이트이고, int형으로 배열을 선연할 경우 4바이트 x 10^7 메모리를 사용한다.
값들이 10000이하의 자연수이므로 unsigned short형으로 선언할 경우에도 결국 2바이트 x 10^7 메모리를 사용한다.
따라서 값들의 개수를 저장하는 배열을 선언한 뒤, 그 개수만큼 앞에서부터 출력해야 한다.
Example :
10
5
2
3
1
4
2
3
5
1
7
-------
1
1
2
2
3
3
4
5
5
7
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, tmp;
  int cnt[10000+1] = {0};
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> tmp;
    cnt[tmp]++;
  }
  for(int i=1; i<=10000; i++) {
    while(cnt[i]--) cout << i << "\n";
  }
  return 0;
}