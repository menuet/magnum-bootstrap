
#include "textured_shader.hpp"
#include <Magnum/GL/Context.h>
#include <Corrade/Utility/Resource.h>
#include <Corrade/Containers/Reference.h>
#include <Magnum/GL/Version.h>
#include <Magnum/GL/Shader.h>

using namespace Magnum;

TexturedTriangleShader::TexturedTriangleShader()
{
    MAGNUM_ASSERT_GL_VERSION_SUPPORTED(GL::Version::GL330);

    const Utility::Resource rs{"textured-triangle-data"};

    GL::Shader vert{GL::Version::GL330, GL::Shader::Type::Vertex};
    GL::Shader frag{GL::Version::GL330, GL::Shader::Type::Fragment};

    vert.addSource(rs.get("textured_shader.vert"));
    frag.addSource(rs.get("textured_shader.frag"));

    CORRADE_INTERNAL_ASSERT_OUTPUT(GL::Shader::compile({vert, frag}));

    attachShaders({vert, frag});

    CORRADE_INTERNAL_ASSERT_OUTPUT(link());

    _colorUniform = uniformLocation("color");

    setUniform(uniformLocation("textureData"), TextureUnit);
}
