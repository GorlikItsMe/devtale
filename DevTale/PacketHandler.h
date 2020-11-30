// This file is part of DevTale.
// Copyright (c) 2019 Piotr "Xeno" Adamczyk
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once
#include "MainForm.h"

#include "vcclr.h"
#include <string>
#include "DiscordRPC.h"

namespace devtale
{
	class PacketHandler
	{
	public:
		/*PacketHandler(MainForm^ form)
		{
			form_ = form;
		}*/
		PacketHandler(DiscordRPC g_Discord)
		{
			g_Discord_ = g_Discord;
		}

		void onPacketSend(std::string packet) const;
		void onPacketReceive(std::string packet) const;

	private:
		gcroot<MainForm^> form_; // trezba do konca usunac
		DiscordRPC g_Discord_;
		void appendLog(String^ packet, bool is_received) const;
	};
}
