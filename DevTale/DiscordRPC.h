#pragma once
#include <Windows.h>
#include "DiscordSDK/cpp/discord.h"


class DiscordRPC
{
public:
	void Initalize();
	void Update();
	void UpdateNTPacket(std::string packet);
	//void MainLoop();

	std::string NTCharacterName = NULL;
};

