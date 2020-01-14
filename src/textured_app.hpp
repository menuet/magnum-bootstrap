
#pragma once

#include "textured_shader.hpp"
#include <Magnum/GL/Mesh.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/GL/Texture.h>

class TexturedApp : public Magnum::Platform::Application
{
public:
    explicit TexturedApp(const Arguments& arguments);

private:
    void drawEvent() override;

    Magnum::GL::Mesh _mesh;
    TexturedTriangleShader _shader;
    Magnum::GL::Texture2D _texture;
};
