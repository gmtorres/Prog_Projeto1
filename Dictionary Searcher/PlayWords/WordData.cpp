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

bool binarySearch(const  vector<string>  v, string value) {
	int indice=-1;
	for (int bottom = 0, top = v.size(); bottom <= top;) {
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
	return binarySearch(words[int(str[0] - 'A')], str);
}