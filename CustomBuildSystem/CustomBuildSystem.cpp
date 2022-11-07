#include <iostream>

#include "Global.h"
#include "Config.h"
#include "DataManager.h"
#include "FileSystemManager.h"

constexpr auto DATAFILE = ".data";

namespace Managers {
	DataManager mgr(DATAFILE);
	FileSystemManager fsm(fs::current_path().concat("\\test_src"));
	
	ConfigManager cfg("config.json");
}

auto main() -> int {
	bool file_changed = 0;
	auto process_file = [&](const std::string &file_name, const timePoint& write_time) {
		file_changed = 1;
		std::string cmd = "g++ " + Managers::cfg.lang_v() + Managers::cfg.flags() + " -I " + Managers::cfg.inc() + " -c " + fs::path(Managers::cfg.src() + "\\").concat(fs::path(file_name).filename().string()).string() + " -o " + Managers::cfg.obj() + "\\" + fs::path(file_name).filename().replace_extension(".o").string();
		std::cout << cmd << '\n';
		system(cmd.c_str());
	};

	fmap map;
	if (!fs::exists(DATAFILE)) { 
		Managers::mgr.set((map = Managers::fsm.get_write_time()));
		for (auto& [file, write_time] : map) process_file(file, write_time);
		return 0;
	} else {
		map = Managers::mgr.get();
		fmap current_map = Managers::fsm.get_write_time();

		for (auto& [file, write_time] : current_map) {
			if (map.find(file) == map.end()) process_file(file, write_time);
			else if (map[file] < current_map[file]) process_file(file, write_time);
		}

		Managers::mgr.set(current_map);
	}

	if (file_changed) {
		std::string cmd = "g++ " + Managers::cfg.lang_v() + ' ' + Managers::cfg.flags() + ' ' + Managers::cfg.obj() + "\\* -o bin\\main.exe";
		std::cout << cmd << '\n';
		system(cmd.c_str());
	} else std::cout << "Nothing to build\n";
}
