#pragma once

#include <cassert>
#include <iostream>
#include <vector>

#include <detail/Typedefs.hpp>

namespace FieldMath::detail
{
    // Elementwise Field + Field
    template<typename T, typename Op1 , typename Op2>
    class FieldAdd
    {
        Op1 const& _op1;
        Op2 const& _op2;

    public:
        FieldAdd(Op1 const& a, Op2 const& b): _op1(a), _op2(b)
        {
            assert(_op1.size() == _op2.size());
        }

        T operator[](const std::size_t i) const
        { 
            return _op1[i] + _op2[i]; 
        }

        std::size_t size() const
        { 
            return _op1.size(); 
        }
    };

    // Elementwise Field * Field
    template< typename T, typename Op1 , typename Op2 >
    class FieldMul
    {
        Op1 const& _op1;
        Op2 const& _op2;

    public:
        FieldMul(Op1 const& a, Op2 const& b ): _op1(a), _op2(b)
        {
            assert(_op1.size() == _op2.size());
        }

        T operator[](const std::size_t i) const
        { 
            return _op1[i] * _op2[i]; 
        }

        std::size_t size() const
        { 
            return _op1.size(); 
        }
    };

    // Function template for the + operator
    template<typename T, typename R1, typename R2>
    Field<T, FieldAdd<T, R1, R2>> operator+ (const Field<T, R1>& a, const Field<T, R2>& b)
    {
        return Field<T, FieldAdd<T, R1, R2>>(FieldAdd<T, R1, R2 >(a.data(), b.data()));
    }

    // Function template for the * operator
    template<typename T, typename R1, typename R2>
    Field<T, FieldMul< T, R1, R2>> operator* (const Field<T, R1>& a, const Field<T, R2>& b)
    {
        return Field<T, FieldMul<T, R1, R2>>(FieldMul<T, R1, R2 >(a.data(), b.data()));
    }

    // Function template for << operator
    template<typename T> std::ostream& operator<< (std::ostream& os, const Field<T>& cont)
    {
        std::cout << std::endl;
        for (int i=0; i<cont.size(); ++i)
            os << cont[i] << ' ';
        os << std::endl;
        return os;
    }
}