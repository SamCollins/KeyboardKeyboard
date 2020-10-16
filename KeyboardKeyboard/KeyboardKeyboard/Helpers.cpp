#include "Helpers.h"
#include "Common.h"

void Helpers::DisplayTitle()
{
	std::cout << 
		"  _  __          _                         _   _  __          _                         _ \n" 
		" | |/ /___ _   _| |__   ___   __ _ _ __ __| | | |/ /___ _   _| |__   ___   __ _ _ __ __| |\n"
		" | ' // _ \\ | | | '_ \\ / _ \\ / _` | '__/ _` | | ' // _ \\ | | | '_ \\ / _ \\ / _` | '__/ _` |\n"
		" | . \\  __/ |_| | |_) | (_) | (_| | | | (_| | | . \\  __/ |_| | |_) | (_) | (_| | | | (_| |\n"
		" |_|\\_\\___|\\__, |_.__/ \\___/ \\__,_|_|  \\__,_| |_|\\_\\___|\\__, |_.__/ \\___/ \\__,_|_|  \\__,_|\n"
		"           |___/                                        |___/                             \n"
	<< std::endl;

	std::cout << "\tCreated By: Sam Collins (97%), Colson Fellers (2%), and Hayden Smith (1%)\n" << std::endl;
}

void Helpers::DisplayInstructions()
{
	std::cout << "Please make a selection\n" << std::endl;
	std::cout << "Standard Mode - Notes are properly mapped to the Keyboard (Code: standard)" << std::endl;
	std::cout << "Random Mode - Notes are randomly mapped to the Keyboard (Code: random)" << std::endl;
	std::cout << "Garbo Mode - Random keys play random notes (Code: garbo)" << std::endl;
	std::cout << "\nExit - Exit the program (Code: exit)\n" << std::endl;
	//std::cout << "\nPress ESC to exit\n" << std::endl;
}

std::wstring Helpers::StringToWString(std::wstring& ws, const std::string& s)
{
	std::wstring wsTmp(s.begin(), s.end());
	ws = wsTmp;
	return ws;
}

//char* Helpers::GetKeyList()
//{
//	std::array<char, 50> keys = {
//		0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, //0 - 9 keys
//		0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, //A - J keys
//		0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, //K - T keys
//		0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0xBA, 0xBC, 0xBE, 0xBF, //U - Z keys, also ; , . /
//		0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, //0 - 9 Numpad keys
//	};
//
//	return keys;
//}

//int Helpers::GetKeyList()
//{
//
//
//	return 0;
//}