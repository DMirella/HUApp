#ifndef BOOSTC11_H
#define BOOSTC11_H

#include <memory>

namespace boostcc11 {

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}  // namespace boostcc11

#endif // BOOSTC11_H
