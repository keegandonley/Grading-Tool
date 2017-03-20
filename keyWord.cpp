#include "keyWord.hpp"
#include "Comment.hpp"
#include "colors.h"
#include <iostream>
#include <fstream>


keyWord::keyWord() {
}

bool keyWord::addKey(std::string key, int value, std::string comment){
    keyWordPoint[key] = value;
    keyWordComment[key] = comment;

    return true;
}

void keyWord::readKeys() {
    // Read the keyWords from the file
    std::string key;
    int value;
    std::string comment;

    std::ifstream infile;
    infile.open ("keyWords.txt");
    while (infile >> key >> value) {
        std::getline(infile, comment);
        addKey(key, value, comment);
    }

}

bool keyWord::isProperKeyWord(std::string key) {
    return !(keyWordPoint.find(key) == keyWordPoint.end() && keyWordComment.find(key) == keyWordComment.end());
}

std::string keyWord::getComment(std::string key) {
    return keyWordComment[key];
}

int keyWord::getValue(std::string key) {
    return keyWordPoint[key];
}

void keyWord::printComments() {
    std::cout << "Existing deductions, keywords, and values ----------------------------------------------------------\n" << std::endl;
    for( auto iter = keyWordComment.begin(); iter != keyWordComment.end(); ++iter )
        std::cout << iter -> first << " -" << getValue(iter -> first) << " point(s) - " <<  iter -> second << "\n\n";
    std::cout << "----------------------------------------------------------------------------------------------------\n" << std::endl;
}
