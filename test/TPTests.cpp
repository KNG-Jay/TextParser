/*
 * TPTests.cpp
 *
 *  Created on: Nov 1, 2025
 *      Author: kng
 */


#include <gtest/gtest.h>
#include "../include/TextParser.hpp"

TEST(TPTests, StopWordsFileRead) {
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

	txtpar.get_stop_words(stop_words);

	vector<string> tokens = txtpar.tokenize_document(txtpar.file_names.front());
	println("Number Of Tokens In: {}", tokens.size());

	ASSERT_TRUE(tokens.size() == 62646);

}

