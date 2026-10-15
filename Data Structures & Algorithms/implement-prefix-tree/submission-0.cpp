class TrieNode{
    public:
        TrieNode* children[26];
        bool endOfWord;
    
    TrieNode(){
        endOfWord = false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(node->children[index]==NULL){
                node->children[index]=new TrieNode();
            }
            node = node->children[index];
        }
        node->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(node->children[index]==NULL){
                return false;
            }
            node = node->children[index];
        }
        if(node->endOfWord == false){
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i]-'a';
            if(node->children[index]==NULL){
                return false;
            }
            node =node->children[index];
        }
        return true;
    }
};
