#include "PreCompile.h"
#include "GameClient.h"
#include "Define.h"

GameClient::GameClient()
{

}

GameClient::~GameClient()
{

}

void GameClient::Start()
{
	if (CNetClient::NetServerOptionParsing(L"OptionFile/GameClientOptionFile.txt") == false)
	{
		g_Dump.Crash();
	}

	heartbeatExitEventHandle = CreateEvent(NULL, TRUE, FALSE, NULL);
}

void GameClient::Stop()
{
	SetEvent(heartbeatExitEventHandle);
}

bool GameClient::RecvPacket(CNetServerSerializationBuf** packet)
{
	return true;
}

bool GameClient::SendToServer(CNetServerSerializationBuf* packet)
{
	return true;
}

int GameClient::GetRecvQueueUseSize()
{
	return 0;
}

void GameClient::OnConnectionComplete()
{

}

void GameClient::OnRelease()
{

}

void GameClient::OnRecv(CNetServerSerializationBuf* OutReadBuf)
{

}

void GameClient::OnSend(int sendsize)
{

}

void GameClient::OnWorkerThreadBegin()
{

}

void GameClient::OnWorkerThreadEnd()
{

}

void GameClient::OnError(st_Error* pError)
{

}

void GameClient::HeartbeatThread()
{
	while (true)
	{
		if (WaitForSingleObject(heartbeatExitEventHandle, heartbeatThreadAwakenMillisec) == WAIT_TIMEOUT)
		{
			// 서버에 하트비트 패킷 송신
		}
		else
		{
			break;
		}
	}
}