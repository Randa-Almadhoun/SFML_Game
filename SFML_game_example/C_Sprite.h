#ifndef C_Sprite_h
#define C_Sprite_h

#include "Component.h"
#include "C_Transform.h"
#include "ResourceAllocator.h"

class C_Sprite : public Component
{
public:
    C_Sprite(Object* owner);

    // Loads a sprite from file.
    void Load(const std::string& filePath);
    // We add a new overloaded Load method that accepts a texture id.
    void Load(int id);

    void SetTextureAllocator(ResourceAllocator<sf::Texture>* allocator); // 1
    // We override the draw method so we can draw our sprite.
    void Draw(Window& window) override;

    void LateUpdate(float deltaTime) override;

    void SetTextureRect(int x, int y, int width, int height);
    void SetTextureRect(const sf::IntRect& rect);
    void SetScale(float x, float y);

private:
    //sf::Texture texture;
    ResourceAllocator<sf::Texture> * allocator;
    sf::Sprite sprite;
    int currentTextureID;
};

#endif /* C_Sprite_h */