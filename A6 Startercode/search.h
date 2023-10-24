// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class Sentence{
    public:
    string sentence;
    int book_code;
    int page;
    int paragraph;
    int sentence_no;

    Sentence();
    Sentence(string sent,int b_code,int pg,int para,int sent_no);
};

/*

 .,-:!"'()?—[]“”‘’˙;@

*/

class TrieNode;

class TrieList{
    public:
    TrieList* prev;
    TrieList* next;
    TrieList* tail;
    TrieNode* data;
    TrieList();
    TrieList(TrieNode* t);
    ~TrieList();
};

class SentList{
public:
    SentList* prev;
    SentList* next;
    SentList* tail;
    Sentence* data;
    SentList();
    SentList(Sentence* t);
    ~SentList();
};

class TrieNode{
    public:
    SentList* sentences;
    TrieNode** children;
    TrieList** Occurances;
    int depth;
    TrieNode();
    ~TrieNode();
    void insert(Sentence* sent);
};

class SearchEngine {
private:
    // You can add attributes/helper functions here
    int size;

public: 
    TrieNode* trie_root;
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};