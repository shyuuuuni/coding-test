/*
Time : 2022.03.29
Problem : BOJ14425 (https://www.acmicpc.net/problem/14425)
Algorithm Type : 문자열, Trie(자료구조)
Outline :
총 N개의 문자열로 이루어진 집합 S가 주어진다.
입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하는 프로그램을 작성하시오.
Method :

Example :

-------

*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

ll dx[6] = {1,-1,0,0,0,0};
ll dy[6] = {0,0,1,-1,0,0};
ll dz[6] = {0,0,0,0,1,-1};

bool compare(const string &a, const string &b) {
  // 왼쪽 변수 a, 오른쪽 변수 b에 대해서
  // a<b 라면 오른쪽이 더 크도록 정렬, a>b 라면 왼쪽이 더 크도록 정렬
  // a가 b보다 앞에 와야 한다면 true, 아니면 false (같을때는 꼭 false 반환하도록 해야 함)
  // 래퍼런스 사용하는게 좋음
  return true;
}

bool outOfBound0(int x, int y, int m, int n) {
  // 0-indexed oob
  return (x<0 || y<0 || m<=x || n<=y);
}

bool outOfBound1(int x, int y, int m, int n) {
  // 1-indexed oob
  return (x<1 || y<1 || m<x || n<y);
}

// ****트라이 구현****
class Trie {
  private:
    int toInteger(char c) {
      return c - 'a';
    }

  public:
    bool isTerminal;
    Trie* children[26];

    Trie() {
      this->isTerminal = false;
      for (int i=0; i<26; i++) {
        this->children[i] = NULL;
      }
    }

    void insert(const string str) {
      Trie* cursor = this;
      for (char element : str) {
        if (!cursor->children[toInteger(element)]) {
          cursor->children[toInteger(element)] = new Trie();
        }
        cursor = cursor->children[toInteger(element)];
      }
      cursor->isTerminal = true;
    }
    
    bool find(const string str) {
      Trie* cursor = this;
      bool result = true;
      for (char element : str) {
        if (!cursor->children[toInteger(element)]) {
          result = false;
          break;
        }
        cursor = cursor->children[toInteger(element)];
      }
      if (!cursor->isTerminal) {
        result = false;
      }
      return result;
    }
};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO

  int n, m;
  int result = 0;
  Trie trie;

  cin >> n >> m;

  for (int i=0; i<n; i++) {
    string str;
    cin >> str;
    trie.insert(str);
  }


  for (int i=0; i<m; i++) {
    string str;
    cin >> str;
    if (trie.find(str)) {
      result++;
    }
  }

  cout << result;

  return 0;
}
