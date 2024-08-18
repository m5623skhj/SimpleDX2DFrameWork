#include "PreCompile.h"
#include "GameClient.h"
#include "Define.h"
#include "NetServerSerializeBuffer.h"
#include "Log.h"
#include <string_view>

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
	CNetClient::Stop();
}

bool GameClient::RecvPacket(CNetServerSerializationBuf** packet)
{
	std::lock_guard lock(recvQueueLock);
	if (recvQueue.GetRestSize() <= 0)
	{
		return false;
	}

	recvQueue.Dequeue(packet);

	return true;
}

void GameClient::SendToServer(CNetServerSerializationBuf* packet)
{
	SendPacket(packet);
}

int GameClient::GetRecvQueueUseSize()
{
	return recvQueue.GetRestSize();
}

void GameClient::OnConnectionComplete()
{

}

void GameClient::OnRelease()
{

}

void GameClient::OnRecv(CNetServerSerializationBuf* outReadBuf)
{
	CNetServerSerializationBuf::AddRefCount(outReadBuf);
	std::lock_guard lock(recvQueueLock);
	recvQueue.Enqueue(outReadBuf);
}

void GameClient::OnSend(int sendSize)
{
	UNREFERENCED_PARAMETER(sendSize);
}

void GameClient::OnWorkerThreadBegin()
{

}

void GameClient::OnWorkerThreadEnd()
{

}

void GameClient::OnError(st_Error* pError)
{
	const std::wstring_view logType(L"Write log type in here");

	_LOG(LOG_LEVEL::LOG_ERROR, logType.data(), L"Internal error : %d\nWindow error : %d\n"
	, pError->ServerErr, pError->GetLastErr);
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