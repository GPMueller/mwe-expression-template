#include <FieldMath.hpp>
#include <iostream>

int main(int argc, char ** argv)
{
    // Initialize
    FieldMath::detail::Field<FieldMath::detail::scalar> vec1({1,2,3,4,5});
    FieldMath::detail::Field<FieldMath::detail::scalar> vec2({1,2,3,4,5});
    FieldMath::detail::Field<FieldMath::detail::scalar> vec3(5, 2);

    // Operate
    auto vec_res = vec1 + vec2 + vec3;

    // Print
    for (int i=0; i < vec_res.size(); ++i)
        std::cerr << vec_res[i] << std::endl;

    return EXIT_SUCCESS;
}