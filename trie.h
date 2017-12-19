#include <string>
#include <memory>
#include "node.h"

#ifndef TRIE_H
#define TRIE_H

class Trie{
    Node parent;
    void insert(std::string str);

   public:
    void addToWordset(std::vector<std::string> &wordset);
    void addToWordset(std::string word);
    bool canResolve(std::string str);
    std::string resolveString(std::string str);
    std::vector<std::string> getSuggestions(std::string str);
    Trie(std::vector<std::string> wordset);
};

#endif