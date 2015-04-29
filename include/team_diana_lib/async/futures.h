#ifndef TEAM_DIANA_LIB_ASYNC_FUTURES
#define TEAM_DIANA_LIB_ASYNC_FUTURES

#include <future>

// from http://stackoverflow.com/questions/14489935/implementing-futurethen-equivalent-for-asynchronous-execution-in-c11
// Roman Kutlak

namespace Td {

template <typename T, typename Work>
auto then(std::future<T> f, Work w) -> std::future<decltype(w(f.get()))>
{
    return std::async([](std::future<T> f, Work w)
                      { return w(f.get()); }, std::move(f), std::move(w));
}

template <typename Work>
auto then(std::future<void> f, Work w) -> std::future<decltype(w())>
{
    return std::async([](std::future<void> f, Work w)
                      { f.wait(); return w(); }, std::move(f), std::move(w));
}

}

#endif
