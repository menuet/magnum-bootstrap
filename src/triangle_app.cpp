
#include "triangle_app.hpp"
#include <Corrade/Utility/DebugStl.h>
#include <Magnum/GL/Buffer.h>
#include <Magnum/GL/Context.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/GL/Version.h>
#include <Magnum/Math/Color.h>

using namespace Magnum;
using namespace Math::Literals;

TriangleApp::TriangleApp(const Arguments& arguments)
    : Platform::Application{arguments, Configuration{}.setTitle("Magnum Triangle Example")}
{
    GL::Renderer::setClearColor(0xa5c9ea_rgbf);

    Debug{} << "Hello! This application is running on" << GL::Context::current().version() << "using"
            << GL::Context::current().rendererString();

    struct TriangleVertex
    {
        Vector2 position;
        Color3 color;
    };

    const TriangleVertex data[]{
        {{-0.5f, 0.f}, 0xff0000_rgbf}, /* Left vertex, red color */
        {{0.f, -0.5f}, 0x00ff00_rgbf}, /* Right vertex, green color */
        {{0.5f, 0.f}, 0x0000ff_rgbf},  /* Top vertex, blue color */
        {{-0.5f, 0.f}, 0xff0000_rgbf}, /* Left vertex, red color */
        {{0.f, 0.5f}, 0x00ff00_rgbf},  /* Right vertex, green color */
        {{0.5f, 0.f}, 0x0000ff_rgbf},  /* Top vertex, blue color */
    };

    constexpr auto vertices_count = sizeof(data) / sizeof(data[0]);

    Debug{} << "Vertices = " << vertices_count;

    GL::Buffer buffer;
    buffer.setData(data);

    _mesh.setCount(vertices_count)
        .addVertexBuffer(std::move(buffer), 0, Shaders::VertexColor2D::Position{}, Shaders::VertexColor2D::Color3{});
}

void TriangleApp::drawEvent()
{
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

    _mesh.draw(_shader);

    swapBuffers();
}
