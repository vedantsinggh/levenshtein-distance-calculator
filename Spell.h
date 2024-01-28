#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define print(x) std::cout<<x
#define println(x) std::cout<<x<<std::endl

void printBoard(std::vector<std::vector<int>>& matrix);
int getLevenshtein(std::string word1, std::string word2);
void spellCheck(std::string checkWord);