// https://leetcode.com/problems/design-add-and-search-words-data-structure

#include <bits/stdc++.h>
using namespace std;
struct Node{
   bool isEnd;
   map <char, Node*> child;
   Node(){
      isEnd = false;
   }
};
class WordDictionary {
   public:
   Node* head;
   WordDictionary() {
      head = new Node();
   }
   void insertNode(Node* head, string s){
      Node* curr = head;
      int n = s.size();
      for(int i = 0; i < n; i++){
         char x = s[i];
         if(!curr->child[x]){
            curr->child[x] = new Node();
         }
         curr = curr->child[x];
      }
      curr->isEnd = true;
   }
   void addWord(string word) {
      insertNode(head, word);
   }
   bool check(Node* curr, string s, int idx = 0){
      if(idx == s.size()) return curr->isEnd;
         bool ok = false;
      if(s[idx] == '.'){
         for(int i = 0; i < 26; i++){
            char x = 'a' + i;
            if(curr->child[x] && check(curr->child[x], s, idx + 1))return true;
         }
      } else {
         char x = s[idx];
         if(curr->child[x] && check(curr->child[x], s, idx + 1))return true;
      }
      return false;
   }
   bool search(string word) {
      Node* curr = head;
      return check(curr, word);
   }
};