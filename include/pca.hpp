#ifndef PCA_HPP
#define PCA_HPP

#include <cstdio>
#include <iostream>
#include <utility>
#include <fstream>
#include <string>
#include <vector>
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
    Matrix2f covarianceMatrix;
    float proportion1;
    float proportion2;

public:
    Analyser();
    ~Analyser();
    vector readFile(string fileName);
    void computeEigenValues();
    void computeEigenVectors();
    void computeCovarianceMatrix();
    void computeTotalVariance();
    void computeVarianceProportions();
    void startPCS();
};
}; // namespace AMWPHI001

#endif // !PCA_HPP
