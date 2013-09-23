/*
 * File:   LibTest.cpp
 * Author: JoPe
 *
 * Created on 18 de septiembre de 2013, 23:12
 */

#include "LibTest.hpp"

#include <cstring>
#include <iostream>
#include "MAT/Matrix4.hpp"

void LibTest::Run()
{
    TestMatrix();
}

bool LibTest::TestMatrix()
{
    mat::Matrix4 testMatrix = { { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0 } };
    std::cout << "testMatrix: " << std::endl;
    std::cout << "Size: " << sizeof( mat::Matrix4 ) << " Size of double x16: " << sizeof( double ) * 16 << std::endl;

    DisplayMatrix( testMatrix );

    memset( &testMatrix, 0, sizeof( mat::Matrix4 ) );

    DisplayMatrix( testMatrix );

    TestMatrix4Identity();
    TestMatrix4Operators();
    TestMatrix4Mult();

    return true;
}

void LibTest::DisplayMatrix( mat::Matrix4 const& i_matrix ) const
{
    for ( int outerLoop = 0; outerLoop < 4; ++outerLoop )                   // Looping inner*4 + outer will display the
    {                                                                       // matrix in column major ordering
        for ( int innerLoop = 0; innerLoop < 4; ++innerLoop )               //  0,  4,  8, 12
        {                                                                   //  1,  5,  9, 13
            int position = innerLoop * 4 + outerLoop;                       //  2,  6, 10, 14
            double matrixValue ( *( (double*)(&i_matrix) + position ) );    //  3,  7, 11, 15
            std::cout << "\t" << matrixValue;
        }
        std::cout << std::endl;
    }
}

bool LibTest::TestMatrix4Identity() const
{
    mat::Matrix4 const identityMatrixCopy ( mat::k_identity );

    std::cout << "identityMatrixCopy:\n";
    DisplayMatrix( identityMatrixCopy );

    mat::Matrix4 const identityMatrixAssignment = identityMatrixCopy;

    std::cout << "identityMatrixAssignment:\n";
    DisplayMatrix( identityMatrixAssignment );

    mat::Matrix4 uninitializedMatrix;
    std::cout << "uninitializedMatrix:\n";
    DisplayMatrix( uninitializedMatrix );

    uninitializedMatrix.SetIdentity();
    std::cout << "uninitializedMatrix.SetIdentity()\n";
    DisplayMatrix( uninitializedMatrix );

    return true;
}

bool LibTest::TestMatrix4Operators() const
{
    mat::Matrix4 testMatrix = { { 0 } };

    if ( testMatrix( 0, 0 ) == 0 )
    {
        // yay
    }

    //double x = testMatrix( -1, 5 );
    return true;
}

bool LibTest::TestMatrix4Mult() const
{
    mat::Matrix4 matA ( mat::k_identity ), matB = { { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0 } };

    std::cout << "TestMatrix4Mult()\nmatA x matB:\n";
    DisplayMatrix( mat::Multiply( matA, matB ) );
    std::cout << "matB x matA:\n";
    DisplayMatrix( mat::Multiply( matB, matA ) );
    std::cout << "identity x 2\n";
    mat::Matrix4 test = { { 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2 } };
    matA.Multiply( test );
    DisplayMatrix( matA );
    std::cout << "matA x matB:\n";
    DisplayMatrix( mat::Multiply( matA, matB ) );
    std::cout << "matB x matA:\n";
    DisplayMatrix( mat::Multiply( matB, matA ) );

    return true;
}