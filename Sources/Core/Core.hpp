#ifndef CORE_HPP_
#define CORE_HPP_

namespace cta {
    class Core {
        public:
            ~Core() = default;
            Core() noexcept;
            Core(const Core &) = delete;
            Core &operator=(const Core &) = delete;
            void run(const int, const char * const *, const char * const*);
    };
}

#endif