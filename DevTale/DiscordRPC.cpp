#define _CRT_SECURE_NO_WARNINGS

#include <array>
#include <cassert>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <vector>

#include "discordRPC.h"

#include "DiscordSDK/cpp/discord.h"


#if defined(_WIN32)
#pragma pack(push, 1)
struct BitmapImageHeader {
    uint32_t const structSize{ sizeof(BitmapImageHeader) };
    int32_t width{ 0 };
    int32_t height{ 0 };
    uint16_t const planes{ 1 };
    uint16_t const bpp{ 32 };
    uint32_t const pad0{ 0 };
    uint32_t const pad1{ 0 };
    uint32_t const hres{ 2835 };
    uint32_t const vres{ 2835 };
    uint32_t const pad4{ 0 };
    uint32_t const pad5{ 0 };

    BitmapImageHeader& operator=(BitmapImageHeader const&) = delete;
};

struct BitmapFileHeader {
    uint8_t const magic0{ 'B' };
    uint8_t const magic1{ 'M' };
    uint32_t size{ 0 };
    uint32_t const pad{ 0 };
    uint32_t const offset{ sizeof(BitmapFileHeader) + sizeof(BitmapImageHeader) };

    BitmapFileHeader& operator=(BitmapFileHeader const&) = delete;
};
#pragma pack(pop)
#endif

std::vector<std::string> split(const std::string& s, char seperator)
{
    std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(seperator, pos)) != std::string::npos)
    {
        std::string substring(s.substr(prev_pos, pos - prev_pos));

        output.push_back(substring);

        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

    return output;
}

struct DiscordState {
    discord::User currentUser;
    std::unique_ptr<discord::Core> core;
};

namespace {
    volatile bool interrupted{ false };
}



void DiscordRPC::Initalize() {
    //"548904830064918640"

    return;
}
/*
void DiscordRPC::MainLoop(DiscordState state) {
    std::signal(SIGINT, [](int) { interrupted = true; });
    do {
        state.core->RunCallbacks();
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    } while (!interrupted);
}*/

void DiscordRPC::Update() {
    //default
    discord::Activity activity{};
    activity.SetDetails("Looking around");
    activity.SetState("Poopwings");
    activity.GetAssets().SetSmallImage("altw");
    activity.GetAssets().SetSmallText("Killrog");
    activity.GetAssets().SetLargeImage("logo");
    activity.GetAssets().SetLargeText("Lvl 99");
    activity.SetType(discord::ActivityType::Playing);
}

void DiscordRPC::UpdateNTPacket(std::string packet) {
    std::cout << "UpdateNTPacket " << packet << std::endl;
    std::vector<std::string> p = split(packet, ' ');

    //c_info Gorlik - -1 -1 - 3 0 1 0 2 1 27 0 0 0 0 0 0 0 0
    if (p[0] == "c_info") {
        NTCharacterName = p[1];        
    }
        

    //default
    discord::Activity activity{};
    activity.SetDetails("Looking around");
    activity.SetState("Poopwings");
    activity.GetAssets().SetSmallImage("altw");
    activity.GetAssets().SetSmallText(NTCharacterName.c_str());
    activity.GetAssets().SetLargeImage("logo");
    activity.GetAssets().SetLargeText("Lvl 99");
    activity.SetType(discord::ActivityType::Playing);

}




