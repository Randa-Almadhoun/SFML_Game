#include "SceneGame.h"


SceneGame::SceneGame(
    ResourceAllocator<sf::Texture>& textureAllocator)
    :  textureAllocator(textureAllocator), mapParser(textureAllocator) { }

void SceneGame::OnCreate()
{
 
    std::shared_ptr<Object> player = std::make_shared<Object>();

    //// Adds a component by calling our previously written template function.
    auto sprite = player->AddComponent<C_Sprite>();
    sprite->SetTextureAllocator(&textureAllocator); // Add this line
    /*sprite->Load("mario.png");*/

    auto movement = player->AddComponent
        <C_KeyboardMovement>();

    // Don’t forget to set the input otherwise the character will not move:
    movement->SetInput(&input);

    // Add our new animation component:
    auto animation = player->AddComponent<C_Animation>();

    //********* Super Mario Example (one animation state) **********
  /*  // the mario has only forward and backward
    int marioTextureID = textureAllocator.Add("mario3.png");

    const int frameWidth = 80; //1
    const int frameHeight = 118;

    // We pass in the animations direction when creating a new animation.
       // The character in the sprites faces right so we set that 
       // as the initial direction.
    std::shared_ptr<Animation> idleAnimation =
        std::make_shared<Animation>(FacingDirection::Right);

    // How long we want to show each frame.
    const float idleAnimFrameSeconds = 0.2f;

    idleAnimation->AddFrame(marioTextureID, 1, 1,
        frameWidth, frameHeight, idleAnimFrameSeconds);//3
    idleAnimation->AddFrame(marioTextureID, 83, 1,
        frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(marioTextureID, 1, 1,
        frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(marioTextureID, 83, 1,
        frameWidth, frameHeight, idleAnimFrameSeconds);

    // This adds the idle animation that we’ve just built. 
    // It will also set it as our active animation.
    animation->AddAnimation(AnimationState::Idle, idleAnimation); */


    //********* Viking character Example (two animation states) **********
    // the mario replaced with viking character to show the movement animation 
    // you can use mario by uncommenting the above part and comment the below part
    int vikingTextureID = textureAllocator.Add("Viking.png");

    const int frameWidth = 165;
    const int frameHeight = 145;

    std::shared_ptr<Animation> idleAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float idleAnimFrameSeconds = 0.2f;
    idleAnimation->AddFrame(vikingTextureID, 600, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 800, 0, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 0, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    idleAnimation->AddFrame(vikingTextureID, 200, 145, frameWidth, frameHeight, idleAnimFrameSeconds);
    animation->AddAnimation(AnimationState::Idle, idleAnimation);

    std::shared_ptr<Animation> walkAnimation = std::make_shared<Animation>(FacingDirection::Right);
    const float walkAnimFrameSeconds = 0.15f;
    walkAnimation->AddFrame(vikingTextureID, 600, 290, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 800, 290, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 0, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 200, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    walkAnimation->AddFrame(vikingTextureID, 400, 435, frameWidth, frameHeight, walkAnimFrameSeconds);
    animation->AddAnimation(AnimationState::Walk, walkAnimation);
   

    // Don’t forget to add the player to the object collection.
    objects.Add(player);

    // You will need to play around with this offset until it fits 
    // the level in at your chosen resolution. This worls for 1920 * 1080.
    // In future we will remove this hardcoded offset when we 
    // look at allowing the player to change resolutions.
    sf::Vector2i mapOffset(-100, 128);
    std::vector<std::shared_ptr<Object>> levelTiles
        = mapParser.Parse("Test Map 1.tmx", mapOffset);

    objects.Add(levelTiles);

}
void SceneGame::OnDestroy()
{

}
void SceneGame::ProcessInput()
{
    input.Update();
}

void SceneGame::Update(float deltaTime)
{
    objects.ProcessRemovals(); // Processes any object removals.

    objects.ProcessNewObjects();

    objects.Update(deltaTime);

}
void SceneGame::LateUpdate(float deltaTime)
{
    //player->LateUpdate(deltaTime);
    objects.LateUpdate(deltaTime);
}
void SceneGame::Draw(Window& window)
{
    objects.Draw(window);
}

