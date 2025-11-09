/*
 * TextParser.cpp
 *
 *  Created on: Oct 31, 2025
 *      Author: kng
 */


#include "../include/TextParser.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <print>
#include <algorithm>
#include <regex>

using namespace std;


TextParser::TextParser() {}
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

string get_root_word(const string& str) {
	stemming::english_stem<> stemmer;
	wstring wstr(str.begin(), str.end());

	stemmer(wstr);
	string root_word(wstr.begin(), wstr.end());

	return root_word;
}

vector<string> TextParser::stem_tokens(const vector<string>& tokens_vec) {
	vector<string> root_words;
	root_words.reserve(tokens_vec.size());

	ranges::transform(tokens_vec, back_inserter(root_words), get_root_word);

	main_token_set.insert(root_words.begin(), root_words.end());

	return root_words;
}

// TODO: ( IMPLEMENT EXCEPTION HANDLING!!! )
void TextParser::process_request(const vector<string>& words_to_parse, const vector<string>& file_names) {
	string stp_wrds_file = "../resources/assets/stop_words.txt";
	unordered_map<string, vector<string>> tokens;
	regex pattern(".*?/|\\..*");

	get_stop_words(stp_wrds_file);

	for (const auto& str : file_names) {
    	string result = std::regex_replace(str, pattern, "");

		tokens[result] = stem_tokens(tokenize_document(str));
	}

	for (const auto& word : words_to_parse) {
		for (const auto& file : file_names) {
			string result = std::regex_replace(file, pattern, "");
			int word_count = std::count(tokens[result].begin(), tokens[result].end(), word);

			inv_index[word][result] = word_count;
		}
	}

	println("\n\nRequest Processed Successfully!\n\n");
}

void TextParser::display_results() {
	println("Results Of Query:\n");
	for (const auto& word : inv_index) {
		println("\tEntries For {}:", word.first);
		for (const auto& ent : inv_index[word.first]) {
			println("\t\tFile: {}\tCount: {}", ent.first, ent.second);
		}
	}
	println("\n");
}
