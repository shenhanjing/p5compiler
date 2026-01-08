#include "frontends/common/parser_options.h"

#include "ir/configuration.h"

namespace P4 {

// Standalone p5compiler does not implement full compile-context stacking for P4CContext.
// We provide a minimal configuration hook used by IR code (e.g., maximumWidthSupported()).
const P4CConfiguration &P4CContext::getConfig() { return DefaultP4CConfiguration::get(); }

}  // namespace P4


