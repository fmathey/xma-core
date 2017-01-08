#include <XMA/Core/Random.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

float random(float min, float max) noexcept
{
    #ifdef XMA_SYSTEM_WINDOWS

        static bool init = false;

        if(!init) {
            srand(time(0));rand();
            init = true;
        }

        double f = (double)rand() / RAND_MAX;
        return (data_t) min + f * (max - min);

    #else

        std::mt19937 gen(std::random_device{}());
        std::uniform_real_distribution<float> dis(min, max);
        return dis(gen);

    #endif
}

// ---------------------------------------------------------------------------------------------------------------------

}}

