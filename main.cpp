#include <FieldMath.hpp>
#include <iostream>

int main(int argc, char ** argv)
{
    using FieldMath::detail::Field;
    using FieldMath::detail::scalar;
    using FieldMath::detail::Vector3;

    // Initialize
    Field<scalar> sf1({1,2,3,4,5});
    Field<scalar> sf2({1,2,3,4,5});
    Field<scalar> sf3(5, 2);
    Field<int> if1(5, 100);

    Field<Vector3> vf1(5, {0, 0,   1});
    Field<Vector3> vf2(5, {0, 0.5, 0.5});

    // Operate
    Field<scalar> sf_res1 = sf1 + sf2 + sf3;
    // Field<scalar> sf_resint = sf1 + if1;
    // auto sf_res2 = vf1.dot(vf2);
    // auto vf_res1 = vf1 + vf2;

    // Print
    std::cerr << std::endl << "sf1 + sf2 + sf3:" << std::endl;
    for (int i=0; i < sf_res1.size(); ++i)
        std::cerr << sf_res1[i] << std::endl;

    // std::cerr << std::endl << "vf1.dot(vf2):" << std::endl;
    // for (int i=0; i < sf_res2.size(); ++i)
    //     std::cerr << sf_res2[i] << std::endl;

    // std::cerr << std::endl << "vf1 + vf2:" << std::endl;
    // for (int i=0; i < vf_res1.size(); ++i)
    //     std::cerr << vf_res1[i] << std::endl;

    return EXIT_SUCCESS;
}