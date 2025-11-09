/*
 * TextParser.hpp
 *
 *  Created on: Oct 31, 2025
 *      Author: kng
 */

#ifndef INCLUDE_TEXTPARSER_HPP_
#define INCLUDE_TEXTPARSER_HPP_


#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <english_stem.h>

using namespace std;

class TextParser {
public:
	TextParser();
	~TextParser();

	vector<string> stop_words;
	unordered_set<string> main_token_set;
	unordered_map<string, unordered_map<string, int>> inv_index;

	void get_stop_words(const string& stp_wrd_filename);
	vector<string> tokenize_document(const string& filepath);
	vector<string> stem_tokens(const vector<string>& tokens_vec);
	void process_request(const vector<string>& words_to_parse, const vector<string>& file_names);

private:

};


#endif /* INCLUDE_TEXTPARSER_HPP_ */
