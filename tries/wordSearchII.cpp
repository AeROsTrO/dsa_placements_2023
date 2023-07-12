#include <bits/stdc++.h>
using namespace std;
//problem description here
//Given an m x n board of characters and a list of strings words, return all words on the board.
// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

//brute force is to generate all words and store them in a temporary array and check each word in the string array to check if it exists or not
//tc=O(w*m*n*4^(m*n))

//optimal is to make a trie and then traverse the trie and check if it exists in the array

class Node{
    bool endOfWord=false;
    Node* links[26];
    
    public:
    string word="";
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
    void removeEnd(){
        endOfWord=false;
    }
    bool isEnd(){
        return endOfWord;
    }
};

Node* root=new Node();
void insertWord(string &word){
        Node* node=root;
        for(char c:word){
            if(!node->containsKey(c)){
                node->addChar(c, new Node());
            }
            node=node->getKey(c);
        }
        node->putEnd();
        node->word=word;
}
vector<string>ans;
bool isValid(int i, int j, int rows, int cols){
    return (i>=0 && j>=0 && i<rows && j<cols);
}
void dfs(vector<vector<char>>&board, int i, int j, Node* ptr){
    int rows=board.size(), cols=board[0].size();
    if(!ptr)return;
    if(ptr->isEnd()){
        ptr->removeEnd();//so we can continue searching for words that have this as prefix ex: fire, fired
        ans.push_back(ptr->word);
    }
    int dirs[][2]={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};//down, up, left, right
    for(auto dir:dirs){
        int newx=i+dir[0], newy=j+dir[1];
        if(isValid(newx, newy, rows, cols) && board[newx][newy]!='#' && ptr->getKey(board[newx][newy])){
            char x=board[newx][newy];
            board[newx][newy]='#';
            dfs(board, newx, newy, ptr->getKey(x));
            board[newx][newy]=x;
        }
    }
}
void findWords(vector<string>&words, vector<vector<char>>&board){
    int rows=board.size(), cols=board[0].size();
    for(string s:words)insertWord(s);
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(root->containsKey(board[i][j])){
                Node* temp=root;
                char x=board[i][j];
                board[i][j]='#';
                dfs(board, i, j, temp->getKey(x));
                board[i][j]=x;
            }
        }
    }
    for(string i:ans)cout<<i<<" ";
}


int main()
{
    int m, n;cin>>m>>n;
    vector<vector<char>>v(m, vector<char>(n));
    for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)cin>>v[i][j];
    string curr="";
    int x;cin>>x;
    vector<string>words(x);
    for(int i=0; i<x; i++)cin>>words[i];
   findWords(words, v);
    return 0;
}