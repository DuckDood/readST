#include <iostream>

std::string encrypt(std::string text, std::string thisText, std::string thing) {
    while(text.find(thisText) != text.npos) {
    
    int there = text.find(thisText);
    text.erase(there, thisText.length());
    text.insert(there, thing);
}
return text;
}

std::string decrypt(std::string text, std::string thisText, std::string thing) {
 while(text.find(thing) != text.npos) {
    int here = text.find(thing);
    text.erase(here, thing.length());
    text.insert(here, thisText);
    }
    return text;
}

