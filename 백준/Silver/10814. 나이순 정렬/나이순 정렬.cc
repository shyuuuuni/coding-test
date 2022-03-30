/*
Time : 2022.02.07 (10 mins)
Problem : BOJ10814 (https://www.acmicpc.net/problem/10814)
Algorithm Type : Sort
Outline :
N개의 나이/이름 쌍이 주어진다.
나이순->가입순으로 출력한다.
Method :
입력 자체가 가입순으로 주어진다.
따라서 Stable Sort를 진행하면 가입순으로는 따로 정렬할 필요가 없다.
Stable Sort인 Merge sort를 구현하여 해결하였다.
Example :
3
21 Junkyu
21 Dohyun
20 Sunyoung
-------
20 Sunyoung
21 Junkyu
21 Dohyun
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))

int n;
pair<int,string> arr[100000+1], tmp[100000+1];

void merge(int st, int en) {
  // arr[st:en]을 정렬하면서 병합한다.
  int mid = (st+en)/2;
  int i = st, j = mid;
  for(int idx = st; idx < en; idx++) {
    if (i == mid) tmp[idx] = arr[j++];
    else if (j == en) tmp[idx] = arr[i++];
    else if (arr[i].first <= arr[j].first) tmp[idx] = arr[i++];
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
  for(int i=0; i<n; i++) {
    int age;
    string name;
    cin >> age >> name;
    arr[i] = mp(age,name);
  }
  merge_sort(0,n);
  for(int i=0; i<n; i++) cout << arr[i].first << " " << arr[i].second << "\n";
  return 0;
}