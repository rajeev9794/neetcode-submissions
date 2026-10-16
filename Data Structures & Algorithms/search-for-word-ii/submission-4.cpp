class TrieNode{
    public:
        TrieNode* children[26];
        bool endOfWord;
        int index;

        TrieNode(){
            endOfWord=false;
            index=-1;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};
class Trie{
    TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string word, int index){
            TrieNode* node=root;
            for(int i=0;i<word.size();i++){
                int index=word[i]-'a';
                if(node->children[index]==NULL){
                    node->children[index]=new TrieNode();
                }
                node =node->children[index];
            }
            node->endOfWord = true;
            node->index = index;
        }

        vector<string> searchAllWords(vector<string> &words, vector<vector<char>> &boards){
            TrieNode* node = root;
            int n=boards.size();
            int m=boards[0].size();
            vector<int>ans;
            vector<bool>visitedWords(words.size(),false);

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    vector<vector<bool>>visitedIndex(n, vector<bool>(m, false));
                    int index = boards[i][j]-'a';
                    if(node->children[index]!=NULL){
                        dfs(node,boards,i,j,visitedIndex, ans, visitedWords);
                    }
                    
                }
            }

            vector<string>finalAns;
            for(int i=0;i<ans.size();i++){
                finalAns.push_back(words[ans[i]]);
            }
            return finalAns;
        }

        void dfs(TrieNode* node, vector<vector<char>> &board, int i, int j, vector<vector<bool>> &visited, vector<int> &ans, vector<bool> &visitedWords){
        // Check the boundry Condition
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j] || node->children[board[i][j]-'a'] == NULL){
            return;
        }
        int childIndex = board[i][j]-'a';

        // Check the edge case
        if(node->children[childIndex] == NULL){
            return;
        }
        
        // Consume the current word
        node = node->children[childIndex];
        visited[i][j]=true;

        // Check for end of word condition
        if(node->endOfWord && visitedWords[node->index]==false){
            int index = node->index;
            visitedWords[index]=true;
            ans.push_back(index);
        }
        
        // Explore all possible paths.
        dfs(node, board, i+1, j, visited, ans, visitedWords);
        dfs(node, board, i-1, j, visited, ans, visitedWords);   
        dfs(node, board, i, j-1, visited, ans, visitedWords);
        dfs(node, board, i, j+1, visited, ans, visitedWords);

        //Backtrack step 
        visited[i][j]=false;
    }
};
class Solution {
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size();
        int m=board[0].size();
        vector<string>ans;
        Trie* trie = new Trie();
        for(int i=0;i<words.size();i++){
            trie->insert(words[i],i);
        }

        
        return trie->searchAllWords(words, board);
    }
};
