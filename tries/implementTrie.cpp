#include <bits/stdc++.h>
using namespace std;
//problem description here
struct Node{
    Node* chain[26];
    bool endOfWord=false;
    bool NodeContainsKey(char ch){
        return chain[ch-'a'];
    }
    void putKey(char ch, Node* tr){
        chain[ch-'a']=tr;
    }
    Node* getKey(char ch){
        return chain[ch-'a'];
    }
    void putEnd(){
        endOfWord=true;
    }
    bool isEnd(){
        return endOfWord;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insertWord(string word){
        Node* node=root;
        for(char c:word){
            if(!node->NodeContainsKey(c)){
                node->putKey(c, new Node());
            }
            node=node->getKey(c);
        }
        node->putEnd();
    }
    bool search(string word){
        Node* node=root;
        for(char c:word){
            if(!node->NodeContainsKey(c))return false;
            node=node->getKey(c);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix){
        Node* node=root;
        for(char c:prefix){
            if(!node->NodeContainsKey(c))return false;
            node=node->getKey(c);
        }
        return true;
    }
};
int main()
{
    
    return 0;
}