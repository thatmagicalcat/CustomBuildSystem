#pragma once

#ifndef GLOBAL_H
#define GLOBAL_H

#include <filesystem>
#include <chrono>
#include <unordered_map>
#include <string>

namespace fs = std::filesystem;

typedef std::chrono::system_clock::rep timePoint;
typedef std::unordered_map<std::string, timePoint> fmap;

#endif // !GLOBAL_H
