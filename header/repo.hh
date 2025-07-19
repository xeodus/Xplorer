#pragma once
#include <cstdint>
#include <string>
#include <expected>
#include <vector>

struct Repo {
    uint64_t id;
    std::string path;
};

std::expected<Repo, std::string> clone(std::string_view url);
std::vector<std::string> diff(Repo& r, std::string_view old_sh);