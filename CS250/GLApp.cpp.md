[[GLApp.h]]
[[C++ if with Initialization]]
[[Universial Fowarding Reference]]
  
## Global Function
```c++
namespace
{
    void hint_gl(SDL_GLattr attr, int value)
    {
        // https://wiki.libsdl.org/SDL_GL_SetAttribute
        glfw에서 윈도우를 만들때 넣는 힌트를 넣기위해 이코들을 사용 
        if (const auto success = SDL_GL_SetAttribute(attr, value); success != 0)
        {   
           //iF with Intialization is only work for c++17
            std::cerr << "Failed to Set GL Attribute: " << SDL_GetError() << '\n';
        }
    }


template <typename... Messages>
[[noreturn]] void throw_error_message(Messages&&... more_messages)
    {
      
        std::ostringstream sout;
        (sout << ... << more_messages);
        throw std::runtime_error{sout.str()};
    }
}
```
