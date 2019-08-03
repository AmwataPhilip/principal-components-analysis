#include "../include/pca.hpp"

int main(int argc, const char** argv) {
    AMWPHI001::Analyser analysis;
    analysis.readFile(argv[1]);
    return 0;
}
