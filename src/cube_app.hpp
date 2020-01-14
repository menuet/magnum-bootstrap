
#pragma once

#include <Magnum/GL/Mesh.h>
#include <Magnum/Math/Color.h>
#include <Magnum/Math/Matrix4.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/Shaders/Phong.h>

class CubeApp : public Magnum::Platform::Application
{
public:
    explicit CubeApp(const Arguments& arguments);

private:
    void drawEvent() override;
    void mousePressEvent(MouseEvent& event) override;
    void mouseReleaseEvent(MouseEvent& event) override;
    void mouseMoveEvent(MouseMoveEvent& event) override;

    Magnum::GL::Mesh _mesh;
    Magnum::Shaders::Phong _shader;
    Magnum::Matrix4 _transformation;
    Magnum::Matrix4 _projection;
    Magnum::Color3 _color;
};
