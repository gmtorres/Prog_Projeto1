#include "Dicionario.h"


Dicionario::Dicionario(){}

Dicionario::Dicionario(std::string in_f,std::string out_f){
	input_file_n = in_f;
	output_file_n = out_f;
	//in_file.open(input_file_n);
	//out_file.open(out)
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
			std::string palavra;
			while (in_file >> palavra) {
				std::cout << palavra << std::endl;
			}
		}
		else {
			std::cout << "Unable to open " <<input_file_n<< "." << std::endl;
		}
	}

}



