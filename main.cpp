#include <string>
#include <vector>
#include <iostream>
#define print(x) cout<<x
#define println(x) cout<<x<<endl
using namespace std;


void printBoard(vector<vector<int>>& matrix){
	for (short i = 0; i < matrix.size(); i++)
	{
		for (short j = 0; j < (matrix)[i].size(); j++)
		{
			print((matrix)[i][j]);
		}
		println(" ");
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> matrix;

	string word1 = " bed", word2 = " bat";

	for (short i = 0; i < word2.size(); i++){
		matrix.push_back({});
		for (short j = 0; j < word1.size(); j++){
			matrix[i].push_back(0);
		}
	}

	for (short i = 0; i < word1.size(); i++) matrix[0][i] = i;
	for (short i = 0; i < word2.size(); i++) matrix[i][0] = i;

	for (short i = 1; i < word1.size(); i++){
		for (short j = 1; j < word2.size(); j++){
			int minimum = min(matrix[i-1][j], min(matrix[i][j-1],matrix[i-1][j-1]));
			if (word1[i] != word2[j]) minimum += 1;
			matrix[i][j] = minimum;
		}
	}

	printBoard(matrix);
	return 0;
}


