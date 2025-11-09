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
#include <english_stem.h>

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

	void get_stop_words(const string& stp_wrd_filename);
	vector<string> tokenize_document(const string& filepath);
	vector<string> stem_tokens(const vector<string>& tokens_vec);
	// ADD REFERENCE TO WHERE WORD IS FIRST FOUND, PLUS FREQUENCY
	void get_info();
	// QUERY A LIST OF FILES FOR CERTAIN WORDS REQUESTED
	void process_request(const vector<string>& words_to_parse, const vector<string>& file_names);

private:


};


#endif /* INCLUDE_TEXTPARSER_HPP_ */
