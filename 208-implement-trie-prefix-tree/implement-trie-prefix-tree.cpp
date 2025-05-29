class Trie {
private:
    Trie* child[26];
    bool isleaf;
public:
    Trie() {
        isleaf=0;
        memset(child, 0, sizeof(child));
    }
    
    void insert(string word,int idx=0) {
        if (idx == word.size()) 
        isleaf = 1;
        else {
        int cur = word[idx] - 'a';
        if (child[cur] == 0)
        child[cur] = new Trie();
        child[cur]->insert(word,idx+1); } 
    }
    
    bool search(string word,int idx=0) {
         if(idx==word.size())return isleaf;
         int cur=word[idx]-'a';
         if(child[cur]==0)return false;
         return child[cur]->search(word,idx+1);
    }
    
    bool startsWith(string prefix,int idx=0) {
        if(idx==prefix.size())return true;
         int cur=prefix[idx]-'a';
         if(child[cur]==0)return false;
         return child[cur]->startsWith(prefix,idx+1);
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */