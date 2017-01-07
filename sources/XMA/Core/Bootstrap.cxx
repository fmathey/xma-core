#include <XMA/Core/Bootstrap.hpp>

namespace XMA { namespace Core {

// ---------------------------------------------------------------------------------------------------------------------

int bootstrap(std::function<void(void)> cb, bool showError) noexcept
{
    try {

        cb();

    }
    catch(const std::bad_alloc&) { if(showError) std::cerr << "Erreur : mémoire insuffisante.\n"; }
    catch(const std::out_of_range&) { if(showError) std::cerr << "Erreur : débordement de mémoire.\n"; }
    catch(const std::exception& e) { if(showError) std::cerr << e.what() << std::endl; }
    catch(...) { if(showError) std::cerr << "Oups ... :-(" << std::endl; }

    return 0;
}

// ---------------------------------------------------------------------------------------------------------------------

}}