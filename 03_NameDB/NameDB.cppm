export module NameDB;

import <stdexcept>;
import <fstream>;
import <string_view>;
import <string>;
import <map>;

export class NameDB
{
public:
	// Reads list of baby names in nameFile to populate the database.
	// Throws invalid_argument if nameFile cannot be opened or read.
	NameDB(std::string_view nameFile);

	// Returns the rank of the name (1st, 2nd, etc).
	// Returns -1 if the name is not found.
	int getNameRank(std::string_view name) const;

	// Returns the number of babies with a given name.
	// Returns -1 if the name is not found.
	int getAbsoluteNumber(std::string_view name) const;

private:
	std::map<std::string, int> m_names;
};
