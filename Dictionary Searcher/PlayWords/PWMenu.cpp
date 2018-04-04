
#ifdef __unix__ 
// linux code goes here
#define CLEAR "clear"
#elif _WIN32
// windows code goes here
#define CLEAR "cls"
#else
#error "OS NOT SUPPORTED"
#endif



#include "PWMenu.h"
#include "WordData.h"


bool isalpha_string(string str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i]< 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z') && !(str[i] == ' ') && !(str[i] == '\n'))
		{
			return false;
		}
	}
	return true;
}

bool alfabetico(string str) {
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!(isalpha(str[i])))
			return false;
	}
	return true;
}

void rm_spaces(string &s)
{
	string temp = "";
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!(s[i] == ' '))
			temp += s[i];
	}
	s = temp;
}


void op_a(WordData &wd) {
	string str;
	cout << "\nIntroduce a word: "; cin >> str;
	while (true)
	{
		if (!cin.fail() && cin.peek() == '\n' && alfabetico(str))
			break;
		cin.clear();
		cin.ignore(100000000, '\n');
		cout << "Error. Introduce a word with only alphabetic caracters: "; cin >> str;
	}
	if (wd.check_Word(str))
		cout << str << " is in the word list." << endl;
	else
		cout << str << " is not in the word list." << endl;

}





void op_b(WordData &wd) {
	string word_o;
	if (wd.randomWord(word_o)) {
		string word_s = word_o;
		wd.scrambleWord(word_s);
		cout << "\n\nGUESS THE WORD : " << word_s << endl;
		string tentativa = "";
		int max_t = 3;
		while (max_t > 0) {
			cin >> tentativa;
			wd.makeupper(tentativa);
			if (tentativa.compare(word_o) == 0) {
				cout << "CORRECT!!" << endl;
				break;
			}
			else {
				max_t--;
				if (max_t == 0) {
					cout << "GAME OVER\tTHE WORD WAS : " << word_o << endl;
				}
				else {
					cout << "TRY AGAIN" << endl;
				}
			}
		}
	}
}

bool isValid(string str, vector<char> vec) {
	if (str.length() > vec.size())
		return false;
	for (size_t i = 0; i < str.length(); i++) {
		bool v = false;
		for (int a = 0; a < vec.size(); a++) {
			if (str[i] == vec[a]) {
				vec[a] = '\0';
				v = true;
				break;
			}
		}
		if (!v)
			return false;
	}
	return true;
}

void op_c(WordData &wd) {
	string str;
	vector<char> chars;
	cin.clear();
	cin.ignore(1);
	cout << "\nIntroduce a set of alphabetic caracters: "; getline(cin, str);  //cin.ignore();
	//cout << str.size();
	while (true) {
		if (isalpha_string(str))
			break;
		cout << "Error. Introduce a set of alphabetic caracters: "; cin >> str;
	}
	wd.makeupper(str);
	for (size_t i = 0; i < str.length(); i++) {
		if (!(str[i] == ' '))
			chars.push_back(str[i]);
	}
	size_t n = 0;
	for (size_t i = 0; i < wd.get_wsize(); i++) {
		if (isValid(wd.getword(i), chars)) {
			n++;
			cout << wd.getword(i) << endl;;
		}
	}
	if (n == 0) {
		cout << "No words found" << endl;
	}

}

void op_d(WordData &wd) {
	cout << "\n\nNumber of letters?" << endl;
	int n;
	cin >> n;
	while (cin.fail() || n <= 0) {
		cout << "Incorrect input" << endl;
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> n;
	}
	vector<char> vec = wd.give_char(n);
	cout << "Form a word with the given set: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
	string inp = "";
	cin >> inp;
	wd.makeupper(inp);
	while (!isValid(inp, vec)) {
		cout << "Input invalido" << endl;
		cin >> inp;
		wd.makeupper(inp);
	}
	if (wd.check_Word(inp)) {
		cout << "CORRECT" << endl;
	}
	else {
		cout << "INCORRECT" << endl;
	}

}

bool wildcardMatch(const char *str, const char *strWild) {
	while (*strWild) {
		// Single wildcard character
		if (*strWild == '?') {
			// Matches any character except empty string
			if (!*str)
				return false;
			// OK next
			++str;
			++strWild;
		}
		else if (*strWild == '*') {
			if (wildcardMatch(str, strWild + 1))
				// we have a match and the * replaces no other character
				return true;
			if (*str && wildcardMatch(str + 1, strWild))
				return true;
			// Nothing worked with this wildcard.
			return false;
		}
		else
		{
			if (toupper(*str++) != toupper(*strWild++))
				return false;
		}
	}
	// Have a match? Only if both are at the end...
	return
		!*str && !*strWild;
}

