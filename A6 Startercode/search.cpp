// Do NOT add any other includes
#include "search.h"
// #include "Node.cpp"

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

TrieList::TrieList(){
    data = NULL;
    prev = NULL;
    next = NULL;
    tail = NULL;
}

TrieList::TrieList(TrieNode* t){
    data = t;
    prev = NULL;
    next = NULL;
    tail = NULL;
}

TrieList::~TrieList(){
    if(next)delete next;
    next = NULL;
    prev = NULL;
    tail = NULL;
    data = NULL;
}

SentList::SentList(){
    data = NULL;
    prev = NULL;
    next = NULL;
    tail = NULL;
}

SentList::SentList(Sentence* s){
    data = s;
    prev = NULL;
    next = NULL;
    tail = NULL;
}

SentList::~SentList(){
    if(next)delete next;
    next = NULL;
    prev = NULL;
    tail = NULL;
    if(data)delete data;
    data = NULL;
}

TrieNode::TrieNode(){
    sentences = NULL;
    Occurances = NULL;
    children = new TrieNode*[101];
    for(int i=0;i<101;i++)children[i]=NULL;
    depth=0;
}

TrieNode::~TrieNode(){
    for(int i=0;i<101;i++)if(children[i])delete children[i];
    delete[] children;
    if(sentences)delete sentences;
    if(Occurances)
    for(int i=0;i<101;i++)if(Occurances[i])delete Occurances[i];
}


void TrieNode::insert(Sentence* sent){
    string s = sent->sentence;
    int place;
    TrieNode* at = this;
    for(char ch:s){
        place = (int)ch;
        if('A'<=place && 'Z'>=place)place+=32;
        if(place>'Z')place-=26;
        if(at->children[place]){
            at = at->children[place];
        }else{
            if(Occurances[place]){
                TrieList* tail = Occurances[place]->tail;
                tail->next = new TrieList(at);
                Occurances[place]->tail = tail->next;
                Occurances[place]->tail->prev = tail;
            }
            else{
                Occurances[place] = new TrieList(at);
                Occurances[place]->tail = Occurances[place];
            }
            at->children[place] = new TrieNode();
            at->children[place]->depth = at->depth+1;
            at = at->children[place];
        }
    }
    if(at->sentences){
        SentList* tail = at->sentences->tail;
        tail->next = new SentList(sent);
        at->sentences->tail = tail->next;
        at->sentences->tail->prev = tail;
    }
    else{
        at->sentences = new SentList(sent);
        at->sentences->tail = at->sentences;
    }
}

SearchEngine::SearchEngine(){
    // Implement your function here
    trie_root = new TrieNode();
    trie_root->Occurances = new TrieList*[101];
    for(int i=0;i<101;i++)trie_root->Occurances[i]=NULL;
    size=0;
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
    delete trie_root;
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here
    Sentence* sent = new Sentence(sentence,book_code,page,paragraph,sentence_no);
    trie_root->insert(sent);
    size++;
}

//helper

void traverse(Node*& tail,TrieNode* root,int &n_matches,int& off){
    if(root->sentences)
    for(SentList* at = root->sentences,*end = root->sentences->tail;;at=at->next){
        if(tail){
            tail->right = new Node(at->data->book_code,at->data->page,at->data->paragraph,at->data->sentence_no,off);
            tail->right->left = tail;
            tail = tail->right;
        }
        else{
            tail = new Node(at->data->book_code,at->data->page,at->data->paragraph,at->data->sentence_no,off);
        }
        n_matches++;
        if(at==end)break;
    }
    for(int i=0;i<101;i++){
        if(root->children[i]){
            traverse(tail,root->children[i],n_matches,off);
        }
    }
}

Node* SearchEngine::search(string pattern, int& n_matches){
    // Implement your function here
    n_matches=0;
    if(pattern!=""){
        int place =(int)pattern[0];
        if('A'<=place && 'Z'>=place)place+=32;
        if(place>'Z')place-=26;
        Node* head,*tail;
        head = tail = new Node();
        if(trie_root->Occurances[place]){
            for(TrieList* at = trie_root->Occurances[place],*end = at->tail;;at=at->next){
                TrieNode* root = at->data;
                bool notfound = false;
                for(int i=0,l=pattern.size();i<l;i++){
                    place =(int)pattern[i];
                    if('A'<=place && 'Z'>=place)place+=32;
                    if(place>'Z')place-=26;
                    if(root->children[place]){
                        root = root->children[place];
                    }
                    else{
                        notfound=true;
                        break;
                    }
                }
                if(!notfound){
                    traverse(tail,root,n_matches,at->data->depth);
                }
                if(at==end)break;
            }
        }
        Node* new_head = head->right;
        delete head;
        if(new_head)new_head->left = NULL;
        return new_head;
    }
    return NULL;
}

// int main(){
//     SearchEngine* S = new SearchEngine();
//     S->insert_sentence(0,0,0,0,"Happy Birthday to You");
//     S->insert_sentence(0,0,0,1,"Happy Birthday to me");
//     S->insert_sentence(0,0,0,2,"Sed Birthday to You");
//     int n_matches=0;
//     Node* head = S->search("birthday",n_matches);
//     for(Node* at = head;at;at=at->right){
//         cout<<at->sentence_no<<" "<<at->offset<<endl;
//     }
//     // TrieNode* root = S->trie_root;
//     // for(int i=0;i<101;i++)if(root->Occurances[71]->data->children[71]->children[i])cout<<char(i+26)<<" ";
//     // cout<<endl;
//     // for(int i=0;i<101;i++)if(root->children[89]->children[i])cout<<char(i+26)<<" ";
//     // cout<<endl;
//     delete S;
//     S=NULL;
//     cout<<"Finished without exception"<<endl;
//     return 0;
// }