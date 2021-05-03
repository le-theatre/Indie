#pragma once

namespace ecs {
    class Scene {
    public:
        virtual void onStart() {}
        virtual void onStop() {}
        virtual void onPause() {}
        virtual void onResume() {}
        virtual void handleEvent() {}
        virtual void fixedUpdate() {}
        virtual void update(float deltaTime) {}
        virtual void shadowUpdate(float deltaTime) {}
        virtual void shadowFixedUpdate() {}
    };

}
