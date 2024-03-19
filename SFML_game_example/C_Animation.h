#ifndef C_Animation_h
#define C_Animation_h

#include "Component.h"
#include "Animation.h"
#include "C_Sprite.h"

enum class AnimationState
{
    None,
    Idle,
    Walk
};

class C_Animation : public Component
{
public:
    C_Animation(Object* owner);

    void Awake() override;

    void Update(float deltaTime) override;

    // Add animation to object. We need its state as well 
    // so that we can switch to it.
    void AddAnimation(AnimationState state,
        std::shared_ptr<Animation> animation);

    // Set current animation states.
    void SetAnimationState(AnimationState state);

    // Returns current animation state.
    const AnimationState& GetAnimationState() const;
    void SetAnimationDirection(FacingDirection dir);

private:
    std::shared_ptr<C_Sprite> sprite; // 1
    std::map<AnimationState, std::shared_ptr<Animation>> animations;

    // We store a reference to the current animation so we 
    // can quickly update and draw it.
    std::pair<AnimationState,
        std::shared_ptr<Animation>> currentAnimation;
};
#endif /* C_Animation_h */
