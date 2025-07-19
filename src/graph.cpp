#include "graph.hh"
#include <fstream>

void graph_write(const std::vector<Symbol>& symbols) {;
    std::ofstream out("symbols.json");
    
    for (const auto& s: symbols) {
        out << s.id << ',' << s.file << ',' << s.line << ',' << s.name << '\n';
    }
}