#include "repo.hh"
#include <filesystem>

std::expected<Repo, std::string> clone(std::string_view url) {
    uint64_t id = std::hash<std::string>{} (std::string(url));
    //std::string path = fmt::filesystem("/tmp/repos/{}", id);

}