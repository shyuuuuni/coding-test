/*
Time : 2022.01.06 (6 min)
Problem : BOJ2562 (https://www.acmicpc.net/problem/2562)
Algorithm Type : I/O
Outline :
9개의 서로 다른 자연수가 주어졌을때, 최댓값과 그 최댓값이 몇번째인지 출력한다.
Method :
STL의 max_element함수는 최댓값이 존재하는 위치의 포인터를 리턴한다.
따라서 처음 최댓값을 출력할때에는 *를 사용하여 그 포인터의 값을 출력하고,
몇번째인지를 출력할때에는 배열의 첫번째 포인터를 빼서 순서를 리턴한다.
이때 인덱스는 0부터지만 순서는 첫번째부터 세므로 1을 더해주었다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int arr[9];
  for(int i=0; i<9; i++) cin >> arr[i];
  cout << *max_element(arr, arr+9) <<  "\n" << max_element(arr, arr+9) - arr + 1;
  return 0;
}