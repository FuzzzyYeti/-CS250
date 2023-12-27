/*
 * Rudy Castan
 * CS200
 * Fall 2022
 */

#pragma once

#include <gsl/pointers>

struct SDL_Window;
typedef void* SDL_GLContext;
union SDL_Event;

namespace ImGuiHelper
{
    void Initialize(gsl::not_null<SDL_Window*> sdl_window, gsl::not_null<SDL_GLContext> gl_context);
    void FeedEvent(const SDL_Event& event);
    void Begin();
    void End(gsl::not_null<SDL_Window*> sdl_window, gsl::not_null<SDL_GLContext> gl_context);
    void Shutdown();
}
