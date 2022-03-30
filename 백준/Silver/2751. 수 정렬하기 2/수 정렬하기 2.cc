/*
Time : 2022.02.07 (10 mins)
Problem : BOJ2751 (https://www.acmicpc.net/problem/2751)
Algorithm Type : Sort (Merge)
Outline :
N개의 수가 주어졌을 때 오름차순으로 정렬한다.
Method :
MergeSort를 구현하여 정렬을 실행하였다.
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

void merge(int st, int en) {
  // arr[st:en]을 정렬하면서 병합한다.
  int mid = (st+en)/2;
  int i = st, j = mid;
  for(int idx = st; idx < en; idx++) {
    if (i == mid) tmp[idx] = arr[j++];
    else if (j == en) tmp[idx] = arr[i++];
    else if (arr[i] <= arr[j]) tmp[idx] = arr[i++];
    else tmp[idx] = arr[j++];
  }
  for(int idx = st; idx < en; idx++)
    arr[idx] = tmp[idx];
  return;
} 

void merge_sort(int st, int en) {
  // arr[st:en]을 정렬한다.
  if(st+1 == en) return;
  int mid = (st+en) / 2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st,en);
  return;
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];
  merge_sort(0,n);
  for(int i=0; i<n; i++) cout << arr[i] << "\n";
  return 0;
}