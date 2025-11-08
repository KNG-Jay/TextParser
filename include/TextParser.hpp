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
#include <sstream>
#include <stdexcept>
#include <print>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class TextParser {
public:
	TextParser();
	TextParser(
		vector<string> words_to_parse,
		vector<string> files_to_parse
	);
	~TextParser();

	vector<string> stop_words;
	vector<string> words_to_parse;
	vector<string> file_names;

	void get_stop_words(string stp_wrd_filename);
	// TOKENIZE DOCUMENT, MINUS "STOP WORDS"
	vector<string> tokenize_document(const string& filepath, const vector<string>& stop_words);
	// STEM ROOT OF WORDS
	vector<string> stem_roots(vector<string> token_vec);
	// ADD REFERENCE TO WHERE WORD IS FIRST FOUND, PLUS FREQUENCY
	void process_request(vector<string> words_to_parse, vector<string> file_names);

private:


};


#endif /* INCLUDE_TEXTPARSER_HPP_ */
