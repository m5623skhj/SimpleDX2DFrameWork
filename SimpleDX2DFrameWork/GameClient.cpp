#include "PreCompile.h"
#include "GameClient.h"

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
}

void GameClient::Stop()
{

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