#include "../include/pca.hpp"

using namespace AMWPHI001;

vector<float> Analyser::computeCovarianceMatrix(vector<float> januaryData, vector<float> julyData)
{
    float mean1 = accumulate(januaryData.begin(), januaryData.end(), 0.0f) / float(januaryData.size());
    float mean2 = accumulate(julyData.begin(), julyData.end(), 0.0f) / float(julyData.size());
    float cov1 = 0.0f, cov2 = 0.0f, cov3 = 0.0f;
    for (int n = 0; n < januaryData.size(); n++)
    {
        januaryData[n] -= mean1;
        julyData[n] -= mean2;
        cov1 += januaryData[n] * januaryData[n];
        cov2 += januaryData[n] * julyData[n];
        cov3 += julyData[n] * julyData[n];
    }
    cov1 /= float(januaryData.size() - 1);
    cov2 /= float(januaryData.size() - 1);
    cov3 /= float(januaryData.size() - 1);
    vector<float> covValues{cov1, cov2, cov3};
    return covValues;
}

MatrixX2f Analyser::readFile(string fileName)
{
    string relativePath = "src/" + fileName;
    std::cout << "Reading File: " << fileName << std::endl;
    std::cout << "Relative Path: " << relativePath << std::endl;

    ifstream infile; // File Pointer

    // Open an existing file
    infile.open(relativePath, ios::in);

    vector<string> row, cols;            // Row stores lines and cols stores each cell
    vector<float> januaryData, julyData; // Store the data for each month
    Matrix2f covMatrix;                  // Store covariances and variance
    vector<float> covVector;
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

    for (int c = 0; c < cols.size(); c++)
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
    covVector = computeCovarianceMatrix(januaryData, julyData);

    covMatrix << covVector[0], covVector[1], covVector[1], covVector[2];

    std::cout << "Covariance Matrix: " << std::endl
              << covMatrix << std::endl
              << std::endl;
    computeTotalVariance(covVector);
    computeVarianceProportions(covVector);
    return covMatrix;
}

void Analyser::eigenSolve(MatrixX2f initialMatrix)
{
    EigenSolver<MatrixXf> eigenSolver(initialMatrix);
    if (eigenSolver.info() != Success)
        abort();
    std::cout << "Eigenvalues: " << std::endl
              << eigenSolver.eigenvalues() << std::endl
              << std::endl;
    std::cout << "Eigenvectors: " << std::endl
              << eigenSolver.eigenvectors() << std::endl
              << std::endl;
}

void Analyser::computeTotalVariance(vector<float> x)
{
    std::cout << "Total Variance: " << std::endl
              << x[0] + x[2] << std::endl
              << std::endl;
}
void Analyser::computeVarianceProportions(vector<float> y)
{
    float pc1, pc2;
    pc1 = (y[0] / (y[0] + y[2])) * 100;
    pc2 = (y[2] / (y[0] + y[2])) * 100;
    std::cout << "Variance Proportions: " << std::endl
              << "PC1: " << pc1 << "%" << std::endl
              << "PC2: " << pc2 << "%" << std::endl
              << std::endl;
}
void Analyser::startPCS(string fname, Analyser pca)
{
    try
    {
        std::cout << "Starting PCA Analysis of data-sets." << std::endl;
        MatrixX2f initMat = pca.readFile(fname);
        pca.eigenSolve(initMat);

        std::cout << "PCA analysis complete." << std::endl;
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
