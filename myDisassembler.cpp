// myDisassembler.cpp : Defines the entry point for the application.
//
#include "myDisassembler.h"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream inf;
	ofstream ouf;
	if (argc != 2)
	{
		cout << "it seems you didn't include the file when calling this program.\n";
		cout << "you may either run this again as myDisassembler *.obj\n";
		cout << "alternitivly you may type the file name here or e to exit\n";
		char answer[30];
		cin >> answer;
		if (answer == "e")
		{
			return 0;
		}
		else
		{
			inf.open(answer, ios::in);
			char output[30];
			strcpy(output, answer);
			char* end = strchr(output, '.');
			end++;
			*(end + 1) = 's';
			end++;
			while (*end != 0)
			{
				*end = 0;
				end++;
			}
			ouf.open(output, ios::out | ios::trunc);
		}
	}
	else
	{
		inf.open(argv[1], ios::in);
		char output[30];
		strcpy(output, argv[1]);
		char* end = strchr(output, '.');
		end++;
		*(end + 1) = 's';
		end++;
		while (*end != 0)
		{
			*end = 0;
			end++;
		}
		ouf.open(output, ios::out | ios::trunc);
	}



	inf.close();
	ouf.close();
	return 0;
}
