#pragma once
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class WordData
{
private:
	vector <vector <string>> words;
	string input_file = " ";
	


public:
	WordData();
	string getInputf();
	void LoadWords();


	//~WordData();
};

