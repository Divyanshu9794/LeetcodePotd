class Solution {
public:
    struct Node {
        Node * links[10];               // 0-9
        bool flag = false;
        bool isContains(char ch){       // Node has ch or not
            return links[ch-'0'] != NULL;
        }
        void put (char ch, Node * node){
            links[ch-'0'] = node;
        }
        Node* get(char ch){
            return links[ch-'0'];
        }
    };
    class Trie {
    public:
         Node * root;
        Trie() {
            root = new Node();
        }
        void insert(string word) {
            Node * node = root;
            int n = word.size();
            for(int i = 0;i<n;i++){
                if(!(node ->isContains(word[i]))){    // if node doesn't contain word[i]
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);       // move forward
            }
            node->flag = true;                   // word is end here mark flag as true 
        }
        
    };
    void traverseTrie(Node * root, int curr, vector<int> &ans){       // normal dfs
        if(root == NULL) return;
        if(root->flag) {
            ans.push_back(curr);
        }
        for(char ch = '0';ch <='9';ch++){
            if(root->isContains(ch)){
                traverseTrie(root->get(ch), (curr*10 )+ (ch - '0'), ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        Trie trie;
        for(int i = 1;i<=n;i++){
            string s = to_string(i);        // it will be easy to traverse a string as compared to integer
            trie.insert(s);
        }
        vector<int> ans;                     
        traverseTrie(trie.root,0,ans);
        return ans;
    }
};