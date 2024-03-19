#ifndef C_KeyboardMovement_h
#define C_KeyboardMovement_h

#include "Component.h"
#include "Input.h"
#include "C_Animation.h"
class C_KeyboardMovement : public Component
{
public:
    C_KeyboardMovement(Object* owner);

    void SetInput(Input* input);
    void SetMovementSpeed(int moveSpeed);

    void Update(float deltaTime) override;
    void Awake() override;
private:
    int moveSpeed;
    Input* input;
    // We need to store a reference to the 
    // animation component for now.
    std::shared_ptr<C_Animation> animation;
};

#endif /* C_KeyboardMovement_h */