#include "ChannlSiParser.h"

#define CHECK_IS_PARSE_FUNC_VALID(f)  if (!f){printf("FUNC_VALID ERR\r\n");return CF_FAILED;}
#define CHECK_IS_SI_PARSE_DONE()  if (c->u8state > c->u8Laststate){printf("parse is done\r\n");return CF_NO_ERR;}

#define CHANNEL_SI_PARSE_STEP(x)   case x:{ \
											CHECK_IS_SI_PARSE_DONE()\
											CHECK_IS_PARSE_FUNC_VALID(c->psrFunclist[x-1])\
											if (c->psrFunclist[x-1]())\
											{\
												c->u8state++;\
											}\
								  }break;

CF_RS ChSiPsr_Main(void* context)
{
	ChSiPsr_Context* c = (ChSiPsr_Context*)context;

	if (c == (ChSiPsr_Context*)0)
	{
		return CF_FAILED;
	}

	switch (c->u8state)
	{
		CHANNEL_SI_PARSE_STEP(1);
		CHANNEL_SI_PARSE_STEP(2);
		CHANNEL_SI_PARSE_STEP(3);
		CHANNEL_SI_PARSE_STEP(4);
		CHANNEL_SI_PARSE_STEP(5);
		CHANNEL_SI_PARSE_STEP(6);
		CHANNEL_SI_PARSE_STEP(7);
		CHANNEL_SI_PARSE_STEP(8);
		CHANNEL_SI_PARSE_STEP(9);
		CHANNEL_SI_PARSE_STEP(10);
		CHANNEL_SI_PARSE_STEP(11);
		CHANNEL_SI_PARSE_STEP(12);
		CHANNEL_SI_PARSE_STEP(13);
		CHANNEL_SI_PARSE_STEP(14);
		CHANNEL_SI_PARSE_STEP(15);
		CHANNEL_SI_PARSE_STEP(16);
		CHANNEL_SI_PARSE_STEP(17);
		CHANNEL_SI_PARSE_STEP(18);
		CHANNEL_SI_PARSE_STEP(19);
		CHANNEL_SI_PARSE_STEP(MAX_FUNC_NUM);
	default:
		return CF_FAILED;
	}
	return CF_END;
}


