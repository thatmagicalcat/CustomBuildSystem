#include "FileSystemManager.h"

FileSystemManager::FileSystemManager(fs::path path):
	_path(path) {
}

auto FileSystemManager::get_write_time() -> fmap {
	std::unordered_map<std::string, timePoint> map;
	if (fs::is_directory(_path)) {
		for (
			fs::directory_entry file :
			fs::directory_iterator(fs::current_path().concat("\\test_src"))
		) map[file.path().string()] = file.last_write_time()
											.time_since_epoch()
											.count();
		return map;
	} else { 
		map[_path.string()] = fs::last_write_time(_path).time_since_epoch().count();
		return map;
	}
}
