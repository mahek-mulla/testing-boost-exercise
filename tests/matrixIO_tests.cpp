#define BOOST_TEST_DYN_LINK

#include <Eigen/Dense>
#include <boost/test/unit_test.hpp>
#include "Configuration.hpp"
#include "matrixIO.hpp"

BOOST_AUTO_TEST_SUITE(MatrixIOTests, *boost::unit_test::tolerance(1e-12))

// Test reading the 3x3 matrix from m3.csv
BOOST_AUTO_TEST_CASE(ReadMatrix3x3)
{
    const std::string expectedMatrixFileName{"../data/m3.csv"};
    const int         expectedMatrixSize{3};
    Eigen::MatrixXd   expectedMatrix(3, 3);

    expectedMatrix << 0.680375, 0.59688, -0.329554,
                     -0.211234, 0.823295,  0.536459,
                      0.566198, -0.604897, -0.444451;

    Configuration   configuration{"testconfig.yml"};
    Eigen::MatrixXd matrix = matrixIO::openData(configuration.matrixFileName, configuration.matrixSize);

    BOOST_TEST(matrix.isApprox(expectedMatrix));
}

BOOST_AUTO_TEST_SUITE_END()