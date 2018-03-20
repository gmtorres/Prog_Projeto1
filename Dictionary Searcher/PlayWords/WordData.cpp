#include "WordData.h"

using namespace std;

WordData::WordData()
{
}

string WordData::getInputf()
{
	return WordData::input_file;
}

void WordData::LoadWords()
{
	ifstream dic;
	int i = 0, j = 0;
	char c='A';
	string line;
	dic.open(getInputf());
	if (dic.is_open())
	{
		while (getline(dic, line))
		{
			c = line[0];
			if (c == line[0])
			{
				i = static_cast<int>(line[0]) - 65;
				j = 0;
			}
			WordData::words[i][j].push_back(line);
			j++;
		}
	}
	dic.close();
}