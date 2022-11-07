#include <iostream>
using namespace std;

struct TrieNode
{
    char data;
    TrieNode *next[26];
    bool isTerminal;
    int countword;
    int countprefix;

    TrieNode(char value)
    {
        data = value;
        for (int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
        isTerminal = false;
        countword = 0;
        countprefix = 0;
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
            root->countword++;
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            root->next[index]->countprefix++;
            child = root->next[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->next[index] = child;
            child->countprefix++;
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
            root->countword--;
            if(root -> isTerminal == true)
            {
            root->isTerminal = false; 
            cout<<"The word "<<word<<" is removed from the Trie";
            }
            else
            {
                cout<<"This word is already not present";
            }
            
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            root->next[index] -> countprefix--;
            child = root->next[index];
        }

        else
        {
            cout << "This word is already not present." << endl;
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

    int countwordUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            if (root->isTerminal)
                return root->countword;
            else
            {
                return 0;
            }
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            child = root->next[index];
        }

        else
        {
            return 0;
        }

        return countwordUtil(child, word.substr(1));
    }

    int countprefixUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->countprefix;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->next[index] != NULL)
        {
            child = root->next[index];
        }

        else
        {
            return 0;
        }

        return countprefixUtil(child, word.substr(1));
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

    int countwordsEqualto(string word)
    {
        return countwordUtil(root, word);
    }

    int countwordsStartingWith(string word)
    {
        return countprefixUtil(root, word);
    }
};

int main()
{

    Trie t1;
    int option;
    do
    {
        cout << "\nChoose from the options below"
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
                cout << "Word " << str1 << " is present " << t1.countwordsEqualto(str1) << " times" << endl;
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
                cout << "There are " << t1.countwordsStartingWith(str3) << " no of words present in the trie with the prefix " << str3 << endl;
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