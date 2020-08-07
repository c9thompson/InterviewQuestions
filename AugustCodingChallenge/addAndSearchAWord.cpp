/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

class trie
{
public:
    vector<char> letters;
    vector<pair<trie *, bool>> nextLetter;

    trie() : nextLetter(26, pair<trie *, bool>(NULL, false)) {}
};

class WordDictionary
{
public:
    trie *top;

    /** Initialize your data structure here. */
    WordDictionary() : top(new trie) {}

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        trie *level = top;

        for (int i = 0; i < word.size(); ++i)
        {
            if (!level->nextLetter[word[i] - 97].first)
            {
                level->nextLetter[word[i] - 97].first = new trie;
                level->letters.push_back(word[i]);
            }

            if (i == (word.size() - 1))
            {
                level->nextLetter[word[i] - 97].second = true;
                break;
            }

            level = level->nextLetter[word[i] - 97].first;
        }
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool searchRec(trie *letter, string &word, int i)
    {
        if (word[i] == '.')
        {
            bool found = false;
            for (int j = 0; j < letter->letters.size() && !found; ++j)
            {
                found = (i == word.size() - 1) ? letter->nextLetter[letter->letters[j] - 97].second : searchRec(letter->nextLetter[letter->letters[j] - 97].first, word, i + 1);
            }

            return found;
        }
        else if (letter->nextLetter[word[i] - 97].first)
        {
            return (i == word.size() - 1) ? letter->nextLetter[word[i] - 97].second : searchRec(letter->nextLetter[word[i] - 97].first, word, i + 1);
        }
        else
        {
            return false;
        }
    }

    bool search(string word)
    {
        return searchRec(top, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */