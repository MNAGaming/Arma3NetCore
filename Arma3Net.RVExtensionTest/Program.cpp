#include <iostream>
#include <string>
#include "..\Arma3Net\RVExtension.h"

#define OUTPUT_SIZE 4096

int main(void)
{
	while (true)
	{
		std::string functionString;
		std::cout << "Enter function name \"DateTime now\": ";
		std::getline(std::cin, functionString);
		if (functionString.length() == 0)
			continue;

		const char* function = functionString.c_str();
		char output[OUTPUT_SIZE] = { 0 };
		RVExtension(output, OUTPUT_SIZE, function);

		std::cout << output << std::endl;
	}
}