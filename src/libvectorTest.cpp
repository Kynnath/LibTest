/*
 * File:   libvectorTest.cpp
 * Author: JoPe
 *
 * Created on 28 de septiembre de 2013, 11:50
 */

#include "libvectorTest.hpp"
#include "VEC/Vector2.hpp"
#include "VEC/Vector3.hpp"


bool libvectorTest::testEquality()
{
    bool pass ( true );

    vec::Vector2 const nullVector2 = { { 0 } };
    vec::Vector3 const nullVector3 = { { 0 } };

    pass = ( nullVector2.Equals( nullVector2 ) && pass );
    pass = ( nullVector3.Equals( nullVector3 ) && pass );

    vec::Vector2 const testVector2 = { { 0, 1 } };
    vec::Vector3 const testVector3 = { { 0, 1, 2 } };

    pass = ( !nullVector2.Equals( testVector2 ) && pass );
    pass = ( !nullVector3.Equals( testVector3 ) && pass );

    return pass;
}

bool libvectorTest::testAddition()
{
    bool pass ( true );

    vec::Vector2 const nullVector2 = { { 0 } };
    vec::Vector3 const nullVector3 = { { 0 } };
    vec::Vector2 const addVector2 = { { 0, 1 } };
    vec::Vector3 const addVector3 = { { 0, 1, 2 } };

    vec::Vector2 testVector2 ( nullVector2 );
    vec::Vector3 testVector3 ( nullVector3 );

    testVector2.Add( addVector2 );
    testVector3.Add( addVector3 );

    pass = ( testVector2.Equals( addVector2 ) && pass );
    pass = ( testVector3.Equals( addVector3 ) && pass );

    return pass;
}

bool libvectorTest::testSubstraction()
{
    bool pass ( true );

    vec::Vector2 const nullVector2 = { { 0 } };
    vec::Vector3 const nullVector3 = { { 0 } };
    vec::Vector2 const subVector2 = { { 0, 1 } };
    vec::Vector3 const subVector3 = { { 0, 1, 2 } };

    vec::Vector2 testVector2 ( subVector2 );
    vec::Vector3 testVector3 ( subVector3 );

    testVector2.Subtract( subVector2 );
    testVector3.Subtract( subVector3 );

    pass = ( testVector2.Equals( nullVector2 ) && pass );
    pass = ( testVector3.Equals( nullVector3 ) && pass );

    return pass;
}

bool libvectorTest::testScaling()
{
    bool pass ( true );

    vec::Vector2 const nullVector2 = { { 0 } };
    vec::Vector3 const nullVector3 = { { 0 } };
    vec::Vector2 const baseVector2 = { { 0, 1 } };
    vec::Vector3 const baseVector3 = { { 0, 1, 2 } };
    int const factor ( 2 );
    vec::Vector2 const resultVector2 = { { 0, 2 } };
    vec::Vector3 const resultVector3 = { { 0, 2, 4 } };

    vec::Vector2 testVector2 ( nullVector2 );
    vec::Vector3 testVector3 ( nullVector3 );

    testVector2.Scale( factor );
    testVector3.Scale( factor );

    pass = ( testVector2.Equals( nullVector2 ) && pass );
    pass = ( testVector3.Equals( nullVector3 ) && pass );

    testVector2 = baseVector2;
    testVector3 = baseVector3;

    testVector2.Scale( factor );
    testVector3.Scale( factor );

    pass = ( testVector2.Equals( resultVector2 ) && pass );
    pass = ( testVector3.Equals( resultVector3 ) && pass );

    return pass;
}

bool libvectorTest::testMagnitude()
{
    bool pass ( true );

    vec::Vector2 const nullVector2 = { { 0 } };
    vec::Vector3 const nullVector3 = { { 0 } };
    vec::Vector2 const baseVector2 = { { 0, 1 } };
    vec::Vector3 const baseVector3 = { { 0, 3, 4 } };

    pass = ( nullVector2.Magnitude() == 0 && pass );
    pass = ( nullVector3.Magnitude() == 0 && pass );
    pass = ( baseVector2.Magnitude() == 1 && pass );
    pass = ( baseVector3.Magnitude() == 5 && pass );

    return pass;
}

bool libvectorTest::testDotProduct()
{
    bool pass ( true );

    vec::Vector2 const nullVector2 = { { 0 } };
    vec::Vector3 const nullVector3 = { { 0 } };
    vec::Vector2 const baseVector2 = { { 0, 2 } };
    vec::Vector3 const baseVector3 = { { 0, 0, 2 } };
    vec::Vector2 const orthoVector2 = { { 2, 0 } };
    vec::Vector3 const orthoVector3 = { { 0, 2, 0 } };
    vec::Vector2 const otherVector2 = { { 1, 2 } };
    vec::Vector3 const otherVector3 = { { 1, 2, 3 } };

    pass = ( nullVector2.DotProduct( otherVector2 ) == 0 && pass );
    pass = ( nullVector3.DotProduct( otherVector3 ) == 0 && pass );
    pass = ( baseVector2.DotProduct( orthoVector2 ) == 0 && pass );
    pass = ( baseVector3.DotProduct( orthoVector3 ) == 0 && pass );
    pass = ( baseVector2.DotProduct( otherVector2 ) == 4 && pass );
    pass = ( baseVector3.DotProduct( otherVector3 ) == 6 && pass );

    return pass;
}

bool libvectorTest::testCrossProduct()
{
    bool pass ( true );
    return pass;
}


