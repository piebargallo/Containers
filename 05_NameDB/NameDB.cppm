/* From the profiling results of 29-3, it now looks like operator>> in the NameDB constructor is the 
   bottleenck. Can you change the implementation to avoid using operator>>? Since each line in the input 
   file contains one name, maybe it´s faster to simply read names line by line? Try to modify your 
   implementation as such and compare the profiling results before and after your changes. */

export module name_db;

import <stdexcept>;
import <fstream>;

import <string_view>;
import <string>;
import <unordered_map>;

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
	std::unordered_map<std::string, int> m_names;
};
