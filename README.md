# Obstacle Game – 3D Obstacle Platformer 

**Obstacle Assault** is a 3D arcade-style game where the player navigates an obstacle course using timing and precision. All platforms are controlled via C++ and behave differently based on their tags and logic setup.

## Core Gameplay

- Precise jumping across platforms with varying behaviors  
- Timed movement and rotation challenges  
- Reactive pushing platforms that interrupt player progress  
- Mix of static, moving, and rotating geometry  
- No Blueprint scripting for platform logic — all handled in C++

## Implemented Features

### C++-Driven Platform System
- Each platform is controlled fully via C++ without individual setup in the editor.
- Behavior is assigned at runtime via `UGameplayStatics::GetAllActorsWithTag`.

### Moving Platforms
- Movement directions: vertical, horizontal
- Reverses direction after reaching max range

### Rotating Platforms
- Rotation speeds set dynamically: 90°, 180°, 220°  

### Pushing Platforms
- Large platforms that move forward to push the player
- Scaled and timed using array index for increasing difficulty

