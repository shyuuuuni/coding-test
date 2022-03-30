/*
Time : 2022.01.06 (3 min)
Problem : BOJ2587 (https://www.acmicpc.net/problem/2587)
Algorithm Type : Math
Outline :
5개의 자연수의 평균과 중앙값을 출력한다.
Method :
반복문을 이용하여 입력받으면서 총 합을 구하고, 이후 평균을 구한다.
배열을 정렬해서 index 2 위치의 중앙값을 출력한다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int arr[5];
  int sum = 0;
  
  for(int i=0; i<5; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr+5);
  cout << sum/5 << "\n" << arr[2];
  return 0;
}