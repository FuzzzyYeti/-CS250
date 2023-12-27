/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */

#pragma once

#include <gsl/pointers>

struct SDL_Window;
typedef void* SDL_GLContext;
class IProgram;

class [[nodiscard]] GLApp
{
public:
    GLApp(const char* title = "OpenGL App", int desired_width = 800, int desired_height = 600);
    ~GLApp();

    GLApp(const GLApp&)                = delete;
    GLApp& operator=(const GLApp&)     = delete;
    GLApp(GLApp&&) noexcept            = delete;
    GLApp& operator=(GLApp&&) noexcept = delete;

    void Update();
    bool IsDone() const noexcept;

private:
    gsl::owner<IProgram*>     ptr_program = nullptr;
    gsl::owner<SDL_Window*>   ptr_window  = nullptr;
    gsl::owner<SDL_GLContext> gl_context  = nullptr;
    bool                      is_done     = false;
};
