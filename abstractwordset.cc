#include "abstractwordset.h"

using namespace std;

vector<string> AbstractWordSet::getWordSet(){
    return wordset;
}

void AbstractWordSet::addToWordSet(string str){
    wordset.emplace_back(str);
}

AbstractWordSet::~AbstractWordSet(){}
