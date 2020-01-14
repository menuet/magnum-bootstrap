
#pragma once

#include <Corrade/Containers/Array.h>
#include <Corrade/Containers/Optional.h>
#include <Magnum/Platform/Sdl2Application.h>
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/SceneGraph/MatrixTransformation3D.h>
#include <Magnum/SceneGraph/Object.h>
#include <Magnum/SceneGraph/Scene.h>
#include <Magnum/Shaders/Phong.h>
#include <Magnum/Trade/AbstractImporter.h>
#include <Magnum/Trade/PhongMaterialData.h>

class ViewerApp : public Magnum::Platform::Application
{
public:
    typedef Magnum::SceneGraph::Object<Magnum::SceneGraph::MatrixTransformation3D> Object3D;
    typedef Magnum::SceneGraph::Scene<Magnum::SceneGraph::MatrixTransformation3D> Scene3D;

    explicit ViewerApp(const Arguments& arguments);

private:
    void drawEvent() override;
    void viewportEvent(ViewportEvent& event) override;
    void mousePressEvent(MouseEvent& event) override;
    void mouseReleaseEvent(MouseEvent& event) override;
    void mouseMoveEvent(MouseMoveEvent& event) override;
    void mouseScrollEvent(MouseScrollEvent& event) override;

    Magnum::Vector3 positionOnSphere(const Magnum::Vector2i& position) const;

    void addObject(
        Magnum::Trade::AbstractImporter& importer,
        Magnum::Containers::ArrayView<const Magnum::Containers::Optional<Magnum::Trade::PhongMaterialData>> materials,
        Object3D& parent, Magnum::UnsignedInt i);

    Magnum::Shaders::Phong _coloredShader;
    Magnum::Shaders::Phong _texturedShader{Magnum::Shaders::Phong::Flag::DiffuseTexture};
    Magnum::Containers::Array<Magnum::Containers::Optional<Magnum::GL::Mesh>> _meshes;
    Magnum::Containers::Array<Magnum::Containers::Optional<Magnum::GL::Texture2D>> _textures;

    Scene3D _scene;
    Object3D _manipulator;
    Object3D _cameraObject;
    Magnum::SceneGraph::Camera3D* _camera{};
    Magnum::SceneGraph::DrawableGroup3D _drawables;
    Magnum::Vector3 _previousPosition;
};
