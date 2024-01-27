#include <string>
#include <vector>
#include <iostream>
#define print(x) cout<<x
#define println(x) cout<<x<<endl
using namespace std;


void printBoard(vector<vector<int>>& matrix){
	for (short i = 0; i < matrix.size(); i++){
		for (short j = 0; j < (matrix)[i].size(); j++){
			print((matrix)[i][j]);
		}
		println(" ");
	}
}

int getLevenshtein(string word1, string word2){
	vector<vector<int>> matrix;
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
			int minimum = min(matrix[i-1][j], min(matrix[i][j-1],matrix[i-1][j-1]));
			if (word1[i] != word2[j]) minimum += 1;
			matrix[i][j] = minimum;
		}
	}
	return matrix[word2.size() - 1][word1.size() - 1];
}

int main(int argc, char const *argv[])
{
	println(getLevenshtein("word", "world"));
	println(getLevenshtein("word", "word"));
	println(getLevenshtein("word", "wood"));
	println(getLevenshtein("word", "wild"));
	return 0;
}


