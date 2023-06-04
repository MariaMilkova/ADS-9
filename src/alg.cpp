// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

bool isLetter(char symbol) {
    return symbol >= 'a' && symbol <= 'z';
}

BSTree<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BSTree<std::string> tree;
    std::string word;
    char character;
    if (!file) {
        std::cout << "File error!" << std::endl;
        return tree;
    }
    while (!file.eof()) {
        character = file.get();
        if (isLetter(character)) {
            character = tolower(character);
            word += character;
        }
        tree.add(word);
        word.clear();
    }
    file.close();
    return tree;
}
