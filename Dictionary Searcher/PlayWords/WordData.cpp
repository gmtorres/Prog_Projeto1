#include "WordData.h"

using namespace std;

WordData::WordData()
{
	for (char c = 'A'; c <= 'Z'; c++)
		frequency.push_back(0);
}

string WordData::getInputf()
{
	return WordData::input_file;
}

void WordData::LoadWords()
{
	ifstream dic;
	string line;
	dic.open(getInputf());
	if (dic.is_open())
	{
		while (getline(dic, line))
		{
			WordData::words.push_back(line);
			for (int i = 0; i < line.length()-1; i++) {
				frequency[line[i] - 'A']++;
			}
		}
	}
	dic.close();
}

void WordData::set_inputFile(string str) {
	input_file = str;
}

bool binarySearch(const  vector<string>  v, string value) {
	int indice=-1;
	for (size_t bottom = 0, top = v.size(); bottom <= top;) {
		int middle = floor((top + bottom) / 2);
		if (v[middle].compare(value) == 0) {
			indice = middle;
			break;
		}
		else if (v[middle].compare(value) > 0) {
			top = middle - 1;
		}
		else {
			bottom = middle + 1;
		}
	}
	if (indice == -1)
		return false;
	return true;
}

void WordData::makeupper(string &str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}



bool WordData::check_Word(string str) {
	makeupper(str);
	return binarySearch(words, str);
}

string WordData::randomWord() {
	if (words.size() < 0)
		return "";
	else return words[rand() % words.size()];
}

void WordData::scrambleWord(string &str) {
	for (int i = 0; i < str.size() * 2; i++) {
		int r1, r2;
		r1 = rand() % str.size();
		r2 = rand() % str.size();
		char temp = str[r1];
		str[r1] = str[r2];
		str[r2] = temp;
	}
	//return str;
}


vector<char> WordData::give_char(int n) {
	int sum = 0;
	vector<char> vec;
	for (int i = 0; i < frequency.size(); i++)
		sum += frequency[i];
	for (int i = 0; i < n; i++) {
		int r = rand() % sum;
		int c = 0;
		for (int s = 0; s<r; c++) {
			s += frequency[c];
		}
		vec.push_back(c + 'A');
	}
	return vec;
}


vector<string> WordData::search_word_set(vector<char> chars) {
		  
}

vector <string> WordData::getWords() {
	return words;
}