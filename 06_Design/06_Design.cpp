/* Read from a file. */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile{ "FileWrite.out" };
	if (inputFile.fail()) {
		cerr << "Unable to open file for reading." << endl;
		return 1;
	}

	string nextToken;
	while (inputFile >> nextToken) {
		cout << "Token: " << nextToken << endl;
	}
}