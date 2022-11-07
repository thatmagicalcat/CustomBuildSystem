#pragma once

#include <string>
#include <cstring>
#include <fstream>
#include <unordered_map>
#include <chrono>
#include <filesystem>

#include "Global.h"

class DataManager {
private:
	std::string _data_file;

public:
	DataManager(std::string data_file);

public:
	auto set(fmap data) -> void;
	auto get() -> fmap;
};
