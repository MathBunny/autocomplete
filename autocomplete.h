#include <string>
#include <memory>
#include <vector>
#include "trie.h"

#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

class AutoComplete{
    std::unique_ptr<Trie> trie;
    bool isCaseInsensitive;

   public:
    void addToWordset(std::vector<std::string> wordset);
    void addToWordset(std::string word);
    bool canResolve(std::string str);
    std::string resolveString(std::string str);
    std::vector<std::string> getSuggestions(std::string str);
    AutoComplete(std::vector<std::string> type, bool isCaseInsensitive = false);
    AutoComplete(bool isCaseInsensitive = false);
};
#endif