#include "../include/pca.hpp"

using namespace AMWPHI001;

vector Analyser::readFile(string fileName)
{
    string relativePath = "src/" + fileName;
    cout << "Reading File: " << fileName << endl;
    cout << "Relative Path: " << relativePath << endl;

    ifstream infile; // File Pointer

    // Open an existing file
    infile.open(relativePath, ios::in);

    vector<string> row, cols;            // Row stores lines and cols stores each cell
    vector<float> januaryData, julyData; // Store the data for each month
    vector<vector> datePoints; // Store januaryData and julyData
    string line, word, temp;
    int sum = 0;

    while (!infile.eof())
    {
        getline(infile, line);
        // Read an entire row and store in a string line
        row.push_back(line);
    }
    row.pop_back();
    for(auto& x: row){
        stringstream s(x);// Used to split words in a line
        // Read every column data of a row and store in a string word
        while(getline(s, word, ';')){
            // Add all column data of a row to the vector
            cols.push_back(word);
        }
    }
    for(int c = 0; c != cols.size()-1; c++){
        if(c%2 == 0){
            januaryData.push_back(cols[c]);
        }else{
            julyData.pus_back(cols[c]);
        }
    }
}
void Analyser::computeEigenValues() {}
void Analyser::computeEigenVectors() {}
void Analyser::computeCovarianceMatrix() {}
void Analyser::computeTotalVariance() {}
void Analyser::computeVarianceProportions() {}
void Analyser::startPCS() {}

Analyser::Analyser()
{
}

Analyser::~Analyser()
{
}