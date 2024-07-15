export module NameDB;

import <fstream>;
import <stdexcept>;
import <string_view>;
import <string>;
import <map>;

export class NameDB
{
public:
	NameDB(std::string_view nameFile);
	int getNameRank(std::string_view name) const;
	int getAbsoluteNumber(std::string_view name) const;
private:
	std::map<std::string, int> m_names;
	bool nameExistsAndIncrement(std::string_view name);
	void addNewName(std::string_view name);
};