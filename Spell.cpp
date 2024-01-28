#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

#define print(x) std::cout<<x
#define println(x) std::cout<<x<<std::endl

void printBoard(std::vector<std::vector<int>>& matrix){
	for (short i = 0; i < matrix.size(); i++){
		for (short j = 0; j < (matrix)[i].size(); j++){
			print((matrix)[i][j]);
		}
		println(" ");
	}
}

int getLevenshtein(std::string word1, std::string word2){
	std::vector<std::vector<int>> matrix;
	word1 = " " + word1, word2 = " " + word2;
	for (short i = 0; i < word2.size(); i++){
		matrix.push_back({});
		for (short j = 0; j < word1.size(); j++){
			matrix[i].push_back(0);
		}
	}
	for (short i = 0; i < word1.size(); i++) matrix[0][i] = i;
	for (short i = 0; i < word2.size(); i++) matrix[i][0] = i;

	for (short i = 1; i < word2.size(); i++){
		for (short j = 1; j < word1.size(); j++){
			int minimum = std::min(matrix[i-1][j], std::min(matrix[i][j-1],matrix[i-1][j-1]));
			if (word1[i] != word2[j]) minimum += 1;
			matrix[i][j] = minimum;
		}
	}
	return matrix[word2.size() - 1][word1.size() - 1];
}

void spellCheck(std::string checkWord){
    std::fstream wordFile;
    wordFile.open("words.txt",std::ios::in);
    if (wordFile.is_open()){
      std::string word;
      while(getline(wordFile, word)){
        int lv = getLevenshtein(word, checkWord);
        std::string k = word + std::to_string(lv);
        if (lv < 3) println(k);
      }
      wordFile.close();
   }
}