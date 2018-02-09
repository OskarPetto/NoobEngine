/**
 * SDL Wrappers for exceptions.
 */ 
#pragma once

#include "Types.h"
#include <stdexcept>

namespace SdlWrapper
{
    class SdlException : public std::exception
    {
        public:
        const char *what() const noexcept override;
    };

    template <class T>
    void checkPointer(const T*);
    void checkReturnValue(int);

    template <class T>
    void checkPointer(const T* ptr)
    {
        if (ptr == nullptr)
            throw SdlException{};
    }

}
