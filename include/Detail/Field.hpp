#pragma once

#include <vector>

namespace FieldMath
{
namespace detail
{
    typedef double scalar;

    template <typename T>
    class Field
    {
        std::vector<T> data;

    public:
        Field();
    };

}
}