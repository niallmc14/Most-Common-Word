/**
 * Author: Niall Mc Guinness
 */


#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

struct val_lessthan : binary_function <pair<string,int>, pair<string,int>, bool>
{
  bool operator()(const pair<string,int>& x, const pair<string,int>& y) const{
	  return x.second < y.second;
  }
}val_lt;


void count_words(string filename) {

	map<string, int> word_map;
	int max_count = 0;
	string most_common_word;
	string word;

	//Open file for reading

	ifstream in(filename.c_str());

	//Check if the file has been found and loaded properly
	if(!in) {
		cout << "File not found." << endl;
		return;
	}

	//Loop through the file and map each new word to each occurrence
	while(in >> word) {
		word_map[word]++;
	}

	// Loop through map to find the max

	for(auto &e : word_map) {
		if(e.second > max_count) {
			max_count = e.second;
			most_common_word = e.first;
		}
	}
	cout << "Most common word: " << most_common_word << " " << max_count << endl;
}

int main() {


	//count_words("lotr.txt");
	count_words("file.txt");

	return 0;
}
