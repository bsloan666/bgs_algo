#include <map>
#include <iostream>
#include <string>

using namespace std;

class Trie {
    class TrieNode {
        public:
        TrieNode():value(false){}
        map<char, TrieNode*> children;
        bool value;
    };

    public:
    Trie():m_root(new TrieNode()){}
    void _collect(TrieNode *x, vector<char> &prefix, vector<string> &results) {
        if (!x){
            return;
        }
        if( x->value ) {
            string prefix_str = "";
            for(int i = 0; i < prefix.size(); i++){
                prefix_str += prefix[i];
            }
            results.push_back(prefix_str);
        }
        map<char, TrieNode*>::iterator iter = x->children.begin();
        while(iter != x->children.end()) { 
            prefix.push_back(iter->first);
            _collect(x->children[iter->first], prefix, results);
            prefix.pop_back();
            iter++;
        }
    }

    void keys_with_prefix(vector<char> &prefix, vector<string> &results) {
        string prefix_str = "";
        for(int i = 0; i < prefix.size(); i++){
            prefix_str += prefix[i];
        }
        TrieNode *x = find(prefix_str);
        _collect(x, prefix, results);
    }

    TrieNode * find(string &key) {
        TrieNode *node = m_root;
        for(size_t i = 0; i < key.size(); i++) {
            char ch = key[i];
            if(node->children.find(ch) != node->children.end()) {
                node = node->children[ch];
            } else {
               return NULL; 
            }
        }
        return node;
    }

    void insert(string &key, bool value){
        TrieNode *node = m_root;
        for(size_t i = 0; i < key.size(); i++) {
            char ch = key[i];
            if(node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->value = value;
    }

    private:
    TrieNode *m_root;
};
