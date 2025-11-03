/*
 * TextParser.cpp
 *
 *  Created on: Oct 31, 2025
 *      Author: kng
 */


#include "../include/TextParser.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


TextParser::TextParser() {}

TextParser::TextParser(vector<string> words_to_parse, vector<string> files_to_parse) :
	words_to_parse(words_to_parse),
	files_to_parse(files_to_parse) {}

TextParser::~TextParser() {}


void TextParser::get_stop_words(string stp_wrd_filename) {
	try {
		ifstream file(stp_wrd_filename);
		string str;
	
		if (!file.is_open())
			cout << "Failed To Open " << stp_wrd_filename << endl;
		else {
			while (getline(file, str)) {
				TextParser::stop_words.push_back(str);
			}
		
			file.close();
		}
	} catch (const exception& e) {
		cerr << "ERROR: " << e.what() << endl;
	}
}

