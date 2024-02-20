#pragma once
#include "NetClient.h"
#include "Queue.h"

class GameClient : public CNetClient
{
public:
	GameClient();
	virtual ~GameClient();

	void Start();
	void Stop();

	bool RecvPacket(CNetServerSerializationBuf** packet);
	bool SendToServer(CNetServerSerializationBuf* packet);

public:
	int GetRecvQueueUseSize();

private:
	virtual void OnConnectionComplete();
	virtual void OnRelease();

	virtual void OnRecv(CNetServerSerializationBuf* OutReadBuf);
	virtual void OnSend(int sendsize);

	virtual void OnWorkerThreadBegin();
	virtual void OnWorkerThreadEnd();
	virtual void OnError(st_Error* pError);

private:
	CListBaseQueue<CNetServerSerializationBuf*> recvQueue;
};