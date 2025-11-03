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
	std::string stop_words = "../resources/assets/stop_words.txt";

	txtpar.get_stop_words(stop_words);
	println("Size Of File: {}", txtpar.stop_words.size());
	ASSERT_TRUE(txtpar.stop_words.size() == 851);

}