void op_e(WordData &wd) {
	cout << "\nIntroduce a word, may contain wildcards ( '?' = unknown caracter , '*' = unknown sequence of caracters ): ";
	string word;
	cin >> word;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cin >> word;
	}
	wd.makeupper(word);
	const char *c_word = word.c_str();
	size_t n = 0;
	for (size_t i = 0; i < wd.get_wsize(); i++) {
		if (wildcardMatch(wd.getword(i).c_str(), c_word)) {
			n++;
			cout << wd.getword(i) << endl;
		}
	}
	if (n == 0) {
		cout << "No words found." << endl;
	}

}
bool op_f(WordData &wd) {
	string ch;
	char kappa = 'y';
	system(CLEAR);
	cout << "\nChoose an option (CTRL + Z to go back):\n\n"
		<< "a) Change words file.\n"
		<< "b) Add a word.\n"
		<< "c) Remove a word.\n"
		<< "d) Clear words.\n"
		<< "e) Print words.\n\n";
	cin >> ch;
	wd.makeupper(ch);
	if (cin.eof()) {
		cin.clear();
		system(CLEAR);
		return false;
	}
	while (cin.fail()) {
		cout << "Invalid option" << endl;
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> ch;
		if (cin.eof()) {
			cin.clear();
			return false;
		}
	}
	char cha = ch[0];
	string str;
	switch (cha) {
	case 'A':
		system(CLEAR);
		cout << "Words file: ";
		cin >> str;
		wd.set_inputFile(str);
		cout << "Loading words...";
		wd.LoadWords();
		cout << endl;
		break;
	case 'B':
		cout << "Word to add: ";
		cin >> str;
		if (wd.addWord(str)) {
			cout << "Word added sucessfully.\n";
		}
		else
			cout << "Word already exists.\n";
		break;
	case 'C':
		cout << "Word to remove: ";
		cin >> str;
		if (wd.removeWord(str)) {
			cout << "Word removed sucessfully.\n";
		}
		else
			cout << "Word doesn't exist.\n";
		break;
	case 'D':
		wd.clear();
		cout << "Words cleared" << endl;
		break;
	case 'E': {
		if (wd.get_wsize() > 100) {
			cout << "There's " << wd.get_wsize() << " words. This may take a while. Do you want to continue? [y/n] "; cin >> kappa;
		}

		while (cin.fail() && (kappa != 'N' || kappa != 'n' || kappa != 'Y' || kappa != 'y'))
		{
			cout << "Invalid input. " << endl;
			cin.clear();
			cin.ignore(100000000, '\n');
			cin >> kappa;
		}

		if (kappa == 'y' || kappa == 'Y')
		{
			wd.printw();
		}
		break;
	}
	}
	cout << "Press ENTER to continue: "; cin.get(); cin.get();
	return true;
}

bool menu(WordData &wd) {
	string ch;
	system(CLEAR);
	cout << "Choose an option (CTRL + Z to exit):\n\n"
		<< "a) Check if the word belongs to the word list.\n"
		<< "b) Guess the word.\n"
		<< "c) Given a set show all posivel combinations.\n"
		<< "d) Given a random set of leters, guess a word.\n"
		<< "e) Read a word with wildcard caracters and return all possivel sets.\n"
		<< "f) Options.\n\n";
	cin >> ch;
	wd.makeupper(ch);
	if (cin.eof()) {
		cin.clear();
		return false;
	}
	while (cin.fail() && (ch != "A" || ch != "B" || ch != "C" || ch != "D" || ch != "E" || ch != "F")) {
		cout << "Invalid option" << endl;
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> ch;
		wd.makeupper(ch);
		if (cin.eof()) {
			cin.clear();
			return false;
		}
	}
	char cha = ch[0];
	switch (cha) {
	case 'A': op_a(wd);
		break;
	case 'B': op_b(wd);
		break;
	case 'C': op_c(wd);
		break;
	case 'D': op_d(wd);
		break;
	case 'E':op_e(wd);
		break;
	case 'F':do {
	} while (op_f(wd));
	break;
	}
	cout << endl;
	cout << "Press ENTER to continue: "; cin.get(); cin.get();
	return true;
}
