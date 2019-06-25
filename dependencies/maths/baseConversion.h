#pragma once
#include <iostream>
class baseConversion
{
public:
	baseConversion();
	~baseConversion();
	// converts a string of 1's and 0's into an integer
	static int binaryStringToInteger(const char* aBinaryString);
	// converts an integer into string of 1's and 0's 
	//desitination char*
	//the char* should be sizeof(int) * 8 + 1 bytes long
	static void integerToBinaryString(char* aBinaryString, int value);
	// sets the bit at the given index to the passed state
	// the bitField to edit by reference
	// the index of the bit to change
	// the desired state of the bit at teh index
	static void setBit(int& aBitField, char aBitIndex, bool aState);
	// reads the bit at the given index to the passed state
		// the bitField read only to chech
		// the index of the bit to check
		// return the current state of the bit at the index
	static bool getBit(const int aBitField, char aBitIndex);

	//prints the integer as a binary number
	//uses the iostream to print the converted binary number into the display
	static void printIntAsBinary(const int a_bit_field, bool space = false);
};

