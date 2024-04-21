#ifndef SceneGame_h
#define SceneGame_h

#include "Scene.h"
#include "Input.h"
#include "Object.h"
#include "C_Sprite.h"
#include "C_KeyboardMovement.h"
#include "ResourceAllocator.h"
#include "ObjectCollection.h"
#include "C_Animation.h"
#include "TileMapParser.h"
class SceneGame : public Scene
{
public:
    // We now pass the texture allocator to our game scene.
    SceneGame(ResourceAllocator<sf::Texture>& textureAllocator);
    void OnCreate() override;
    void OnDestroy() override;

    void ProcessInput() override;
    void Update(float deltaTime) override;
    void LateUpdate(float deltaTime) override;
    void Draw(Window& window) override;

private:
    //sf::Texture marioTexture;
    //sf::Sprite marioSprite;
    //std::shared_ptr<Object> player;
    ObjectCollection objects;
    Input input;
    // We’ll store a reference to the texture allocator.
    ResourceAllocator<sf::Texture>& textureAllocator;

    TileMapParser mapParser;
};

#endif /* SceneGame_hpp */


