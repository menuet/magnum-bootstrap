find_package(Corrade REQUIRED Main)
find_package(Magnum REQUIRED GL Sdl2Application MeshTools Primitives Shaders Trade)

set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

corrade_add_resource(TexturedTriangle_RESOURCES resources.conf)

add_executable(MyApplication main.cpp triangle_app.cpp cube_app.cpp textured_app.cpp textured_shader.cpp ${TexturedTriangle_RESOURCES})

target_link_libraries(MyApplication PRIVATE
    Corrade::Main
    Magnum::Application
    Magnum::GL
    Magnum::Magnum
    Magnum::MeshTools
    Magnum::Primitives
    Magnum::Shaders)

add_dependencies(MyApplication Magnum::TgaImporter)

set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MyApplication)
