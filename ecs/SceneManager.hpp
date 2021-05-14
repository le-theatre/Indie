#pragma once

#include "IScene.hpp"

namespace Ecs {

template<typename ComponentList>
class World;

template <typename ComponentList>
class SceneManager
{
private:
    using ScenePtr = std::unique_ptr<IScene>;

    ScenePtr $currentScene{nullptr};
    std::vector<ScenePtr> $sceneStack;
    World<ComponentList> &$ecs;
    
public:
    SceneManager(World<ComponentList> &ecs) : $ecs(ecs) {}

    void clear()
    {
        $currentScene = nullptr;
        $sceneStack.clear();
    }

    template <typename TScene>
    void push()
    {
        if ($currentScene) {
            $currentScene->onPause();
            $sceneStack.push_back(std::move($currentScene));
        }
        $currentScene = std::make_unique<TScene>($ecs);
        $currentScene->onStart();
    }

    void pop()
    {
        if ($currentScene) {
            $currentScene->onStop();
        }
        if ($sceneStack.size() > 0) {
            $currentScene = std::move($sceneStack.back());
            $currentScene->onResume();
            $sceneStack.pop_back();
        } else {
            $currentScene = nullptr;
        }
    }

    template <typename TScene>
    void swap()
    {
        $currentScene = std::make_unique<TScene>($ecs);
    }

    void update(float deltaTime)
    {
        for (auto &scene : $sceneStack) {
            scene->shadowUpdate(deltaTime);
        }
        if ($currentScene) {
            $currentScene->update(deltaTime);
            // $currentScene->runSystem();
        }
    }

    void fixedUpdate()
    {
        for (auto &scene : $sceneStack) {
            scene->shadowFixedUpdate();
        }
        if ($currentScene) {
            $currentScene->fixedUpdate();
        }
    }

    [[ nodiscard ]] bool isOk() const noexcept
    {
        return not not $currentScene;
    }
};

}
