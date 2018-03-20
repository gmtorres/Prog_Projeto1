#include "WordData.h"

using namespace std;

WordData::WordData()
{
	for (char c = 'A'; c <= 'Z'; c++) {
		vector<string> temp;
		words.push_back(temp);
	}
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
			WordData::words[static_cast<int>(line[0]-'A')].push_back(line);
		}
	}
	dic.close();
}

void WordData::set_inputFile(string str) {
	input_file = str;
}

bool WordData::check_Word(string str) {

}