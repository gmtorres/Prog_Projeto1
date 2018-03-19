#include "Dicionario.h"

Dicionario::Dicionario(){
	for (char c = 'A'; c <= 'Z'; c++) {
		std::vector <std::string> t;
		words.push_back(t);
	}
}

//---------------------------------------------------------------------------------------

Dicionario::Dicionario(std::string in_f,std::string out_f){
	input_file_n = in_f;
	output_file_n = out_f;
	for (char c = 'A'; c <= 'Z'; c++) {
		std::vector <std::string> t;
		words.push_back(t);
	}
}

//--------------------------------------------------------------------------------------

void Dicionario::set_input(std::string str) {
	input_file_n = str;
}

//-----------------------------------------------------------------------------------------

void Dicionario::set_output(std::string str){
	output_file_n = str;
}

//----------------------------------------------------------------------------------------

void Dicionario::read() {
	if (input_file_n.empty())
		std::cout << "No input file especified." << std::endl;
	else {
		in_file.open(input_file_n);
		if (in_file.is_open()) {
			std::string linha;
			char atual = 'A';
			std::cout << "\nA" << std::endl;
			int ocorrencias_100 = 0;
			int outsider = 0;
			while (getline(in_file,linha)) {
				if (isValid(linha)) {
					std::vector<std::string> palavras = get_words(linha);
					if (palavras.size() > 0) {
						char prim = palavras[0][0];
						if (prim == atual+1) {
							outsider++;
							if (outsider > 0) {			//set to 0, 1 would also be a good option because then we are more certain that there was no mistake
								atual = prim;
								ocorrencias_100 = 0;
								std::cout << "\n" << atual << std::endl;
								outsider = 0;
							}
						}
						for (size_t i = 0; i < palavras.size(); i++) {
							while ((ocorrencias_100+1) * 100 < words[int(atual - 'A')].size()) {
								std::cout << ".";
								ocorrencias_100++;
							}
							simple_words++;
							words[int(palavras[i][0] - 'A')].push_back(palavras[i]);
						}
					}
				}
			}
			std::cout << std::endl;
			in_file.close();
		}
		else {
			std::cout << "Unable to open " <<input_file_n<< "." << std::endl;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------

bool Dicionario::isValid(std::string str) {
	for (int i = 0; i < str.length(); i++) {
		int c = int(str[i]);
		if ((c<65 || c>90) && c!=' ' && c != ';' && c != '-' && c!= '\'')
			return false;
	}
	return true;
}

//------------------------------------------------------------------------------------------------------------------------

void Dicionario::print() {
	for (size_t i = 0; i < words.size(); i++)
		for (size_t ii = 0; ii < words[i].size(); ii++)
			std::cout << words[i][ii] << std::endl;
}

//------------------------------------------------------------------------------------------------------------------------

size_t  Dicionario::get_nSimple() {
	return simple_words;
}

//---------------------------------------------------------------------------------------------------------------------------

size_t Dicionario::get_nUnique() {
	return unique_words;
}

//----------------------------------------------------------------------------------------------------------------------

std::vector<std::string> Dicionario::get_words(std::string str) { // str é uma 'headline' pode conter mais que uma palavra
	std::vector<std::string> palavras;
	const int n = 3;
	const char special[n] = { '-','\'',';' };
		for (int i = 0; i < str.size(); i++) { //Substitui os carateres especiais (- , \ , ;) por espaços 
			for (int a = 0; a < n; a++) {
				if (str[i] == special[a]) {
					str[i] = ' ';
					break;
				}
			}
		}
		std::string temp = ""; //Guarda a palavra antes de a enviar para o vetor
		for (int i = 0; i < str.size(); i++) { //Percorre a headline toda
			if (str[i] == ' '){ // Ao encontrar umm espaço envia a palavra para o vetor
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
	return palavras;
}


