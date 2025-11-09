/*
 * TextParser.cpp
 *
 *  Created on: Oct 31, 2025
 *      Author: kng
 */


#include "../include/TextParser.hpp"

using namespace std;


TextParser::TextParser() {}

TextParser::TextParser(vector<string> words_to_parse, vector<string> file_names) :
	words_to_parse(words_to_parse),
	file_names(file_names) {}

TextParser::~TextParser() {}


void TextParser::get_stop_words(const string& stp_wrd_filename) {
	try {
		ifstream file(stp_wrd_filename);
		string str;
	
		if (!file.is_open()) {
            cout << "Failed To Open " << stp_wrd_filename << endl;
            return;
        }

        while (getline(file, str)) {
            str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end());
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            stop_words.push_back(str);
        }

        file.close();
	} catch (const exception& e) {
		cerr << "ERROR: " << e.what() << endl;
	}
}

vector<string> TextParser::tokenize_document(const string& filepath) {
	unordered_set<string> stop_set(stop_words.begin(), stop_words.end());
	vector<string> tokens;

	ifstream file(filepath);
	if (!file) {
		throw runtime_error("Cannot Open File: " + filepath);
	}

	string line;
	while (getline(file, line)) {
		istringstream lineStream(line);
		string word;

		while (lineStream >> word) {
			word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
			transform(word.begin(), word.end(), word.begin(), ::tolower);

			if (!stop_set.count(word) && !word.empty()) {
				tokens.push_back(word);
			}
		}
	}

	return tokens;
}

string root_word(const string& str) {
	stemming::english_stem<> stemmer;
	wstring wstr(str.begin(), str.end());

	stemmer(wstr);
	string root_word(wstr.begin(), wstr.end());

	return root_word;
}

vector<string> TextParser::stem_tokens(const vector<string>& tokens_vec) {
	vector<string> root_words;
	root_words.reserve(tokens_vec.size());

	ranges::transform(tokens_vec, back_inserter(root_words), root_word);

	return root_words;
}

void TextParser::get_info() {

}
