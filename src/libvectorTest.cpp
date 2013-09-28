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
    return pass;
}

bool libvectorTest::testScaling()
{
    bool pass ( true );
    return pass;
}

bool libvectorTest::testMagnitude()
{
    bool pass ( true );

    return pass;
}

bool libvectorTest::testDotProduct()
{
    bool pass ( true );
    return pass;
}

bool libvectorTest::testCrossProduct()
{
    bool pass ( true );
    return pass;
}


