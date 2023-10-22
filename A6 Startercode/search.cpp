// Do NOT add any other includes
#include "search.h"

Sentence::Sentence(){
    sentence="";
    book_code=0;
    page=0;
    paragraph=0;
    sentence_no=0;
}

Sentence::Sentence(string sent,int b_code,int pg,int para,int sent_no){
    sentence=sent;
    book_code=b_code;
    page=pg;
    paragraph=para;
    sentence_no=sent_no;
}

TrieNode::TrieNode(){
    sentence = NULL;
    children = new TrieNode*[57];
    for(int i=0;i<57;i++)children[i]=NULL;
}

TrieNode::TrieNode(Sentence* sent){
    sentence = sent;
    children = new TrieNode*[57];
    for(int i=0;i<57;i++)children[i]=NULL;
}

void TrieNode::insert(Sentence* sent){
    string s = sent->sentence;
    int place;
    for(char32_t ch:s){
        if('a'<=ch && ch<='z')place = ch-'a';
        else if('A'<=ch && ch<='Z')place = ch-'A';
        else if('0'<=ch && ch<='9')place = 26+(ch-'0');
        else switch(ch){
            case ' ':place = 36;break;
            case '.':place = 37;break;
            case ',':place = 38;break;
            case '-':place = 39;break;
            case ':':place = 40;break;
            case '!':place = 41;break;
            case '\"':place = 42;break;
            case '\'':place = 43;break;
            case '(':place = 44;break;
            case ')':place = 45;break;
            case '?':place = 46;break;
            case '—':place = 47;break;
            case '[':place = 48;break;
            case ']':place = 49;break;
            case '“':place = 50;break;
            case '”':place = 51;break;
            case '‘':place = 52;break;
            case '’':place = 53;break;
            case '˙':place = 54;break;
            case ';':place = 55;break;
            case '@':place = 56;break;
            default:place = -1;
        }
        

    }
}

SearchEngine::SearchEngine(){
    // Implement your function here  
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    return;
}

Node* SearchEngine::search(string pattern, int& n_matches){
    // Implement your function here  
    return nullptr;
}