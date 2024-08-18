#pragma once
#include "NetClient.h"
#include "Queue.h"
#include <thread>
#include "ManagerDefine.h"
#include <mutex>

class GameClient : public CNetClient
{
	NON_COPYABLE_WITH_NON_DESTRUCTOR(GameClient);
protected:
	virtual ~GameClient() = default;

public:
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
	std::mutex recvQueueLock;

private:
	void HeartbeatThread();

private:
	std::thread heartbeatThread;

	HANDLE heartbeatExitEventHandle;
};