#include "vector.hh"
#include <fstream>

void vector_index(const std::vector<Symbol>& symbol) {
    std::ofstream out("embeddings.json");

    for (const auto& s: symbol) {
        out << s.id << ',' << "\"placeholder\"\n";
    }
}