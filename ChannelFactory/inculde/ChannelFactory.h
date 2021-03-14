#pragma once
#ifndef CHANNEL_FACTORY
#define CHANNEL_FACTORY

#include "stdio.h"
#include "ChannlSiParser.h"
#include "ChFacUnitly.h"

typedef struct {
	CF_BOOL(*ChFac_Init) (void);
	CF_BOOL(*ChFac_Out) (void);
	CF_BOOL(*ChFac_Clear) (void);
	int state;
	void* pSiPsr;
}ChFac_Context;


CF_BOOL ChFac_Process(void* context);



#endif // !1
