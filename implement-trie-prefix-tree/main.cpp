#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for trie tree node.
 */
class trie_node
{
private:
    char val;
    list<unique_ptr<trie_node>> children;
    bool word_end;

public:
    trie_node(char c) : val(c), children(), word_end(false) {}
    trie_node* add_child(char c)
    {
        unique_ptr<trie_node> child = make_unique<trie_node>(c);
        trie_node* child_ptr = child.get();
        children.push_back(move(child));
        return child_ptr;
    }
    trie_node* find(char c)
    {
        for (const auto& child: children)
            if (child.get()->val == c)
                return child.get();
        return nullptr;
    }
    bool is_last() { return word_end; }
    bool set_last(bool last = true) { return word_end = last; }
};

class Trie
{
private:
    vector<unique_ptr<trie_node>> tree;
    vector<bool> tree_beginnings;

public:
    Trie() : tree(), tree_beginnings(26, false)
    {
        tree.reserve(26);
        for (char c = 'a'; c <= 'z'; ++c)
            tree.push_back(make_unique<trie_node>(c));
    }
    
    void insert(string word)
    {
        if (word.empty())
            return;
        trie_node* node = tree[word[0] - 'a'].get();
        tree_beginnings[word[0] - 'a'] = true;
        for (int i = 1; i < (int)word.length(); ++i)
        {
            trie_node* child = node->find(word[i]);
            if (child == nullptr)    
                child = node->add_child(word[i]);
            node = child;
        }
        node->set_last();
    }
    
    bool search(string word)
    {
        if (word.empty())
            return false;
        trie_node* node = tree[word[0] - 'a'].get();
        if ((int)word.length() == 1)
            return node->is_last() && tree_beginnings[word[0] - 'a'];
        for (int i = 1; i < (int)word.length(); ++i)
        {
            trie_node* child = node->find(word[i]);
            if (child == nullptr)    
                return false;
            node = child;
        }
        return node->is_last();
    }
    
    bool startsWith(string prefix)
    {
        if (prefix.empty())
            return true;
        trie_node* node = tree[prefix[0] - 'a'].get();
        if ((int)prefix.length() == 1)
            return tree_beginnings[prefix[0] - 'a'];
        for (int i = 1; i < (int)prefix.length(); ++i)
        {
            trie_node* child = node->find(prefix[i]);
            if (child == nullptr)    
                return false;
            node = child;
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
    
int main()
{
    unique_ptr<Trie> trie(make_unique<Trie>());
    trie->insert("apple");
    cout << "search for apple: " << trie->search("apple") << '\n';    // return true
    cout << "search for app: " << trie->search("app") << '\n';        // return false
    cout << "starting with app: " << trie->startsWith("app") << '\n'; // return true
    trie->insert("app");
    cout << "search for app: " << trie->search("app") << '\n';        // return true
    return 0;
}
