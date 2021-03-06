#ifndef __PROTOCOL_CS_H__
#define __PROTOCOL_CS_H__


/*   包结构命名规则 Jake.Sun
1) 请求(Request)						_SYN
2) 请求应答(Answer)					_ACK
3) 通知(Command)						-CMD
4) 广播(Broadcasting)				_BRD
*/


// --消息协议
#define		CS_CATEGORY_LENGTH		40
#define		WS_CATEGORY_LENGTH		50
#define		DS_CATEGORY_LENGTH		100

enum
{
	CS_CATEGORY_BASE	=	10,
	WS_CATEGORY_BASE	=	CS_CATEGORY_BASE + CS_CATEGORY_LENGTH,
	DS_CATEGORY_BASE	=	WS_CATEGORY_BASE + WS_CATEGORY_LENGTH,
};


enum eCS_CATEGORY
{
	CS_LOGON	= CS_CATEGORY_BASE,			// --登陆消息大类
	CS_MAX,
};


// --登录验证
enum eCS_LOGON
{
	S2C_SVR_READY_CMD		= 0,			// --S2C:服务器准备
	C2S_USER_AUTH_SYN		= 1,			// --C2S:认证请求
	S2C_USER_AUTH_ACK		= 2,			// --S2C:认证回复
	S2C_KICK_USER_CMD		= 4,			// --S2C:踢出账号

	C2S_TEST_ORDER_SYN		= 51,			// --C2S:测试下单
	C2S_TEST_ORDER_ACK		= 54,			// --S2C:测试下单回复
};


// --
enum eWS_CATEGORY
{
	WS_DATA	= WS_CATEGORY_BASE,				// --
	WS_MAX,
};


// --登录验证
enum eWS_AUTH
{
	W2S_WSCONNECTED_CMD	= 0,				// --W2S:Web服务器连接通知
	S2W_PUSHSVRAUTH_SYN	= 1,				// --S2W:推送服务器认证请求
	W2S_AUTH_RESULT_ACK	= 2,				// --W2S:推送服务器认证反馈
	W2S_NEWORDERBRD_CMD	= 4,				// --W2S:新增订单广播请求

	S2W_TEST_ORDER_SYN	= 52,				// --S2W:测试下单
};


#pragma pack(push,1)

//-------------------------------------------------------------------------------------------------------
// --基础包
// --最基础的 Packet,所有包的父类
struct MSG_BASE
{
	BYTE						m_byCategory;	// 协议分类
	BYTE						m_byProtocol;
};


/* 类名: MSG_SERVER_TYPE
 * 说明: 服务器间登陆消息，指示了服务器类型，ＩＤ，名称，最大玩家数相关信息
 */
struct MSG_SERVER_TYPE : public MSG_BASE
{
	BYTE						m_byServerType;					// 服务器类型
 	char						m_szServerName[32];				// 服务器名称
 	UINT16						m_nChanleID;					// 所属区ID
	UINT16						m_nServerID;					// 服务器ID	小区内必须唯一
	UINT16						m_nMaxPlayerCount;				// 服务器最大用户数量
};


struct MSG_DBPROXY_RESULT : public MSG_BASE
{
	void *						m_pData;
};


#pragma pack(pop)




#endif // __PROTOCOL_CL_H__


