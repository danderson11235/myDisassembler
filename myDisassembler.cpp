// myDisassembler.cpp : Defines the entry point for the application.
//
#include "myDisassembler.h"
#include <cmath>

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
			if(!inf.is_open())
			{
				cout << "cant open the file\n";
				return 1;
			}
			cout << "file found\n";
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
		if(!inf.is_open())
		{
			cout << "cant open the file\n";
			return 1;
		}
		cout << "file found\n";
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

	string line;
	uint32_t inst, address;
	uint8_t rd, rt, rs, opcode, shamt, funct;
	uint16_t immideate;

	while(getline(inf, line))
	{
		inst = stobin(line);
		opcode = (uint8_t)(inst >> 26);
		
		switch (opcode)
		{
			case 0:
				/* code */
				break;
		
			default:
				break;
		}
	}
	

	inf.close();
	ouf.close();
	return 0;
}


uint32_t stobin(string in)
{
	int num[8];
	uint32_t out;
	for(int i = 0; i < 8; i++)
	{
		
		if (in[i] > '9') {
			in[i] = toupper(in[i]);
			num[i] = (int)(in[i] - 55);
		}
		else
		{
			num[i] = (int)(in[i] - '0');
		}		
		out += pow(16, 7 - i) * num[i];
	}
	
}