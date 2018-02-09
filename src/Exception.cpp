#include "../include/Exception.h"

namespace SdlWrapper
{
    const char* SdlException::what() const noexcept
    {
        return SDL_GetError();
    }

    void checkReturnValue(int returnValue)
    {
        if (returnValue != 0)
            throw SdlException{};
    }

}