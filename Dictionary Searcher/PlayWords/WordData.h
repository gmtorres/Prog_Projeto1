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
	vector <vector <string>> words;
	string input_file = "";
	


public:
	WordData();
	string getInputf();
	void LoadWords();
	void set_inputFile(string str);


	//~WordData();
};

