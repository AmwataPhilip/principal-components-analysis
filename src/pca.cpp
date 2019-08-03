#include "../include/pca.hpp"

using namespace AMWPHI001;

void pca::readFile(const char *fileName)
{
    cout << "Reading File: " << fileName << endl;

    ifstream infile; // File Pointer

    // Open an existing file
    infile.open(fileName, ios::in);

    vector<string> row;                  // Stores earch cell in a line
    vector<float> januaryData, julyData; // Store the data for each month
    string line, word, temp;

    while (infile >> temp)
    {
        // Empyt out the vector
        row.clear();

        for (int i = 0; i < 2; i++)
        {
            infile.ignore(256, '\n');
        }

        // Read an entire row and store in a string line
        getline(infile, line);

        stringstream s(line); // Used to split words in a line

        // Read every column data of a row and store in a string word
        while (getline(s, word, ';'))
        {
            cout << line << endl;
            // Add all column data of a row to the vector
            row.push_back(word);
            januaryData.push_back(stof(row[1]));
            julyData.push_back(stof(row[2]));
        }

        cout << "Done Reading File: " << fileName << endl;
    }
}
void pca::computeEigenValues() {}
void pca::computeEigenVectors() {}
void pca::computeCovarianceMatrix() {}
void pca::computeTotalVariance() {}
void pca::computeVarianceProportions() {}
void pca::startPCS() {}
