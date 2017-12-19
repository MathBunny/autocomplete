# Autocomplete

The purpose of this repository is to provide a quick implementation for autocompletes using a trie structure to be used in other projects. It features the ability to determine if a string is ambigious, resolve it, or return suggestions for possible list of words.

## Sample Usage
```cpp
#include "autocomplete.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main (){
    // Usage:
    // restart
    // restartIgnoreCase
    // add <string>
    // addSample
    // resolve <string>
    // canResolve <string>
    // getSuggestions <string>
    vector<string> sampleWords {"Aligator", "Amphibian", "Buck", "Bunny", "Cat", "Dog", "Giraffe", "Lion", "Squid", "Zebra"};

    string cmd, argument;
    AutoComplete c;
    while(1){
        cin >> cmd;
        if (cmd == "restart"){
            c = AutoComplete {};
        }
        else if (cmd == "restartIgnoreCase"){
            c = AutoComplete{true};
        }
        else if (cmd == "add"){
            cin >> argument;
            c.addToWordset(argument);
        }
        else if (cmd == "addSample"){
            c.addToWordset(sampleWords);
        }
        else if (cmd == "resolve"){
            cin >> argument;
            if (!c.canResolve(argument)){
                cerr << "Error - cannot resolve string" << endl;
            }
            else{
                cout << argument << " resolves to " << c.resolveString(argument) << endl;
            }
        }
        else if (cmd == "canResolve"){
            cin >> argument;
            if (c.canResolve(argument)){
                cout << argument << " can be resolved." << endl;
            }
            else{
                cout << argument << " cannot be resolved." << endl;
            }
        }
        else if (cmd == "getSuggestions"){
            cin >> argument;
            cout << "Suggestions:" << endl;
            for(auto &s: c.getSuggestions(argument)){
                cout << "=> " << s << endl;
            }
        }
        else{
            cerr << "Error - invalid command" << endl;
        }
    }
}
```