#include "parser.hh"
#include <fstream>

std::vector<Symbol> parse_file(const std::string& file) {
    std::vector<Symbol> output;
    std::string line;
    uint64_t line_no = 1;
    std::ifstream f(file);

    while (std::getline(f, line)) {
        if ((line.find("int") != std::string::npos)
            || line.find("void") != std::string::npos) 
        {
            Symbol s;
            s.id = std::hash<std::string>{} (file + std::to_string(line_no));
            s.name = line.substr(0, line.find(""));
            s.file = file;
            s.line = line_no;
            output.push_back(s);
        }
        line_no++;
    }
    return output;
}