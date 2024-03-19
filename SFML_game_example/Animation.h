
#ifndef Animation_h
#define Animation_h

#include <vector>

enum class FacingDirection
{
    None,
    Left,
    Right
};

struct FrameData
{
    int id; // Texture id (retrieved from our texture allocator).
    int x; // x position of sprite in the texture.
    int y; // y position of sprite in the texture.
    int width; // Width of sprite.
    int height; // Height of sprite.
    float displayTimeSeconds; // How long to display the frame.
};
class Animation
{
public:
    Animation();
    Animation(FacingDirection direction);

    void AddFrame(int textureID, int x, int y,
        int width, int height, float frameTime);
    const FrameData* GetCurrentFrame() const;
    bool UpdateFrame(float deltaTime);
    void Reset();
    void SetDirection(FacingDirection dir);
    FacingDirection GetDirection() const;

private:
    void IncrementFrame();
    // Stores all frames for our animation.
    std::vector<FrameData> frames;
    // Current frame.
    int currentFrameIndex;
    // We use this to decide when to transition to the next frame.
    float currentFrameTime;
    FacingDirection direction;
};

#endif /* Animation_h */