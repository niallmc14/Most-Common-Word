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

	map<string, int> word_count;

	ifstream in(filename.c_str());

	if(!in) {
		cout << "File not found." << endl;
		return;
	}

	string word;
	while(in >> word) {
		++word_count[word];
	}

	// do a simple loop through map to find the max:
	int max_count = 0;
	string most_common_word;

	for(auto &e : word_count) {
		if(e.second > max_count) {
			max_count = e.second;
			most_common_word = e.first;
		}
	}
	cout << "most common word: " << most_common_word << " " << max_count << endl;
}

int main(int argc, char **argv) {

	count_words("lotr.txt");
	count_words("file.txt");

	return 0;
}
