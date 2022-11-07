#include "utils.h"

auto Tools::split(std::string sv, char delim) -> std::vector<std::string> {
	size_t pos; if ((pos = sv.find(delim)) == sv.npos) return std::vector<std::string> {  };

	std::vector<std::string> res;
	do {
		if (pos)
			res.push_back(sv.substr(0, pos));
		sv = sv.substr(pos + 1);
	} while ((pos = sv.find(delim)) != sv.npos);
	res.push_back(sv);
	return res;
}
