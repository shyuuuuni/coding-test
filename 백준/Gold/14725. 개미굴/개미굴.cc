/*
Time : 2022.04.13
Problem : BOJ14725 (https://www.acmicpc.net/problem/14725)
Algorithm Type : Trie
Outline :

Method :

Example :
4
2 KIWI BANANA
2 KIWI APPLE
2 APPLE APPLE
3 APPLE BANANA KIWI
-------
APPLE
--APPLE
--BANANA
----KIWI
KIWI
--APPLE
--BANANA
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pii pair<int,int>
#define mp(X,Y) make_pair((X),(Y))
typedef long long ll;

class Trie {
  private:
    void printtab(int tab) {
      while(tab--) {
        cout << "--";
      }
    }
  
  public:
    string food;
    map<string,Trie*> children;

    Trie() {
      food = "";
    }

    Trie* insert(string s) {
      Trie* cursor = this;

      if (cursor->children.find(s) == cursor->children.end()) {
        cursor->children[s] = new Trie();
        cursor->children[s]->food = s;
      }

      return cursor->children[s];
    }

    void printTrie(int tab) {
      Trie* cursor = this;

      for (auto iter=cursor->children.begin(); iter!=cursor->children.end(); iter++) {
        printtab(tab);
        cout << iter->first << "\n";
        iter->second->printTrie(tab+1);
      }

      return;
    }
};

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0); // FAST IO
  
  int n;
  Trie trie;

  cin >> n;
  while (n--) {
    int k;
    Trie* cursor = &trie;

    cin >> k;
    while(k--) {
      string s;

      cin >> s;
      cursor = cursor->insert(s);
    }
  }

  trie.printTrie(0);

  return 0;
}
