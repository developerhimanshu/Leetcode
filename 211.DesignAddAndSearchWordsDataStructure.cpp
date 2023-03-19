class TrieNode{
    public:
    
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(){
        for(int i = 0;i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class WordDictionary {

    TrieNode *root;
public:
    WordDictionary() {
        root =  new TrieNode();
    }
    
    // void addUtil(TrieNode *root, string word){
    //     if(word.size()==0){
    //         root->isTerminal = true;return;
    //     }
    //     int ind = word[0]-'a';
    //     TrieNode *child;
    //     if(root->children[ind]!=NULL){
    //         child = root->children[ind];
    //     }else{
    //         child = new TrieNode(word[0]);
    //         root->children[ind] = child;
    //     }
    //     addUtil(root, word.substr(1));
    // }
    void addWord(string word) {
        TrieNode *node = root;
        for(int i = 0; i<word.length(); i++){
            int ind = word[i]-'a';
            if(node->children[ind] == NULL){
                node->children[ind] = new TrieNode();
            }
            node = node->children[ind];
        }
        node->isTerminal = true;
    }
    bool searchUtil(string word, TrieNode *node){
        for(int i = 0; i<word.length(); i++){
            char ch = word[i];
            if(ch == '.'){
                for(auto c:node->children){
                    if(c && searchUtil(word.substr(i+1) ,c))return true;
                }
                return false;
            }
            int ind = ch - 'a';
            if(node ->children[ind] == NULL)return false;
            node = node->children[ind];
        }
        return node->isTerminal;
    }
    bool search(string word) {
        return searchUtil(word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */