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

	bool exists(std::string str); //verifica se uma palavra ja se encontra na lista, true se existir, falso caso não exista
	std::vector<std::string> get_words(std::string); // dada uma linha de um ficheiro, caso as letras constituintes sejam maiusculas ou caracteres especiais, retorna as palavras constituintes
	bool isValid(std::string str);// verifica se uma palavra é valida, se nao contem lowercase letras

public:
	
	Dicionario();  //Incializar o objeto sem parametros
	Dicionario(std::string in_f, std::string out_f); //Inicializar o objeto com os nomes dos ficheiros de entrada e saida
	void set_input(std::string str); // Atribuir um nome ao ficheiro de entrada
	void set_output(std::string str); //Atribuir um nome ao ficheiro de saida
	void read();	// Lê do ficheiro as headlines
	void print();	// Mostra no ecra todas a ocorrencias (nao recomendado)
	size_t get_nSimple();
	size_t get_nUnique();
	
};

