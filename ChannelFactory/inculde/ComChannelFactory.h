#pragma once
#ifndef COM_CHANNEL_FACTORY
#define COM_CHANNEL_FACTORY

#include "ChannelFactory.h"

typedef struct {
	ChFac_Context fac_c;
	int err;
}COM_CHFAC;

void COM_CF_Process(void);


#endif