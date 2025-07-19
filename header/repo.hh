#pragma once
#include <cstdint>
#include <string>
#include <vector>

struct Repo {
    uint64_t id;
    std::string path;
};

std::string run_command(const std::string& cmd);
std::string get_head_sh(const std::string& repo_path);
std::vector<std::string> changed_files(const std::string& repo_path, const std::string& old_sh);