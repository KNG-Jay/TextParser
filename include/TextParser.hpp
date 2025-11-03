/*
 * TextParser.hpp
 *
 *  Created on: Oct 31, 2025
 *      Author: kng
 */

#ifndef INCLUDE_TEXTPARSER_HPP_
#define INCLUDE_TEXTPARSER_HPP_


#include <fstream>
#include <iostream>
#include <stdexcept>
#include <print>
#include <string>
#include <vector>

using namespace std;

class TextParser {
public:
	TextParser();
	TextParser(
		vector<string> words_to_parse,
		vector<string> files_to_parse);
	~TextParser();

	vector<string> stop_words;
	vector<string> words_to_parse;
	vector<string> files_to_parse;

	void get_stop_words(string stp_wrd_filename);

private:
	
};


#endif /* INCLUDE_TEXTPARSER_HPP_ */
