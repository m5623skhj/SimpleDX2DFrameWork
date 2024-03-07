#pragma once
#include "NetClient.h"
#include "Queue.h"
#include <thread>

class GameClient : public CNetClient
{
public:
	GameClient();
	virtual ~GameClient() = default;

	void Start();
	void Stop();

	bool RecvPacket(CNetServerSerializationBuf** packet);
	void SendToServer(CNetServerSerializationBuf* packet);

public:
	int GetRecvQueueUseSize();

private:
	virtual void OnConnectionComplete();
	virtual void OnRelease();

	virtual void OnRecv(CNetServerSerializationBuf* outReadBuf);
	virtual void OnSend(int sendSize);

	virtual void OnWorkerThreadBegin();
	virtual void OnWorkerThreadEnd();
	virtual void OnError(st_Error* pError);

private:
	CListBaseQueue<CNetServerSerializationBuf*> recvQueue;

private:
	void HeartbeatThread();

private:
	std::thread heartbeatThread;

	HANDLE heartbeatExitEventHandle;
};