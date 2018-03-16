#include "Dicionario.h"

Dicionario::Dicionario(){}

Dicionario::Dicionario(std::string in_f,std::string out_f){
	input_file_n = in_f;
	output_file_n = out_f;
}
void Dicionario::set_input(std::string str) {
	input_file_n = str;
}
void Dicionario::set_output(std::string str){
	output_file_n = str;
}
void Dicionario::read() {
	if (input_file_n.empty())
		std::cout << "No input file especified." << std::endl;
	else {
		in_file.open(input_file_n);
		if (in_file.is_open()) {
			std::string linha;
			while (getline(in_file,linha)) {
				std::vector<std::string> palavras= get_words(linha);
				for (size_t i = 0; i < palavras.size(); i++) {
					simple_words++;
					words.push_back(palavras[i]);
				}
			}
		}
		else {
			std::cout << "Unable to open " <<input_file_n<< "." << std::endl;
		}
	}
}
bool Dicionario::isValid(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		int c = int(str[i]);
		if ((c<65 || c>90) && c!=' ' && c != ';' && c != '-' && c!= '\'')
			return false;
	}
	return true;
}
void Dicionario::print() {
	for (size_t i = 0; i < words.size(); i++)
		std::cout << words.at(i) << std::endl;
}
bool Dicionario::exists(std::string str){
	for (size_t i = 0; i < words.size(); i++)
		if (str == words[i])
			return true;
	return false;
}
size_t  Dicionario::get_nSimple() {
	return simple_words;
}
size_t Dicionario::get_nUnique() {
	return unique_words;
}
std::vector<std::string> Dicionario::get_words(std::string str) {
	std::vector<std::string> palavras;
	const int n = 3;
	const char special[n] = { '-','\'',';' };
	if (isValid(str)) {
		for (int i = 0; i < str.size(); i++) {
			for (int a = 0; a < n; a++) {
				if (str[i] == special[a]) {
					str[i] = ' ';
					break;
				}
			}
		}
		std::string temp = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' '){
				if (!temp.empty()) {
					palavras.push_back(temp);
					temp = "";
				}
			}else {
				temp += str[i];
			}
		}
		if (!temp.empty()) {
			palavras.push_back(temp);
		}
	}
	return palavras;
}


