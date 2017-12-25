Expression Template MWE
=============================
**Efficient and expressive use of Fields**<br />


**Requirements:**
- C++17


**Goals:**
- scalar /op/ scalarfield
- scalar /op/ vectorfield      (should maybe not include `+`/`-`)
- vector /op/ scalarfield      (should maybe not include `+`/`-`)
- vector /op/ vectorfield      (should not include `*`, but should include `.dot(...)`, `.cross(...)` etc.)
- vectorfield /op/ vectorfield (should not include `*`, but should include `.dot(...)`, `.cross(...)` etc.)


**TODO:**
- enable mixture of numeric types (currently Fields need to have the exact same type)
- enable scaling of vectorfields: scalar(field) /op/ vectorfield