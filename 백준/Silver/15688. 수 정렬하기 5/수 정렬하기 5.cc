/*
Time : 2022.02.07 (10 mins)
Problem : BOJ11931 (https://www.acmicpc.net/problem/11931)
Algorithm Type : Sort
Outline :
N개의 수가 주어졌을 때 오름차순으로 정렬한다.
Method :
메모리가 넉넉하고, 입력으로 들어오는 수도 크지 않으므로 배열로 입력받고 STL sort를 사용한다.
비내림차순으로 정렬함에 유의한다.
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
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int arr[1000000+1] = {};
  for(int i=0; i<n; i++) cin >> arr[i];
  sort(arr, arr+n, less<int>());
  for(int i=0; i<n; i++) cout << arr[i] << "\n";
  return 0;
}