#include "Arguments.h"
#include "Option.h"

#include "PricingEng.h"

PricingEng::PricingEng(Option*opt){opt_ = opt;}

PricingEng::PricingEng(Arguments& paras){opt_ = paras.g_PTR<Option>("option");}

