#include "ComChannelSiPsr.h"

static int i = 0;


CF_BOOL testParseState1(void) {
	printf("This is testParseState1 i = %d\r\n", i++);
	if (i<=10)
	{
		return FALSE;
	}
	return TRUE;
}

CF_BOOL testParseState2(void) {
	i--;
	printf("This is testParseState2 i = %d\r\n", i);
	if (i > 0)
	{
		return FALSE;
	}
	return TRUE;
}

CF_BOOL testParseState3(void) {
	i = 2021;
	printf("This is testParseState3 i = %d\r\n", i);

	return TRUE;
}

COM_CHSIPSR* CreateComChSiPsr(void)
{
	COM_CHSIPSR* psr = malloc(sizeof(COM_CHSIPSR));
	memset(psr, 0, sizeof(COM_CHSIPSR));
	psr->ComPsr.psrFunclist[0] = testParseState1;
	psr->ComPsr.psrFunclist[1] = testParseState2;
	psr->ComPsr.psrFunclist[2] = testParseState3;
	psr->ComPsr.u8Laststate = 3;
	psr->ComPsr.u8state = 1;
	return psr;
}
