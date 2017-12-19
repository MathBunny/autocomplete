#include <algorithm>
#include "autocomplete.h"

using namespace std;

void AutoComplete::addToWordset(vector<string> wordset){
    if (isCaseInsensitive){
        for(auto &str: wordset){
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        }
    }
    trie->addToWordset(wordset);
}

void AutoComplete::addToWordset(string word){
    if (isCaseInsensitive){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
    trie->addToWordset(word);
}

bool AutoComplete::canResolve(string str){
    return trie->canResolve(str);
}

string AutoComplete::resolveString(string str){
    return trie->resolveString(str);
}

vector<string> AutoComplete::getSuggestions(string str){
    return trie->getSuggestions(str);
}

AutoComplete::AutoComplete(std::vector<std::string> wordset, bool isCaseInsensitive): isCaseInsensitive{isCaseInsensitive}{
    if (isCaseInsensitive){
        for(auto &str: wordset){
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        }
    }
    trie = make_unique<Trie>(wordset);
}

AutoComplete::AutoComplete(bool isCaseInsensitive): isCaseInsensitive {isCaseInsensitive}{
    trie = make_unique<Trie>(vector<string>(0));
}