#include <string>
#include <vector>

#ifndef ABSTRACT_WORD_SET_H
#define ABSTRACT_WORD_SET_H

class AbstractWordSet{
    std::vector<std::string> wordset;
    
   protected:
    void addToWordSet(std::string str);

   public:
    std::vector<std::string> getWordSet();
    virtual ~AbstractWordSet() = 0;
};
#endif