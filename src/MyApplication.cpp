#include <Corrade/Containers/Optional.h>
/* Magnum GL headers must always be included before Qt ones */
#include <Magnum/GL/DefaultFramebuffer.h>
#include <Magnum/Platform/GLContext.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QOpenGLWidget>

using namespace Magnum;

class MyApplication: public QOpenGLWidget {
    public:
        explicit MyApplication(Platform::GLContext& context, QWidget* parent = nullptr, Qt::WindowFlags f = nullptr);

    private:
        void initializeGL() override;
        void paintGL() override;

        Platform::GLContext& _context;
};

MyApplication::MyApplication(Platform::GLContext& context, QWidget* parent, Qt::WindowFlags f): QOpenGLWidget{parent, f}, _context(context) {
    /* TODO: Add your context format setup code here */
}

void MyApplication::initializeGL() {
    _context.create();

    /* TODO: Add your initialization code here */
}

void MyApplication::paintGL() {
    GL::defaultFramebuffer.clear(GL::FramebufferClear::Color);

    /* TODO: Add your drawing code here */
}

int main(int argc, char** argv) {
    Platform::GLContext context{NoCreate, argc, argv};
    QApplication app{argc, argv};

    MyApplication w{context};
    w.show();

    return app.exec();
}
