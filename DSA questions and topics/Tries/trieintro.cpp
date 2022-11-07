#include <iostream>
using namespace std;

// class TrieNode{
//     public:
//     char data;
//     TrieNode* children[26];
//     bool isTerminal;

//     TrieNode(char ch){
//         data = ch;
//         for(int i=0; i<26; i++)
//         {
//             children[i] = NULL;
//         }
//         isTerminal = false;
//     }
// };

struct TrieNode
{
    char data;
    TrieNode *next[26];
    bool isTerminal;

    TrieNode(char value)
    {
        data = value;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root = new TrieNode('\0');

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            child = root->next[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->next[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            child = root->next[index];
        }

        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    void removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false; // space optimization needs to be done as we are just marking terminal node as false. We can free the nodes after the second last terminal node.
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            child = root->next[index];
        }

        else
        {
            cout << "The word is already not present." << endl;
            return;
        }

        removeUtil(child, word.substr(1));
    }

    bool prefixUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            child = root->next[index];
        }

        else
        {
            return false;
        }
        return prefixUtil(child, word.substr(1));
    }

    void insertTrie(string word)
    {
        insertUtil(root, word);
    }

    bool searchTrie(string word)
    {
        return searchUtil(root, word);
    }

    bool removefromTrie(string word)
    {
        removeUtil(root, word);
    }

    bool prefixSearch(string pre)
    {
        return prefixUtil(root, pre);
    }
};

int main()
{

    Trie t1;
    int option;
    do
    {
        cout << "Choose from the options below"
                "\nPress 1 if you want to insert a word\n"
                "Press 2 if you want to search for a word\n"
                "Press 3 if you want to delete a word\n"
                "Press 4 if you want to find out if a word is starting with some prefix\n"
                "Press 5 if you're not interested in any of it and are thinking why am I here."
             << endl;
        cin >> option;
        if (option == 1)
        {
            string str;
            cout << "Enter string to insert" << endl;
            cin >> str;
            t1.insertTrie(str);
            continue;
        }
        else if (option == 2)
        {
            string str1;
            cout << "Enter string to search" << endl;
            cin >> str1;
            if (t1.searchTrie(str1))
            {
                cout << "String " << str1 << " is present" << endl;
            }
            else
            {
                cout << "String " << str1 << " is NOT present." << endl;
            }
            continue;
        }
        else if (option == 3)
        {
            string str2;
            cout << "Enter string to delete" << endl;
            cin >> str2;
            t1.removefromTrie(str2);
            cout << "String " << str2 << " is removed from trie." << endl;
            continue;
        }
        else if (option == 4)
        {
            string str3;
            cout << "Enter the prefix string" << endl;
            cin >> str3;
            if (t1.prefixSearch(str3))
            {
                cout << "String " << str3 << " is present in some words as prefix." << endl;
            }
            else
            {
                cout << "String " << str3 << " is NOT present in any words as prefix." << endl;
            }
            continue;
        }
        else
        {
            option = 0;
        }
    } while (option != 0);

    return 0;
}