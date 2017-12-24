Expression Template MWE
=============================
**Efficient and expressive use of Fields**<br />


**Requirements:**
- C++17


**Goals:**
Examples:
- scalar /op/ scalarfield
- scalar /op/ vectorfield      (should maybe not include `+`/`-`)
- vector /op/ scalarfield      (should maybe not include `+`/`-`)
- vector /op/ vectorfield      (should not include `*`, but should include `.dot(...)`, `.cross(...)` etc.)
- vectorfield /op/ vectorfield (should not include `*`, but should include `.dot(...)`, `.cross(...)` etc.)
