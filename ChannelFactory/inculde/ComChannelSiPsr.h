#pragma once
#ifndef COM_CHANNEL_SI_PSR
#define COM_CHANNEL_SI_PSR

#include "ChannlSiParser.h"

typedef struct {
	ChSiPsr_Context ComPsr;
	int err;
}COM_CHSIPSR;


COM_CHSIPSR* CreateComChSiPsr(void);

#endif