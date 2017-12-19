#include "autocomplete.h"

using namespace std;

void AutoComplete::addToWordset(vector<string> wordset){
    trie->addToWordset(wordset);
}

void AutoComplete::addToWordset(string word){
    trie->addToWordset(word);
}

bool AutoComplete::canResolve(string str){
    return trie->canResolve(str);
}

string AutoComplete::resolveString(string str){
    return trie->resolveString(str);
}

AutoComplete::AutoComplete(std::vector<std::string> wordset){
    trie = make_unique<Trie>(wordset);
}

vector<string> AutoComplete::getSuggestions(string str){
    return trie->getSuggestions(str);
}