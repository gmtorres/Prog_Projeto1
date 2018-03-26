#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

class WordData
{
private:
	vector <string> words;
	vector <int > frequency;
	string input_file = "";

public:
	
	WordData();
	WordData(string str);
	string getword(size_t i);
	size_t get_wsize();
	string getInputFile();
	bool addWord(string str);
	bool removeWord(string str);
	void clear();
	void LoadWords();
	void set_inputFile(string str);
	bool check_Word(string str);
	void makeupper(string &str);
	bool randomWord(string &str);
	void scrambleWord(string &str);
	vector<char> give_char(int n);
	vector<string> search_word_set(vector<char> chars);
	bool word_has_char(char c, string palavra);
	//~WordData();
};

