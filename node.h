#include <map>
#include <string>
#include <memory>
#include <vector>

#ifndef NODE_H
#define NODE_H

class Node{
    int childrenCount;
    bool isTerminal = false;
    std::map<char, std::unique_ptr<Node>> children;

   public:
    std::vector<std::string> getSuggestions(std::string s, std::string acc);
    int getChildrenCount();
    bool getIsTerminal();
    void insertStr(std::string str);
    bool canResolve(std::string str);
    std::string resolveString(std::string str, std::string res);
    Node();
};

#endif