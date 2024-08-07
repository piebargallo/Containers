import <stdexcept>;
import <fstream>;

export module name_db;

import <string_view>;
import <string>;
import <vector>;
import <utility>;

export class NameDB
{
public:
	// Reads list of baby names in nameFile to populate the database.
	// throws invalid_argument if nameFile cannot be opened or read.
	NameDB(std::string_view nameFile);

	// Returns the rank of the name (1st, 2nd, etc).
	// Returns -1 if the name is not found.
	int getNameRank(std::string_view name) const;

	// Returns the number of babies with a given name.
	// returns -1 if the name is not found.
	int getAbsoluteNumber(std::string_view name) const;

private:
	std::vector<std::pair<std::string, int>> m_names;

	// Helper methods
	bool nameExists(std::string_view name) const;
	void incrementNameCount(std::string_view name);
	void addNewName(std::string_view name);
};