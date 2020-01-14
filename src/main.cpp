
#include "triangle_app.hpp"
#include "cube_app.hpp"
#include "textured_app.hpp"
#include "viewer_app.hpp"

#define APP_INDEX 3

#if APP_INDEX == 0
MAGNUM_APPLICATION_MAIN(TriangleApp)
#elif APP_INDEX == 1
MAGNUM_APPLICATION_MAIN(CubeApp)
#elif APP_INDEX == 2
MAGNUM_APPLICATION_MAIN(TexturedApp)
#elif APP_INDEX == 3
MAGNUM_APPLICATION_MAIN(ViewerApp)
#endif
