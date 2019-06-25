#include "baseConversion.h"



baseConversion::baseConversion()
{
}


baseConversion::~baseConversion()
{
}


int  baseConversion::binaryStringToInteger(const char* aBinaryString)
{
	int bitField = 0;
	int stringLength = strlen(aBinaryString);

	for (size_t i = 0; i < stringLength; i++)
	{
		if (aBinaryString[i] == '1')
		{
			setBit(bitField, stringLength - i - 1, true);
		}
	}

	return bitField;
}

void baseConversion::integerToBinaryString(char* aBinaryString, int value)
{
	aBinaryString[32] = '\0';
	for (size_t i = 0; i < 32; i++)
	{
		aBinaryString[31 - i] = getBit(value, i) ? '1' : '0';
	}
}

void baseConversion::setBit(int& aBitField, char aBitIndex, bool aState)
{
	if (aState)// shift OR = on
	{
		aBitField = aBitField | (1 << aBitIndex);
	}
	else // shift flip AND = off
	{
		aBitField = aBitField& ~(1 << aBitIndex);
	}
}

bool baseConversion::getBit(const int aBitField, char aBitIndex)
{
	return bool(aBitField & (1 << aBitIndex));
}

void baseConversion::printIntAsBinary(const int a_bit_field, bool space /*= false*/)
{
	for (int i = 31; i >= 0; i--)
	{
		std::cout << baseConversion::getBit(a_bit_field, i);
		if (i % 4 == 0 && space)
		{
			std::cout << " ";
		}
	}
	std::cout << "\n";
}