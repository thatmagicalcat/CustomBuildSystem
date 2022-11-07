#pragma once

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>
#include <optional>
#include <filesystem>

#include "json.hpp"

#define switch_ std::optional<std::string>
namespace json = nlohmann;

class ConfigManager {
private:
	struct _switches {
		switch_ _src_;
		switch_ _obj_;
		switch_ _inc_;
		switch_ _flags_;
		switch_ _lang_v_;
	};

	_switches switches;

public:
	ConfigManager(std::string file_name);
	ConfigManager();

public:
	auto src() -> std::string;
	auto obj() -> std::string;
	auto inc() -> std::string;
	auto lang_v() -> std::string;
	auto flags() -> std::string;
};

#endif // !CONFIG_H
