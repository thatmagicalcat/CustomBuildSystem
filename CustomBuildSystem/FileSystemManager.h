#pragma once

#include <filesystem>
#include <optional>
#include <unordered_map>
#include <string>
#include <chrono>
#include <regex>

#include "Global.h"

class FileSystemManager {
private:
	fs::path _path;

public:
	FileSystemManager(fs::path path);

public:
	auto get_write_time() -> fmap;
};
