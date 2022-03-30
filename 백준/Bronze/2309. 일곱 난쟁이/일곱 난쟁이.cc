/*
Time : 2022.01.06 (3 min)
Problem : BOJ2309 (https://www.acmicpc.net/problem/2309)
Algorithm Type : Math
Outline :
9명의 난쟁이의 키가 주어진다.
7명의 난쟁이의 키의 합이 100인것을 이용하여 난쟁이를 찾고, 그 키를 오름차순으로 출력한다.
Method :
(모든 난쟁이들의 키의 합) - (가짜 난쟁이들의 키의 합) = 100 이므로
(가짜 난쟁이들의 키의 합) = (모든 난쟁이들의 키의 합) - 100 이다.
즉, 9명의 난쟁이 중 2개를 선택해서 위의 값이 나오면, 그 값들만 제외하고 출력하면 된다.
*/
#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int arr[9], sum=0, flag=1;
  for(int i=0; i<9; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sum -= 100;
  for(int i=0; i<9 && flag; i++) {
    for(int j=i+1; j<9 && flag; j++) {
      if(arr[i]+arr[j] == sum) {
        arr[i] = arr[j] = 0;
        flag = 0;
      }
    }
  }
  sort(arr, arr+9);
  for(int i=2; i<9; i++) cout << arr[i] << "\n";
  return 0;
}