Expression Template MWE
=============================
**Efficient and expressive use of abstract Fields**<br />

&nbsp;

**Requirements:**
- C++17
- (later maybe OpenMP 4.5)
- (later maybe CUDA 8)


**Goals:**
- scalar /op/ scalarfield
- scalar /op/ vectorfield      (should maybe not include `+`/`-`)
- vector /op/ scalarfield      (should maybe not include `+`/`-`)
- vector /op/ vectorfield      (should not include `*`, but should include `.dot(...)`, `.cross(...)` etc.)
- vectorfield /op/ vectorfield (should not include `*`, but should include `.dot(...)`, `.cross(...)` etc.)


**TODO:**
- enable mixture of field contents types (currently Fields need to have the exact same type): enables e.g. `Field<int>*Field<scalar>` and `Field<scalar>*Field<Vector3>`
- add more operators `-`, `+=`, `-=`, `*=`, `/=`
- enable choice of backend: single-thread, OpenMP, CUDA
- add function to extract a set of entries via an index list: field.set(list), field.set({0,1,3,4,20})


ScalarField Example:
--------------------
```C++
using FieldMath::detail::Field;
using FieldMath::detail::scalar;

// Initialize
Field<scalar> sf1({1,2,3,4,5});
Field<scalar> sf2({1,2,3,4,5});
Field<scalar> sf3(5, 2);

// Operate
Field<scalar> sf_res1 = sf1 + sf2 * sf3;

// Print
std::cerr << "sf1 + sf2 * sf3:" << std::endl;
for (int i=0; i < sf_res1.size(); ++i)
    std::cerr << sf_res1[i] << std::endl;
```
should print:
```
sf1 + sf2 * sf3:
3
6
9
12
15
```

VectorField Example:
--------------------
```C++
using FieldMath::detail::Field;
using FieldMath::detail::scalar;
using FieldMath::detail::Vector3;

// Initialize
Field<scalar> sf1(5, 2);

Field<Vector3> vf1(5, {0, 0,   1});
Field<Vector3> vf2(5, {0, 0.5, 0.5});

// Operate
Field<scalar> sf_res2 = vf1.dot(vf2) + sf1;
Field<Vector3> vf_res1 = vf1 + vf2;
Field<Vector3> vf_res2 = vf1.cross(vf2);

// Print
std::cerr << std::endl;
std::cerr << "vf1.dot(vf2):" << std::endl;
for (int i=0; i < sf_res2.size(); ++i)
    std::cerr << sf_res2[i] << std::endl;

std::cerr << std::endl;
std::cerr << "vf1 + vf1.cross(vf2):" << std::endl;
for (int i=0; i < vf_res1.size(); ++i)
    std::cerr << vf_res1[i].transpose() << std::endl;
```
should print:
```
vf1.dot(vf2):
2.5
2.5
2.5
2.5
2.5

vf1 + vf1.cross(vf2):
-0.5    0    1
-0.5    0    1
-0.5    0    1
-0.5    0    1
-0.5    0    1
```