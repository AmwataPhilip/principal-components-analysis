#ifndef PCA_HPP
#define PCA_HPP

#include <cstdio>
#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include "Eigen/Core"
#include "Eigen/LU"
#include "Eigen/Cholesky"
#include "Eigen/QR"
#include "Eigen/SVD"
#include "Eigen/Geometry"
#include "Eigen/Eigenvalues"

namespace AMWPHI001
{
using namespace std;
using namespace Eigen;

class Analyser
{
private:
    /* data */
    pair<float, float> eigenValues;
    pair<float, float> eigenVectors;
    MatrixXf covarianceMatrix;
    float proportion1;
    float proportion2;

public:
    Analyser();
    ~Analyser();

    typedef std::pair<vector<float>, vector<float>> vectorPair;

    MatrixX2f readFile(string fileName);
    void eigenSolve(SelfAdjointEigenSolver<MatrixXf> eigenSolver, MatrixX2f initialMatrix);
    void computeCovarianceMatrix(MatrixXf initMat);
    void computeTotalVariance();
    void computeVarianceProportions();
    void startPCS(string fname);
};
}; // namespace AMWPHI001

#endif // !PCA_HPP
