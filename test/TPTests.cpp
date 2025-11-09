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
	txtpar.file_names.push_back("../resources/assets/UK_Infantry_Training_1905.txt.utf-8");

	vector<string> raw_tokens = txtpar.tokenize_document(txtpar.file_names.front());
	println("Number Of Raw Tokens: {}", raw_tokens.size());

	txtpar.get_stop_words(stop_words);

	vector<string> tokens = txtpar.tokenize_document(txtpar.file_names.front());
	println("Number Of Processed Tokens: {}", tokens.size());

	ASSERT_EQ(tokens.size(), 27553);

}

TEST(TPTests, TokensRooted) {
	TextParser txtpar = TextParser();
	std::string stop_words = "../resources/assets/stop_words.txt";
	txtpar.file_names.push_back("../resources/assets/UK_Infantry_Training_1905.txt.utf-8");

	txtpar.get_stop_words(stop_words);

	vector<string> tokens = txtpar.tokenize_document(txtpar.file_names.front());

	vector<string> rooted_tokens = txtpar.stem_tokens(tokens);

	println("tokens[5] == \"training\"");
	ASSERT_EQ(tokens[5], "training");
	ASSERT_EQ(rooted_tokens.size(), 27553);
	println("rooted_tokens[5] == \"train\"");
	ASSERT_EQ(rooted_tokens[5], "train");

}

