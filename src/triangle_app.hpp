
#pragma once

#include <Magnum/GL/Mesh.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Shaders/VertexColor.h>

class TriangleApp : public Magnum::Platform::Application
{
public:
    explicit TriangleApp(const Arguments& arguments);

private:
    void drawEvent() override;

    Magnum::GL::Mesh _mesh;
    Magnum::Shaders::VertexColor2D _shader;
};
