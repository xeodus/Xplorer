#include <cstdint>
#include <string>
#include <vector>

struct Symbol {
    uint64_t id;
    std::string name;
    std::string file;
    uint64_t line;
};

std::vector<Symbol> parse_file(const std::string& file);