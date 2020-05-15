/**
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

**/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie {
    unordered_map<char, vector<string>> umap_tree;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        umap_tree[word[0]].push_back(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (umap_tree.find(word[0]) == umap_tree.end()){
            return false;
        }
        
        vector<string> tree = umap_tree[word[0]];
        for(auto s: tree){
            if(s == word){
                return true;
            }
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (umap_tree.find(prefix[0]) != umap_tree.end()){
            vector<string> tree = umap_tree[prefix[0]];
            for(auto s: tree){
                if(s.rfind(prefix, 0) == 0){
                    return true;
                }
            }
        }
        return false;
    }
};

