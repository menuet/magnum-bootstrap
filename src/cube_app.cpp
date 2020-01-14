
#include "cube_app.hpp"
#include <Corrade/Utility/DebugStl.h>
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/GL/Mesh.h>
#include <Magnum/GL/Renderer.h>
#include <Magnum/MeshTools/CompressIndices.h>
#include <Magnum/MeshTools/Interleave.h>
#include <Magnum/Primitives/Cube.h>
#include <Magnum/Trade/MeshData3D.h>

using namespace Magnum;
using namespace Math::Literals;

CubeApp::CubeApp(const Arguments& arguments)
    : Platform::Application{arguments, Configuration{}.setTitle("Magnum Triangle Example")}
{
    GL::Renderer::enable(GL::Renderer::Feature::DepthTest);
    GL::Renderer::enable(GL::Renderer::Feature::FaceCulling);

    const Trade::MeshData3D cube = Primitives::cubeSolid();

    GL::Buffer vertices;
    vertices.setData(MeshTools::interleave(cube.positions(0), cube.normals(0)));

    Containers::Array<char> indexData;
    MeshIndexType indexType;
    UnsignedInt indexStart, indexEnd;
    std::tie(indexData, indexType, indexStart, indexEnd) = MeshTools::compressIndices(cube.indices());

    GL::Buffer indices;
    indices.setData(indexData);

    _mesh.setPrimitive(cube.primitive())
        .setCount(cube.indices().size())
        .addVertexBuffer(std::move(vertices), 0, Shaders::Phong::Position{}, Shaders::Phong::Normal{})
        .setIndexBuffer(std::move(indices), 0, indexType, indexStart, indexEnd);

    _transformation = Matrix4::rotationX(30.0_degf) * Matrix4::rotationY(40.0_degf);
    _projection = Matrix4::perspectiveProjection(35.0_degf, Vector2{windowSize()}.aspectRatio(), 0.01f, 100.0f) *
                  Matrix4::translation(Vector3::zAxis(-10.0f));
    _color = Color3::fromHsv({35.0_degf, 1.0f, 1.0f});
}

void CubeApp::drawEvent()
{
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color | GL::FramebufferClear::Depth);

    _shader.setLightPosition({7.0f, 5.0f, 2.5f})
        .setLightColor(Color3{1.0f})
        .setDiffuseColor(_color)
        .setAmbientColor(Color3::fromHsv({_color.hue(), 1.0f, 0.3f}))
        .setTransformationMatrix(_transformation)
        .setNormalMatrix(_transformation.normalMatrix())
        .setProjectionMatrix(_projection);
    _mesh.draw(_shader);

    swapBuffers();
}

void CubeApp::mousePressEvent(MouseEvent& event)
{
    if (event.button() != MouseEvent::Button::Left)
        return;

    event.setAccepted();
}

void CubeApp::mouseReleaseEvent(MouseEvent& event)
{
    _color = Color3::fromHsv({_color.hue() + 50.0_degf, 1.0f, 1.0f});

    event.setAccepted();
    redraw();
}

void CubeApp::mouseMoveEvent(MouseMoveEvent& event)
{
    if (!(event.buttons() & MouseMoveEvent::Button::Left))
        return;

    Vector2 delta = 3.0f * Vector2{event.relativePosition()} / Vector2{windowSize()};

    _transformation = Matrix4::rotationX(Rad{delta.y()}) * _transformation * Matrix4::rotationY(Rad{delta.x()});

    event.setAccepted();
    redraw();
}
