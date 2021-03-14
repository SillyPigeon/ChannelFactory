#pragma once
#ifndef CHANNEL_SI_PASER
#define CHANNEL_SI_PASER
#include "ChFacUnitly.h"

#define MAX_FUNC_NUM  20

typedef CF_BOOL (*ChSiPsr_StFunc) (void);

typedef struct {
	ChSiPsr_StFunc psrFunclist[MAX_FUNC_NUM+1];//TODO:ªª≥…¡¥±Ì¿¥–¥
	unsigned char u8state;
	unsigned char u8Laststate;
}ChSiPsr_Context;

extern CF_RS ChSiPsr_Main(void* context);

#endif
