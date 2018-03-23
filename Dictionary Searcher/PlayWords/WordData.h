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
	
	string getword(int i);
	int get_wsize();
	WordData();
	string getInputf();
	void LoadWords();
	void set_inputFile(string str);
	bool check_Word(string str);
	void makeupper(string &str);
	bool randomWord(string &str);
	void scrambleWord(string &str);
	vector<char> give_char(int n);
	vector<string> search_word_set(vector<char> chars);
	vector <string> getWords();
	bool word_has_char(char c, string palavra);
	void rm_duplicates_char_vector(vector<char> &cv);
	//~WordData();
};

