/*
 * main.cpp
 *
 *  Created on: Oct 31, 2025
 *      Author: kng
 */


#include "../config.h"
#include "../src/TextParser.cpp"
#include "TextParser.hpp"
#include <ranges>
#include <string>

using namespace std;

void run_UI() {
	TextParser txtpar = TextParser();
	vector<string> words_to_parse;
	vector<string> file_names;
	char chr = '^';

	while (chr != 'q') {
		string query_string;
		string filename_string;

		println("\nEnter Q To Quit..");
		println("\nPlease Enter The Terms You Would Like To Search, Separated By A Space...");
		getline(cin, query_string);

		if (query_string.size() == 1) chr = query_string.at(0);
		for (auto part : views::split(query_string, ' ')) {
			words_to_parse.push_back(string(part.begin(), part.end()));
		}

		println("\nThen Provide The Files You Would Like To Query...");
		getline(cin, filename_string);

		for (auto part : views::split(filename_string, ' ')) {
			file_names.push_back(string(part.begin(), part.end()));
		}

		break;
	}

	txtpar.process_request(words_to_parse, file_names);
	txtpar.display_results();

}

int main(int argc, char **argv) {
	std::cout << "Version " << TextParser_VERSION_MAJOR << "." << TextParser_VERSION_MINOR << std::endl;

	run_UI();

	return 0;
}

