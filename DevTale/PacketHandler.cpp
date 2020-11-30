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

#include "PacketHandler.h"
#include "DiscordRPC.h"

void devtale::PacketHandler::onPacketSend(std::string packet) const
{
	std::cout << "<Send> " << packet << std::endl;

	/*if (!form_->logSentPacketsCheckBox->Checked) return;
	String^ s = gcnew String(packet.c_str()) + "\r\n";
	if (!form_->enableSentPacketFilterCheckBox->Checked)
	{
		appendLog(s, false);
		return;
	}
	auto en = form_->filterSentPacketList->Items->GetEnumerator();
	while (en->MoveNext())
	{
		String^ filter = (String^)en->Current;
		if (s->Contains(filter))
		{
			if (form_->sentWhitelistRadio->Checked)
			{
				appendLog(s, false);
			}
			return;
		}
	}

	if (form_->sentBlacklistRadio->Checked)
	{
		appendLog(s, false);
	}
	*/
}

void devtale::PacketHandler::onPacketReceive(std::string packet) const
{
	std::cout << "<recv> " << packet << std::endl;

	//c_info Gorlik - -1 -1 - 3 0 1 0 2 1 27 0 0 0 0 0 0 0 0
	//std::string needle = "c_info";
	//if (packet.compare(0, needle.length(), needle) == 0)
		//g_Discord_->UpdateNTPacket(packet);

	/*
	if (!form_->logReceivedPacketsCheckBox->Checked) return;
	System::String^ s = gcnew String(packet.c_str()) + "\r\n";
	if (!form_->enableReceivedPacketFilterCheckBox->Checked)
	{
		appendLog(s, true);
		return;
	}
	auto en = form_->filterReceivedPacketList->Items->GetEnumerator();
	while (en->MoveNext())
	{
		String^ filter = (String^)en->Current;
		if (s->Contains(filter))
		{
			if (form_->receivedWhitelistRadio->Checked)
			{
				appendLog(s, true);
			}
			return;
		}
	}
	if (form_->receivedBlacklistRadio->Checked)
	{
		appendLog(s, true);
	}*/
}

void devtale::PacketHandler::appendLog(System::String^ packet, bool is_received) const
{
	if (form_->packetLogPrependDirectionCheckBox->Checked)
	{
		packet = (is_received ? "[R] " : "[S] ") + packet;
	}

	if (form_->packetLogPrependTimeCheckBox->Checked)
	{
		packet = "[" + System::DateTime::Now.ToLongTimeString() + "] " + packet;
	}

	form_->packetLogTextBox->AppendText(packet);
}
