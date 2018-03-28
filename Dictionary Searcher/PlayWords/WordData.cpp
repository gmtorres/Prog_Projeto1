#include "WordData.h"

//using namespace std;

int binarySearch(const  vector<string>  v, string value) {
	if (v.size() == 0)
		return -1;
	for (int bottom = 0, top = v.size()-1; bottom <= top;) {
		int middle = static_cast<int>(floor((top + bottom) / 2));
		if (v.at(middle).compare(value) == 0) {
			return middle;
		}
		else if (v.at(middle).compare(value) > 0) {
			top = middle - 1;
		}
		else {
			bottom = middle + 1;
		}
	}
	return -1;
}

WordData::WordData(){
	for (char c = 'A'; c <= 'Z'; c++)
		frequency.push_back(2);
}
WordData::WordData(string str) {
	for (char c = 'A'; c <= 'Z'; c++)
		frequency.push_back(2);
	set_inputFile(str);

}

string WordData::getInputFile(){
	return WordData::input_file;
}

bool WordData::addWord(string str) {
	makeupper(str);
	if (!check_Word(str)) {
		words.push_back(str);
		sort(words.begin(), words.end());
		for (size_t i = 0; i < str.length(); i++)
			frequency[str[i] - 'A']++;
		return true;
	}
	return false;
}
bool WordData::removeWord(string str) {
	makeupper(str);
	int n = binarySearch(words, str);
	if (n != -1) {
		for (size_t i = 0; i < str.length(); i++)
			frequency[str[i] - 'A']--;
		for (size_t i = n; i < words.size() - 1; i++)
			words[i] = words[i + 1];
		words.resize(words.size() - 1);
		return true;
	}
	return false;
}

void WordData::clear() {
	words.clear();
	for (size_t i = 0; i < frequency.size(); i++) {
		frequency[i] = 2;
	}
}

void WordData::LoadWords(){
	ifstream dic;
	string line;
	dic.open(getInputFile());
	if (dic.is_open()){
		while (getline(dic, line)){
			WordData::words.push_back(line);
			for (size_t i = 0; i < line.length() - 1; i++) {
				frequency[line[i] - 'A']++;
			}
		}
	}
	else {
		cout << "Unable to open file" << endl;
	}
	dic.close();
}

void WordData::set_inputFile(string str) {
	input_file = str;
}

void WordData::makeupper(string &str) {
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = toupper(str[i]);
	}
}


bool WordData::check_Word(string str) {
	makeupper(str);
	if (binarySearch(words, str) == -1)
		return false;
	return true;
}

bool WordData::randomWord(string &str) {
	if (words.size() <= 0) {
	str = "";
	return false;
	}
	long r = (rand() << 15 | rand()) % words.size();
	str= words[r];
	return true;
}

void WordData::scrambleWord(string &str) {
	if (str.length() > 1) {
		string temp = str;
		for (size_t t = 0; t < 4 && temp == str; t++) {
			for (size_t i = 0; i < str.size() * 2; i++) {
				int r1, r2;
				r1 = rand() % str.size();
				r2 = rand() % str.size();
				char temp = str[r1];
				str[r1] = str[r2];
				str[r2] = temp;
			}
		}
	}
	//return str;
}


vector<char> WordData::give_char(int n) {
	int sum = 0;
	vector<char> vec;
	for (size_t i = 0; i < frequency.size(); i++)
		sum += frequency[i];
	for (size_t i = 0; i < n; i++) {
		long r = (rand() << 15 | rand()) % sum;
		int c = 0;
		for (size_t s = 0; s <= r; c++) {
			s += frequency[c];
		}
		vec.push_back(char(c + 'A'-1));
	}
	return vec;
}


vector<string> WordData::search_word_set(vector<char> chars) {
	vector<string> out;
	string palavra;
	for (size_t i = 0; i < words.size(); i++){
		palavra = words[i];
		for (int j = 0; j < chars.size(); j++){
			if (word_has_char(chars[j], palavra)){
				if (j == chars.size() - 1)
					out.push_back(palavra);
			}
			else break;
		}
	}
	return out;
}

bool WordData::word_has_char(char c, string palavra) {
	for (size_t i = 0; i < palavra.length(); i++){
		if (palavra[i] == c)
			return true;
	}
	return false;
}



size_t WordData::get_wsize() {
	return words.size();
}

string WordData::getword(size_t i) {
	if(i<words.size())
		return words[i];
	return "";
}

void WordData::printw() {
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}
}