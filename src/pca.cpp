#include "../include/pca.hpp"

using namespace AMWPHI001;

MatrixX2f Analyser::readFile(string fileName)
{
    string relativePath = "src/" + fileName;
    cout << "Reading File: " << fileName << endl;
    cout << "Relative Path: " << relativePath << endl;

    ifstream infile; // File Pointer

    // Open an existing file
    infile.open(relativePath, ios::in);

    vector<string> row, cols;            // Row stores lines and cols stores each cell
    vector<float> januaryData, julyData; // Store the data for each month
    MatrixX2f initialMatrix;             // Store with 2 vectors and their 64 observations
    string line, word, temp;
    int sum = 0;

    while (!infile.eof())
    {
        getline(infile, line);
        // Read an entire row and store in a string line
        row.push_back(line);
    }
    row.pop_back();
    for (auto &x : row)
    {
        stringstream s(x); // Used to split words in a line
        // Read every column data of a row and store in a string word
        while (getline(s, word, ';'))
        {
            // Add all column data of a row to the vector
            cols.push_back(word);
        }
    }

    for (int c = 0; c != cols.size() - 1; c++)
    {
        if (c % 2 == 0)
        {
            januaryData.push_back(stof(cols[c]));
        }
        else
        {
            julyData.push_back(stof(cols[c]));
        }
    }

    for (int n = 0; n < januaryData.size(); n++)
    {
        initialMatrix(n, 0) = januaryData[n];
        initialMatrix(n, 1) = julyData[n];
    }

    return initialMatrix;
}
void Analyser::computeCovarianceMatrix(MatrixXf intiMat)
{
}
void Analyser::eigenSolve(SelfAdjointEigenSolver<MatrixXf> eigenSolver, MatrixX2f initialMatrix)
{
    eigenSolver.computeDirect(initialMatrix);

    cout << "Eigenvalues: " << endl
         << eigenSolver.eigenvalues << endl;
    cout << "Eigenvectors: " << endl
         << eigenSolver.eigenvectors << endl;
}

void Analyser::computeTotalVariance() {}
void Analyser::computeVarianceProportions() {}
void Analyser::startPCS(string fname)
{
    Analyser::Analyser pca;
    SelfAdjointEigenSolver<MatrixXf> eigenSolver;
    try
    {
        cout << "Starting PCA Analysis of data-sets." << endl;
        MatrixX2f initMat = pca.readFile(fname);
        pca.eigenSolve(eigenSolver, initMat);

        cout << "PCA analysis complete." << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

Analyser::Analyser()
{
}

Analyser::~Analyser()
{
}
