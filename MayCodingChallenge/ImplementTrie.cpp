class node {
public:
    bool endOfWord;
    unordered_map<char, node*> next;
    
    node(bool endOfWord_) : endOfWord(endOfWord_) {}
    ~node(){
        unordered_map<char, node*>::iterator it = next.begin();
        for(; it != next.end(); ++it){
            delete it->second;
        }
    }
};

class Trie {
private:
    node* root; 
    
/*
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
*/

public:
    /** Initialize your data structure here. */
 
    Trie() : root(new node(false)) {}
    ~Trie() {delete root;}
    
    node* traverse(string& word, int i, node* n, bool build){
        if(i == word.size()) {
            if(build) n->endOfWord = true;
            return n;
        }
            
        unordered_map<char, node*>::iterator it = (n->next).find(word[i]);
        if(it == (n->next).end()){
            if(build){
                node* nextNode = new node(i == word.size() - 1);
                (n->next)[word[i]] = nextNode;
                return traverse(word, ++i, nextNode, build);
            }else return NULL;
        }else 
            return traverse(word, ++i, it->second, build);
    }
    
    void insert(string word) {
        traverse(word, 0, root, true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* end = traverse(word, 0, root, false);
        
        if(!end) return false;
        return end->endOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return traverse(prefix, 0, root, false);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */