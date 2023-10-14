# CatLink
CatLink Library.

# Use
1. Pull this repo.
2. Copy **All** src folder item (except `CMakeLists.txt`) to your project.
3. Add the include line below:
```c
#include <catlink.h>
```

# API
- `uint8_t * build_packet(catlink_struct)`
    - build/pack catlink_struct to byte array.
- `uint8_t unpack_packet(uint8_t *, catlink_struct *)`
    - unpack byte array to catlink_struct.