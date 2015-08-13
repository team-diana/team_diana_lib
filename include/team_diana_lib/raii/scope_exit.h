#pragma once

#include <functional>

namespace Td {

struct scope_exit {
    scope_exit(std::function<void (void)> f) : f_(f) {}

    ~scope_exit(void) {
        f_();
    }

private:
      std::function<void (void)> f_;
};

}
