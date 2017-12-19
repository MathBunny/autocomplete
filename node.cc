#include "node.h"

using namespace std;

int Node::getChildrenCount(){
    return childrenCount;
}

bool Node::getIsTerminal(){
    return isTerminal;
}

vector<string> Node::getSuggestions(string str, string acc){
    vector<string> ans;
    if (str != ""){
        if (children.count(str[0]) == 0){
            return ans;
        }
        return children[str[0]]->getSuggestions(str.substr(1), acc + str[0]);
    }
    
    if (isTerminal){
        ans.emplace_back(acc);
    }

    for(auto &p : children){
        vector<string> tmp = children[p.first]->getSuggestions("", acc + p.first);
        for(auto &o : tmp){
            ans.emplace_back(o);
        }
    }
    return ans;
}

void Node::insertStr(string str){
    if (str.length() == 0){
        isTerminal = true;
        return;
    }

    childrenCount++;

    if (children.count(str[0]) == 0){
        children[str[0]] = make_unique<Node>();
    } 

    if (str.length() == 1){
        children[str[0]]->insertStr("");
    }
    else{
        children[str[0]]->insertStr(str.substr(1));
    }
}

bool Node::canResolve(string str){
    if (str.length() == 0 && (isTerminal || childrenCount == 1)){
        return true;
    }
    if (str.length() == 0 || children.count(str[0]) == 0){
        return false;
    }
    return children[str[0]]->canResolve(str.substr(1));
}

string Node::resolveString(string str, string ans){
    if (str == ""){
        for(auto &p: children){
            char newChar = p.first;
            ans += newChar;
            return children[newChar]->resolveString(str, ans);
        }
        return ans;
    }
    return children[str[0]]->resolveString(str.substr(1), ans + str[0]);
}

Node::Node(): childrenCount{0}{}