#pragma once
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <cstring>
using namespace std;

class WordData
{
private:
	vector <string> words;
	string input_file = "";
	
	string randomWord();

public:
	WordData();
	string getInputf();
	void LoadWords();
	void set_inputFile(string str);
	bool check_Word(string str);
	void makeupper(string &str);

	//~WordData();
};

