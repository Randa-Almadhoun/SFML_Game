#ifndef Game_h
#define Game_h

#include <SFML/Graphics.hpp>
#include "Input.h"
#include "Window.h"
#include <iostream>
#include "SceneStateMachine.h"
#include "SceneSplashScreen.h"
#include "SceneGame.h"
#include "ResourceAllocator.h"

class Game
{
public:
    Game();

    void CaptureInput();
    void Update();
    void LateUpdate();
    void Draw();
    void CalculateDeltaTime();
    bool IsRunning() const;

private:
    Window window;
    //sf::Texture marioTexture;
    //sf::Sprite marioSprite;
    sf::Clock clock;
    float deltaTime;
    //Input input;
    ResourceAllocator<sf::Texture> textureAllocator;
    SceneStateMachine sceneManager;
};

#endif /* Game_h */

