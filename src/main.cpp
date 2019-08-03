#include "../include/pca.hpp"

int main(int argc, const char** argv) {
    AMWPHI001::Analyser analysis;
    AMWPHI001::Analyser::vectorPair xd = analysis.readFile(argv[1]);
    analysis.computeEigenValues(xd);
    return 0;
}
