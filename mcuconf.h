#pragma once

#include_next <mcuconf.h>

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE

#undef RP_ADC_USE_ADC1
#define RP_ADC_USE_ADC1 TRUE

