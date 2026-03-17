#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch)
    {
        if (links[ch - 'a'] == NULL)
        {
            return false;
        }
        return true;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntEndWith--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (!temp->containsKey(word[i]))
            {
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increaseEnd();
    }
    int countWordsEqualTo(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->cntPrefix;
    }

    void erase(string word)
    {
        Node *node = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
            {
                return;
            }
        }
        node->deleteEnd();
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    cout << "Inserting strings 'apple', 'app' into Trie" << endl;
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'app': ";
    cout << trie.countWordsStartingWith("app") << endl;
    cout << "Erasing word 'app' from trie" << endl;
    trie.erase("app");
    cout << "Count Words Equal to 'apple': ";
    cout << trie.countWordsEqualTo("apple") << endl;
    cout << "Count Words Starting With 'apple': ";
    cout << trie.countWordsStartingWith("app") << endl;
    return 0;
}