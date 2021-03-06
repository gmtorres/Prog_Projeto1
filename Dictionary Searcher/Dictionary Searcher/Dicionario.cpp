#include "Dicionario.h"

Dicionario::Dicionario() {
	for (char c = 'A'; c <= 'Z'; c++) {
		std::vector <std::string> t;
		words.push_back(t);
	}
}

//---------------------------------------------------------------------------------------

Dicionario::Dicionario(std::string in_f, std::string out_f) {
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

void Dicionario::set_output(std::string str) {
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
			int atual = 'A';
			std::cout << "\nA" << std::endl;
			int ocorrencias_100 = 0;
			int outsider = 0;
			while (getline(in_file, linha)) {
				if (isValid(linha)) {
					std::vector<std::string> palavras = get_words(linha);
					if (palavras.size() > 0) {
						char prim = palavras[0][0];
						if (prim == atual + 1) {
							outsider++;
							if (outsider > 1) {			//set to 0, 1 would also be a good option because then we are more certain that there was no mistake
								atual = prim;
								ocorrencias_100 = 0;
								std::cout << "\n" << char(atual) << std::endl;
								outsider = 0;
							}
						}
						while ((ocorrencias_100 + 1) * 100 < words[int(atual - 'A')].size()) {
							std::cout << ".";
							ocorrencias_100++;
						}
						for (size_t i = 0; i < palavras.size(); i++) {
							//simple_words++;
							words[int(palavras[i][0] - 'A')].push_back(palavras[i]);
						}
					}
				}
			}
			std::cout << std::endl;
			in_file.close();
			for (size_t i = 0; i < words.size(); i++)
				simple_words += words[i].size();
		}
		else {
			std::cout << "Unable to open file " << input_file_n << " ." << std::endl;
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------

bool Dicionario::isValid(std::string str) {
	if (str.length() == 0)
		return false;
	for (int i = 0; i < str.length(); i++) {
		int c = int(str[i]);
		if ((c < 65 || c>90) && c != ' ' && c != ';' && c != '-' && c != '\'')
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

bool checkWord(std::string str) {

	for(int i = 0;i<str.length();i++)
		if (str[i] == '-' || str[i] == '\'' || str[i] == '\\')
			return false;
	return true;
}

//----------------------------------------------------------------------------------------------------------------------

std::vector<std::string> Dicionario::get_words(std::string str) { // str � uma 'headline' pode conter mais que uma palavra
	std::vector<std::string> palavras;
	/*
	const int n = 3;
	const char special[n] = { '-','\'',';' };
	for (int i = 0; i < str.size(); i++) { //Substitui os carateres especiais (- , \ , ;) por espa�os
		for (int a = 0; a < n; a++) {
			if (str[i] == special[a]) {
				str[i] = ' ';
				break;
			}
		}
	}*/
	/*
	std::string temp = ""; //Guarda a palavra antes de a enviar para o vetor
	for (int i = 0; i < str.size(); i++) { //Percorre a headline toda
		if (str[i] == ' ' || str[i] == '-' || str[i] == '\'' || str[i] == ';') { // Ao encontrar umm espa�o envia a palavra para o vetor
			if (!temp.empty()) {
				palavras.push_back(temp);
				temp.clear();
			}
		}
		else {
			temp += str[i];
		}
	}
	if (!temp.empty()) {
		palavras.push_back(temp);
	}
	*/
	
	std::string temp = ""; //Guarda a palavra antes de a enviar para o vetor
	bool w = true,space = false;
	for (int i = 0; i < str.size(); i++) { //Percorre a headline toda
		if (str[i] == '-' || str[i] == '\'' || str[i] == '\\') { // Ao encontrar umm espa�o envia a palavra para o vetor
			w = false;
			space = false;
		}
		else if (str[i] == ' ') { // Ao encontrar umm espa�o envia a palavra para o vetor
			if (!temp.empty()) {
				w = false;
			}
			space = true;
		}
		else if (str[i] == ';') { // Ao encontrar umm espa�o envia a palavra para o vetor
			if (w || space) {
				palavras.push_back(temp);
			}
			temp.clear(); 
			w = true;
			space = false;
		}
		else {
			temp += str[i];
			space = false;
		}
	}
	if (!temp.empty() && w) {
		palavras.push_back(temp);
	}
	
	/*
	std::stringstream line(str);
	std::string temp = "";
	while (line >> temp) {
		palavras.push_back(temp);
	}
	
	std::size_t found = str.find_first_of(";");
	while (found != std::string::npos) {
		std::string temp = str.substr(0, found);
		if (checkWord(temp))
			palavras.push_back(temp);
		str = str.substr(found+1, str.length());
		found = str.find_first_of(";");
	}
	if(checkWord(str))
		palavras.push_back(str);
		*/
	return palavras;
}

void Dicionario::ordenar() {
	for (size_t i = 0; i < words.size(); i++)
		std::sort(words[i].begin(), words[i].end());
}


void Dicionario::remove() {
	for (int a = 0; a < words.size(); a++) {
		int n = 0;
		std::string temp = "";
		for (size_t i = 0; i < words[a].size(); i++) {
			if (words[a][i] != temp) {
				temp = words[a][i];
				words[a][n] = temp;
				n++;
			}
		}
		words[a].resize(n);
	}
	int uw = 0;
	for (int i = 0; i < words.size(); i++)
		uw += words[i].size();
	unique_words = uw;
}


std::string Dicionario::get_inFile() {
	return input_file_n;
}


std::string Dicionario::get_outFile() {
	return output_file_n;
}

void Dicionario::make_out_file() {
	std::ofstream file;
	file.open(output_file_n);
	if (file.is_open())
	{
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++)
			{
				file << words[i][j] << '\n';
			}
		}

		file.close();
	}
}