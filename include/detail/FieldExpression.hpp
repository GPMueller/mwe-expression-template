#pragma once

#include <assert.h>

namespace FieldMath::detail
{
    // Field expression template
    template <typename E>
    class FieldExpression {
    public:
        double operator[](size_t i) const { return static_cast<E const&>(*this)[i];     }
        size_t size()               const { return static_cast<E const&>(*this).size(); }

        // The following overload conversions to E, the template argument type;
        // e.g., for FieldExpression<FieldSum>, this is a conversion to FieldSum.
        operator E& () { return static_cast<E&>(*this); }
        operator const E& () const { return static_cast<const E&>(*this); }
    };

    template <typename E1, typename E2>
    class FieldSum : public FieldExpression<FieldSum<E1, E2> > {
        E1 const& _u;
        E2 const& _v;

    public:
        FieldSum(E1 const& u, E2 const& v) : _u(u), _v(v) {
            assert(u.size() == v.size());
        }

        double operator[](size_t i) const { return _u[i] + _v[i]; }
        size_t size()               const { return _v.size(); }
    };

    template <typename E1, typename E2>
    FieldSum<E1,E2> const
    operator+(E1 const& u, E2 const& v) {
        return FieldSum<E1, E2>(u, v);
    }
}