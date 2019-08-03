#ifndef PCA_HPP
#define PCA_HPP

#include <cstdio>
#include <iostream>
#include <utility>
#include "Eigen/Core"
#include "Eigen/LU"
#include "Eigen/Cholesky"
#include "Eigen/QR"
#include "Eigen/SVD"
#include "Eigen/Geometry"
#include "Eigen/Eigenvalues"

using namespace std;
using namespace Eigen;

class pca
{
private:
    /* data */
    pair<float, float> eigenValues;
    pair<float, float> eigenVectors;
    Matrix2f covarianceMatrix;
    float proportion1;
    float proportion2;

public:
    pca(/* args */);
    ~pca();
    void readFile();
    void computeEigenValues();
    void computeEigenVectors();
    void computeCovarianceMatrix();
    void computeTotalVariance();
    void computeVarianceProportions();
    void startPCS();
};

#endif // !PCA_HPP
