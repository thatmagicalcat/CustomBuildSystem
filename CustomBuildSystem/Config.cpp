#include "Config.h"

ConfigManager::ConfigManager(std::string file_name) {
	std::ifstream ifs(file_name);

	std::string data{
		std::istreambuf_iterator<char>(ifs),
		{}
	}; 

	ifs.close();

	json::json json_data = json::json::parse(data);

	try { switches._inc_    = json_data.at("inc");   } catch (std::exception&) { }
	try { switches._obj_    = json_data.at("obj");   } catch (std::exception&) { }
	try { switches._src_    = json_data.at("src");   } catch (std::exception&) { }
	try { switches._lang_v_ = json_data.at("langv"); } catch (std::exception&) { }
	try { switches._flags_  = json_data.at("flags"); } catch (std::exception&) { }
}

ConfigManager::ConfigManager() { }

auto ConfigManager::src() -> std::string {
	return switches._src_.value_or(std::filesystem::current_path().concat("\\src").string());
}

auto ConfigManager::obj() -> std::string {
	return switches._obj_.value_or(std::filesystem::current_path().concat("\\obj").string());
}

auto ConfigManager::inc() -> std::string {
	return switches._inc_.value_or(std::filesystem::current_path().concat("\\include").string());
}

auto ConfigManager::lang_v() -> std::string {
	return "-std=c++" + switches._lang_v_.value_or("17");
}

auto ConfigManager::flags() -> std::string {
	return switches._flags_.value_or("");
}
