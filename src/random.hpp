#ifndef SRC_RANDOM_HPP
#define SRC_RANDOM_HPP

#include <random>

template <typename T, template <typename> typename Distribution, typename RNG>
T random_value(T start, T end)
{
    // Choice distribution.
    // For T = int, start = 1, end = 2
    //   -> {1, 2}
    // For T = int, start = 1, end = 4
    //   -> {1, 2, 3, 4}
    // For T = double, start = 0.0, end = 1.0
    //   -> {0.0, ..., 1.0}
    static Distribution<T> dist(start, end);

    // Seed device. Set static to persist seed state.
    static std::random_device rd;

    // Random number generator.
    static RNG gen(rd());

    // Run the distribution functor on `gen`, producing the next
    // pseudo-random value from rd's seed.
    return dist(gen);
}

struct Random {
    using Algorithm = std::mt19937;

    template <typename T>
    using Real = std::uniform_real_distribution<T>;

    template <typename T>
    static T real(const T &start, const T &end)
    {
        return random_value<T, Real, Algorithm>(start, end);
    }

    template <typename T>
    using Integer = std::uniform_int_distribution<T>;

    template <typename T>
    static T integer(const T &start, const T &end)
    {
        return random_value<T, Integer, Algorithm>(start, end);
    }
};

template <typename T>
T randfloat(const T &start, const T &end)
{
    return Random::real(start, end);
}

template <typename T>
T randint(const T &start, const T &end)
{
    return Random::integer(start, end);
}

#endif /* SRC_RANDOM_HPP */
