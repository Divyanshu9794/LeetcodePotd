class Trie {
public:
    set<string> s;
    Trie() {
        
    }
    
    void insert(string word) {
        s.insert(word);
    }
    
    bool search(string word) {
        return s.find(word)!=s.end();
    }
    
    bool startsWith(string prefix) {
        auto it=s.lower_bound(prefix);
        if(it==s.end()){
            return false;
        }
        for(int i=0;i<prefix.size();i++){
            if(prefix[i]!= (*it)[i]){
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */