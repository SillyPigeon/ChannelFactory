#include "ChannelFactory.h"
#include "ChannlSiParser.h"

CF_BOOL ChFac_Process(void* context)
{
	ChFac_Context* c = (ChFac_Context*)context;

	if (c == (ChFac_Context*)0)
	{
		return CF_FAILED;
	}

	switch (c->state)
	{
	case 1:
		if (c->ChFac_Init())
		{
			c->state++;
		}
		break;
	case 2:
		while (ChSiPsr_Main(c->pSiPsr) > 0);
		c->state++;
		break;
	case 3:
		if (c->ChFac_Out())
		{
			c->state++;
		}
		break;
	case 4:
		if (c->ChFac_Clear())
		{
			return CF_NO_ERR;
		}
		break;
	default:
		return CF_FAILED;
	}
	return CF_END;
}

