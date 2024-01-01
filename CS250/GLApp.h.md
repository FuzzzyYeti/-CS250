---
date created: 2023-12-27 12:58
tags:
  - Header
---

```c++
/*
 * Jinseok Son
 * Winter 2023
 */

#pragma once

#include <gsl/pointers>

struct SDL_Window;
typedef void* SDL_GLContext;
class IProgram;

class [[nodiscard]] GLApp
{
public:
  
    ~GLApp();
    inline static GLApp& GLAppInstance(const char*title="OpenGL App",int width=800, int     desired_height=800)
    {
        //I apply direct Initialization at this code because  i delete all copy constructor and copy operation
        static GLApp app(title,width,desired_height);
        return app;
    } 
    GLApp(const GLApp&)                = delete;
    GLApp& operator=(const GLApp&)     = delete;
    GLApp(GLApp&&) noexcept            = delete;
    GLApp& operator=(GLApp&&) noexcept = delete;

    void Update();
    bool IsDone() const noexcept;

private:
    GLApp(const char* title = "OpenGL App", int desired_width = 800, int desired_height = 600);
    gsl::owner<IProgram*>     ptr_program = nullptr;
    gsl::owner<SDL_Window*>   ptr_window  = nullptr;
    gsl::owner<SDL_GLContext> gl_context  = nullptr;
    bool                      is_done     = false;
};

```

Forward Declartion 

```c++
struct SDL_Window;
typedef void* SDL_GLContext;
class IProgram;
```

