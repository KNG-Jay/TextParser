/*
 * TPTests.cpp
 *
 *  Created on: Nov 1, 2025
 *      Author: kng
 */


#include <gtest/gtest.h>
#include "../include/TextParser.hpp"

TEST(TPTests, StopWordsRead) {
	TextParser txtpar = TextParser();
	const std::string stop_words = "../resources/assets/stop_words.txt";

	txtpar.get_stop_words(stop_words);
	println("Size Of Stop-Words: {}", txtpar.stop_words.size());

	ASSERT_TRUE(txtpar.stop_words.size() == 851);
	
}

TEST(TPTests, DocumentTokenized) {
	TextParser txtpar = TextParser();
	std::string stop_words = "../resources/assets/stop_words.txt";
	std::string file_name = "../resources/assets/UK_Infantry_Training_1905.txt.utf-8";

	vector<string> raw_tokens = txtpar.tokenize_document(file_name);
	println("Number Of Raw Tokens: {}", raw_tokens.size());

	txtpar.get_stop_words(stop_words);

	vector<string> tokens = txtpar.tokenize_document(file_name);
	println("Number Of Processed Tokens: {}", tokens.size());

	ASSERT_EQ(tokens.size(), 27553);

}

TEST(TPTests, TokensRooted) {
	TextParser txtpar = TextParser();
	std::string stop_words = "../resources/assets/stop_words.txt";
	std::string file_name = "../resources/assets/UK_Infantry_Training_1905.txt.utf-8";

	txtpar.get_stop_words(stop_words);

	vector<string> tokens = txtpar.tokenize_document(file_name);

	vector<string> rooted_tokens = txtpar.stem_tokens(tokens);

	println("tokens[5] == \"training\"");
	ASSERT_EQ(tokens[5], "training");
	ASSERT_EQ(rooted_tokens.size(), 27553);
	println("rooted_tokens[5] == \"train\"");
	ASSERT_EQ(rooted_tokens[5], "train");
	println("Unique Entries: {}", txtpar.main_token_set.size());
	ASSERT_EQ(txtpar.main_token_set.size(), 2579);

}

TEST(TPTests, ProccessRequest) {
	TextParser txtpar = TextParser();
	std::string stop_words = "../resources/assets/stop_words.txt";
	std::vector<std::string> query;
	std::vector<std::string> files;

	query.push_back("soldier");
	query.push_back("ally");
	query.push_back("weapon");
	query.push_back("water");
	query.push_back("boots");

	files.push_back("../resources/assets/UK_Infantry_Training_1905.txt.utf-8");
	files.push_back("../resources/assets/US_Army_Infantry_manual_1917.txt.utf-8");
	files.push_back("../resources/assets/US_AWC_Trench_Warfare_1917.txt.utf-8");
	files.push_back("../resources/assets/USMC_Pistol_Marksmanship.txt.utf-8");

	txtpar.process_request(query, files);

	string test_phrase = "water";
	println("Entries for '{}':", test_phrase);
	for (const auto& str : txtpar.inv_index[test_phrase]) {
		println("\tFile: {}\tCount: {}", str.first, str.second);
	}

	ASSERT_EQ(txtpar.inv_index.size(), 5);
	ASSERT_EQ(txtpar.inv_index["water"].size(), 4);
}

