#include "ComChannelFactory.h"
#include "ComChannelSiPsr.h"

CF_BOOL testInit(void) {
	printf("This is testInit \r\n");
	return TRUE;
}

CF_BOOL testOut(void) {
	printf("This is testOut \r\n");
	return TRUE;
}

CF_BOOL testClear(void) {
	printf("This is testClear \r\n");
	return TRUE;
}

void registerFunc(COM_CHFAC* p_fac) {
	if (p_fac == (COM_CHFAC*)0)
	{
		return;
	}
	p_fac->fac_c.ChFac_Init = testInit;
	p_fac->fac_c.ChFac_Out = testOut;
	p_fac->fac_c.ChFac_Clear = testClear;
	p_fac->fac_c.state = 0;
	p_fac->fac_c.pSiPsr = CreateComChSiPsr();
}

COM_CHFAC* CreateComChannelFac(void) {
	COM_CHFAC* p_myfac = malloc(sizeof(COM_CHFAC));
	memset(p_myfac, 0, sizeof(COM_CHFAC));
	registerFunc(p_myfac);
	p_myfac->fac_c.state = 1;
	return p_myfac;
}

void COM_CF_Process(void)
{
	COM_CHFAC* p_myfac = CreateComChannelFac();
	while (ChFac_Process((void*)&p_myfac->fac_c) > 0)
	{

	}
	free(p_myfac->fac_c.pSiPsr);
	free(p_myfac);
}
