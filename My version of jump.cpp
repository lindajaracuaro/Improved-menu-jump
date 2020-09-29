#include <cstdio>
#include <iostream>

const char * prompt();
int jump(const char*);

void opA()	{	puts("This is A\n");	}

void opB()
{
	puts("This is B\n");
}

void opC()
{
	puts("This is C\n");
}

void opD()
{
	puts("This is D\n");
}

void (*func[])() = { opA, opB, opC, opD };


int main()
{
	while (jump(prompt()));
	puts("Done.");

	return 0;
}

const char* prompt() {
	
	std::cout << "Select one option \n 1. Option A \n 2. Option B \n 3. Option C \n 4. Option D \n Enter Q to quit \t";
	fflush(stdout);                 // clearing the buffer and moving it to the console			//	flush after prompt

	const int buffsz = 16;          // Declaring size of the buffer to use						//	constant for buffer size
	static char response[buffsz];   // Declares the static storage for response buffer
	fgets(response, buffsz, stdin); // get response from console
	
	std::cout << std::endl;

	return response;
}

int jump(const char* response)
{
	char code = response[0];			//Takes just the first character
	code = toupper(code);

	if (code == 'Q')		return 0;

	int i = (int)code - '0';		//Converts const char to int just taking the first char


	if (i <= 0 || i > sizeof(*func))
{
		std::cout << "Invalid option, try again\n";
	return 1;
}
else
{
	(func[i - 1])();
	return 1;
}

}
