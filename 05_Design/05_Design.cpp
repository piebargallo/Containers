/* Write to a file. */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream outputFile{ "FileWrite.out" };
	if (outputFile.fail()) {
		cerr << "Unable to open file for writing." << endl;
		return 1;
	}
	outputFile << "Hello!" << endl;
	outputFile.close();

	ofstream appendFile{ "FileWrite.out", ios_base::app };
	if (appendFile.fail()) {
		cerr << "Unable to open file for appening." << endl;
	}
	appendFile << "World!" << endl;
}