#pragma once
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

class Dicionario{
private:
	std::string input_file_n, output_file_n;
	std::ifstream in_file;
	std::ofstream out_file;
	std::vector<std::string> words;
	size_t simple_words = 0;
	size_t unique_words = 0;

	bool isValid(std::string str);// verifica se uma palavra é valida, se nao contem lowercase letras
	bool exists(std::string str); //verifica se uma palavra ja se encontra na lista, true se existir, falso caso não exista

public:
	
	Dicionario();  //Incializar o objeto sem parametros
	Dicionario(std::string in_f, std::string out_f); //Inicializar o objeto com os nomes dos ficheiros de entrada e saida
	void set_input(std::string str); // Atribuir um nome ao ficheiro de entrada
	void set_output(std::string str); //Atribuir um nome ao ficheiro de saida
	void read();
	void print();
	size_t get_nSimple();
	size_t get_nUnique();
};

