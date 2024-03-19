#ifndef SceneSplashScreen_h
#define SceneSplashScreen_h

#include <SFML/Graphics.hpp>

#include "SceneStateMachine.h"
#include "ResourceAllocator.h"

class SceneSplashScreen : public Scene
{
public:
    SceneSplashScreen(SceneStateMachine& sceneStateMachine, Window& window,
        ResourceAllocator<sf::Texture>& textureAllocator);
    void OnCreate() override;
    void OnDestroy() override;

    void OnActivate() override;

    void SetSwitchToScene(unsigned int id);

    void Update(float deltaTime) override;
    void Draw(Window& window) override;

private:
    sf::Texture splashTexture;
    sf::Sprite splashSprite;

    SceneStateMachine& sceneStateMachine;
    Window& window;

    float showForSeconds; // We want to show this scene for a set amount of time
    float currentSeconds; // How long the scene has currently been visible.

    unsigned int switchToState; // The state we want to transition to when this scenes time expires.
    ResourceAllocator<sf::Texture>& textureAllocator;
};

#endif /* SceneSplashScreen_h */