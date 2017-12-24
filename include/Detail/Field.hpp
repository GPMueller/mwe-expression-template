#pragma once

#include <vector>

#include <detail/FieldExpression.hpp>

namespace FieldMath::detail 
{
    typedef double scalar;

    template <typename T>
    class Field : public FieldExpression<Field<T>>
    {
        std::vector<T> _contents;

    public:

        scalar   operator[](size_t i) const { return _contents[i]; }
        scalar & operator[](size_t i)       { return _contents[i]; }
        size_t   size() const               { return _contents.size(); }


        Field(typename std::vector<T>::size_type N, T initvalue)
        {
            this->_contents = std::vector<T>(N, initvalue);
        }
        Field(size_t n) : _contents(n) {}

        // construct vector using initializer list 
        Field(std::initializer_list<scalar> init)
        {
            for(auto i : init)
                _contents.push_back(i);
        }


        // A Field can be constructed from any FieldExpression, forcing its evaluation.
        template <typename E>
        Field(FieldExpression<E> const& field) : _contents(field.size())
        {
            for (size_t i = 0; i != field.size(); ++i)
            {
                _contents[i] = field[i];
            }
        }
    };
}