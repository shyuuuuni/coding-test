/*
Time : 2022.01.06 (1 min)
Problem : BOJ2752 (https://www.acmicpc.net/problem/2752)
Algorithm Type : Sort
Outline :
1과 100,000 사이의 수 3개를 오름차순으로 정렬하여 출력한다.
Method :
STL sort함수를 이용하여 정렬하여 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int arr[3];
  for(int i = 0; i < 3; i++) cin >> arr[i];
  sort(arr, arr+3);
  for(int i = 0; i < 3; i++) cout << arr[i] << " ";
  return 0;
}