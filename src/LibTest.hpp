/*
 * File:   LibTest.hpp
 * Author: JoPe
 *
 * Created on 18 de septiembre de 2013, 23:12
 */

#ifndef LIBTEST_HPP
#define	LIBTEST_HPP

//#include "MAT/Matrix4.hpp"

namespace mat
{
    struct Matrix4;
}

class LibTest
{
    public:
        void Run();

    protected:
        bool TestMatrix();

        // Matrix4 tests
        void DisplayMatrix( mat::Matrix4 const& i_matrix ) const;
        bool TestMatrix4Identity() const;
        bool TestMatrix4Operators() const;
        bool TestMatrix4Mult() const;
};

#endif	/* LIBTEST_HPP */

