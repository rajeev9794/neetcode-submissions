class TrieNode{
    public:
        TrieNode* children[26];
        bool endOfWord;

        TrieNode(){
            endOfWord = false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(node->children[index]==NULL){
                node->children[index]= new TrieNode();
            }
            node=node->children[index];
        }
        node->endOfWord=true;
        
    }
    bool recursiveSearch(string word, int index, TrieNode* node){
        
        if(index>=word.size() && node!=NULL && node->endOfWord){
            return true;
        }

        //cout<<index<<endl;
        bool res = false;
        bool conditionShouldSatisfyOnce= false;
        if(index<word.size()){
        if(word[index]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i]!=NULL){
                    conditionShouldSatisfyOnce=true;
                    res = res || recursiveSearch(word, index+1, node->children[i]);
                }
            }
            if(!conditionShouldSatisfyOnce){
                return false;
            }
        }
        else{
            int id = word[index]-'a';
            if(node->children[id]==NULL){
                return false;
            }
            node =node->children[id];
            res=recursiveSearch(word,index+1,node);
        }
        }
        return res;
    }
    bool search(string word) {
        TrieNode* node =root;
        return recursiveSearch(word,0,node);
    }
};
