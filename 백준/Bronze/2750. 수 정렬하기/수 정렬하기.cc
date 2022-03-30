/*
Time : 2022.02.07 (10 mins)
Problem : BOJ2750 (https://www.acmicpc.net/problem/2750)
Algorithm Type : Sort (Bubble)
Outline :
N개의 수가 주어졌을 때 오름차순으로 정렬한다.
Method :
Bubble Sort를 구현하여 해결하였다.
Example :
5
5
4
3
2
1
-------
1
2
3
4
5
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000000+1];
int tmp[1000000+1];

void bubble_sort(int st, int en) {
  for(int i=0; i<n; i++) {
    for(int j=0; j<n-1; j++) {
      if(arr[j+1] < arr[j]) swap(arr[j], arr[j+1]);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  bubble_sort(0,n);
  for(int i=0; i<n; i++) cout << arr[i] << "\n";
  return 0;
}