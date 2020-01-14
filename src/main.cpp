
#include "triangle_app.hpp"
#include "cube_app.hpp"

#define APP_INDEX 1

#if APP_INDEX == 0
MAGNUM_APPLICATION_MAIN(TriangleApp)
#elif APP_INDEX == 1
MAGNUM_APPLICATION_MAIN(CubeApp)
#endif
