#include <bits/stdc++.h>
using namespace std;
//problem description here
// Design a data structure that supports adding new words and finding if a string matches any previously added string.
// Implement the WordDictionary class:
// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.


class Node{
    bool endOfWord=false;
    Node* links[26];
    public:
    bool containsKey(char ch){
        return links[ch-'a'];
        //returns null if not present in the word
    }
    void addChar(char ch, Node* tr){
        links[ch-'a']=tr;
    }
    Node* getKey(char ch){
        return links[ch-'a'];
    }
    void putEnd(){
        endOfWord=true;
    }
    bool isEnd(){
        return endOfWord;
    }

};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c)){
                node->addChar(c, new Node());
            }
            node=node->getKey(c);
        }
        node->putEnd();
    }
    bool pathSearch(string word, Node* search, int ind){
        Node* node=search;
        char c=word[ind];
        if(ind==word.size())return node && node->isEnd();
        if(c=='.'){
            for(char ch='a'; ch<'z'+1; ch++){
                if(node->containsKey(ch)){
                    if(pathSearch(word, node->getKey(ch), ind+1))return true;
                }
            }
            return false;
        }else{
            if(!node->containsKey(c))return false;
            return pathSearch(word, node->getKey(c), ind+1);
        }
    }
    bool search(string word) {
       return pathSearch(word, root, 0);
    }
};

