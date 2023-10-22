// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class SymNode {
public:
    string key;
    int height;
    int address=-1;
    
    SymNode* par = NULL;
    SymNode* left = NULL;
    SymNode* right = NULL;

    SymNode();
    SymNode(string k);

    SymNode* LeftLeftRotation(); // case 1
    SymNode* RightRightRotation(); // case 2
    SymNode* LeftRightRotation(); // case 3
    SymNode* RightLeftRotation(); // case 4

    ~SymNode();
    
};

class Dict {
private:
    // You can add attributes/helper functions here

public: 
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};