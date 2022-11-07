#include "DataManager.h"

DataManager::DataManager(std::string data_file) :
	_data_file(data_file) {
}

auto DataManager::set(fmap data) -> void {
	std::ofstream out(_data_file);
	
	for (auto& [file_name, write_time] : data)
		out << file_name << " = " << write_time << '\n';

	out.close();
}

auto DataManager::get() -> fmap {
	std::ifstream in(_data_file);
	std::string str;
	fmap map;

	while (std::getline(in, str)) 
		map[str.substr(0u, str.find(" ="))] = stoll(str.substr(str.find("= ") + 2, str.size()));

	return map;
}
