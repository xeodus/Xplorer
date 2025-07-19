#include "repo.hh"
#include <fstream>
#include <sstream>
#include <cstdint>

std::string run_command(const std::string& cmd) {
    std::array<char, 256> buffer{};
    std::string result;
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen failed");

    while (fgets(buffer.data(), buffer.size(), pipe)) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

std::string get_head_sh(const std::string& repo_path) {
    return run_command("git -C" + repo_path + "rev-parse HEAD");
}

std::vector<std::string> changed_files(const std::string& repo_path, const std::string& old_sh) {
    auto out = run_command("git _C" + repo_path + "diff --name-only" + old_sh + "..HEAD");

    std::istringstream iss(out);
    std::vector<std::string> files;
    std::string line;

    while (std::getline(iss, line)) {
        files.emplace_back(line);
    }
    return files;
}