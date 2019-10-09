#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>
#include <iostream>

namespace devtale {

	class PacketHandler;

class Protocol
{
public:
	static Protocol* get();
	void send(char* packet) const;
	void send(const std::string& packet) const;
	void receive(char* packet) const;
	void receive(const std::string& packet) const;
	void setPacketHandler(PacketHandler* handler);


private:
	Protocol();

	void setup();
	static void hookedSend();
	static void hookedReceive();
	static void __fastcall onPacketSend(char* packet);
	static void __fastcall onPacketReceive(char* packet);
	DWORD _ptr = 0, _send = 0, _receive = 0;
	PacketHandler *handler_;
};

}