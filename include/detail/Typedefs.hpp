#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>

namespace FieldMath::detail 
{
    // Scalar typedef
    typedef double scalar;

    // Dynamic Eigen typedefs
    typedef Eigen::Matrix<scalar, -1,  1> VectorX;
    typedef Eigen::Matrix<scalar,  1, -1> RowVectorX;
    typedef Eigen::Matrix<scalar, -1, -1> MatrixX;

    // 3D Eigen typedefs
    typedef Eigen::Matrix<scalar, 3, 1> Vector3;
    typedef Eigen::Matrix<scalar, 1, 3> RowVector3;
    typedef Eigen::Matrix<scalar, 3, 3> Matrix3;
}