#include <utility>
#include <queue>
#include <memory>
#include <sstream>
#include "trie.h"

using namespace std;

void Trie::addToWordset(vector<string> &wordset){
    for(string &s: wordset){
        insert(s);
    }
}

void Trie::addToWordset(string word){
    insert(word);
}

void Trie::insert(string str){
    parent.insertStr(str);
}

bool Trie::canResolve(string str){
    return parent.canResolve(str);
}

string Trie::resolveString(string str){
    return parent.resolveString(str, "");
}

vector<string> Trie::getSuggestions(string str){
    return parent.getSuggestions(str, "");
}

Trie::Trie(vector<string> wordset){
    for(string str: wordset){
        insert(str);
    }
}

