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

class TrieNode{
    public:
    Sentence* sentence;
    TrieNode** children;
    TrieNode();
    TrieNode(Sentence* sent);
    void insert(Sentence* sent);
};

class SearchEngine {
private:
    // You can add attributes/helper functions here
    TrieNode* trie_root;
    int size;

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};