#include <bits/stdc++.h>
using namespace std;

class Trie {
    private:
        int toInteger(char c) {
            return c - 'a';
        }
    
    public:
        long long count; 
        Trie* children[26];
    
        Trie() {
            this->count = 0;
            for (int i=0; i<26; i++) {
                this->children[i] = NULL;
            }
        }
    
        void insert(string str) {
            Trie* cursor = this;
            for (char c : str) {
                cursor->count++;
                if (!cursor->children[toInteger(c)]) {
                    cursor->children[toInteger(c)] = new Trie();
                }
                cursor = cursor->children[toInteger(c)];
            }
            cursor->count++;
            return;
        }
    
        int find(string str) {
            int result = 0;
            Trie* cursor = this;
            for (char c : str) {
                if (c == '?') break;
                if (!cursor->children[toInteger(c)]) {
                    return 0;
                }
                cursor = cursor->children[toInteger(c)];
            }
            result = cursor->count;
            return result;
        }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie trie_le[10000+10];
    Trie trie_ri[10000+10];
    
    for (string word : words) {
        string rev_word = word;
        reverse(rev_word.begin(), rev_word.end());
        int len = (int)word.size();
        trie_le[len].insert(word);
        trie_ri[len].insert(rev_word);
    }
    
    for (string query : queries) {
        int len = (int)query.size();
        if (query.back() == '?' || query.front() != '?') {
            answer.push_back(trie_le[len].find(query));
        } else {
            reverse(query.begin(), query.end());
            answer.push_back(trie_ri[len].find(query));
        }
    }
    
    return answer;
}