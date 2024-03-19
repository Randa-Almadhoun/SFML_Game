#include "Game.h"

Game::Game() : window("Our game engine")
{
     // Pass in the texture allocator to our splash screen.
    std::shared_ptr<SceneSplashScreen> splashScreen =
        std::make_shared<SceneSplashScreen>(sceneManager,window, textureAllocator);

    // We now pass the textureAllocator to our game scene.
    std::shared_ptr<SceneGame> gameScene =
        std::make_shared<SceneGame>(textureAllocator);

    unsigned int splashScreenID = sceneManager.Add(splashScreen);
    unsigned int gameSceneID = sceneManager.Add(gameScene);

    splashScreen->SetSwitchToScene(gameSceneID);

    sceneManager.SwitchTo(splashScreenID);

    deltaTime = clock.restart().asSeconds();

}

void Game::Update()
{
    window.Update();

    sceneManager.Update(deltaTime);


}
void Game::CaptureInput()
{
    sceneManager.ProcessInput();
}
void Game::LateUpdate()
{
    sceneManager.LateUpdate(deltaTime);
}

void Game::Draw()
{
    window.BeginDraw();
    sceneManager.Draw(window);
    window.EndDraw();
}
void Game::CalculateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}
bool Game::IsRunning() const
{
    return window.IsOpen();
}


