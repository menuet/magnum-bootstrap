#include <Platform/Sdl2Application.h>
#include <DefaultFramebuffer.h>

using namespace Magnum;

class MyApplication: public Platform::Application {
    public:
        explicit MyApplication(const Arguments& arguments);

    private:
        void drawEvent() override;
};

MyApplication::MyApplication(const Arguments& arguments): Platform::Application(arguments) {
    /* TODO: Add your initialization code here */
}

void MyApplication::drawEvent() {
    defaultFramebuffer.clear(FramebufferClear::Color);

    /* TODO: Add your drawing code here */

    swapBuffers();
}

MAGNUM_APPLICATION_MAIN(MyApplication)