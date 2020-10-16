#include "Common.h"
#include "Key.h"
#include "Helpers.h"

#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>

const int LINE_NUM = 40;
int CURRENT_LINE_COUNT = 0;
bool escapeFlag = false;

enum class input_code
{
	invalid,
	standard,
	random,
	garbo,
	exit
};

input_code TranslateInput(std::string input)
{
	//Maybe also trim whitespace here for extra input validation
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	if (input == "standard")
		return input_code::standard;
	else if (input == "random")
		return input_code::random;
	else if (input == "garbo")
		return input_code::garbo;
	else if (input == "exit")
		return input_code::exit;
	else
		return input_code::invalid;
}

void PlayNote(std::wstring filename, bool complete)
{
	PlaySound(filename.c_str(), NULL, (complete ? SND_SYNC : SND_ASYNC));
}

bool ListenForKeypress(int keyCode)
{
	return (GetKeyState(keyCode) & 0x8000);
}

char EchoKey()
{
	//static int count = 0;

	char key = _getch();

	if (CURRENT_LINE_COUNT == LINE_NUM)
	{
		std::cout << "\n\t";
		CURRENT_LINE_COUNT = 0;
	}

	CURRENT_LINE_COUNT++;
	return key;
}

std::wstring GetRandomNote()
{
	std::string filename = "";
	std::string path = "Notes/";

	filename = "note" + std::to_string((std::rand() % 64 + 1)) + ".wav";

	std::wstring wFilename;

	Helpers::StringToWString(wFilename, path + filename);

	return wFilename;
}

std::wstring GetMappedNote(std::map<char, int> mappedKeys, char keyCode)
{
	std::string filename = "";
	std::string path = "Notes/";

	int keyIndex = mappedKeys[keyCode];

	filename = "note" + std::to_string(keyIndex) + ".wav";

	std::wstring wFilename;

	Helpers::StringToWString(wFilename, path + filename);

	return wFilename;
}

void GarboMode()
{
	//The worst mode
	std::cout << "Garbo Mode (Press ESC to stop playing)" << std::endl;
	std::cout << "\n\t";

	while (true)
	{
		char key = EchoKey();

		if (key == VK_ESCAPE)
		{
			break;
		}
		else
		{
			std::cout << key;
			PlayNote(GetRandomNote(), false);
		}
	}

	std::cout << "\n\nThank you for suffering! Please make another selection\n" << std::endl;
}

void RandoMode()
{
	//The fun mode
	std::cout << "Rando Mode (Press ESC to stop playing)" << std::endl;
	std::cout << "\n\t";

	std::array<int, 64> keyIndexes;

	for (int i = 0; i < 64; i++)
	{
		keyIndexes[i] = i + 1;
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(keyIndexes.begin(), keyIndexes.end(), std::default_random_engine(seed));
	//char* keysList = Helpers::GetKeyList();

	//std::array<char, 50> keys = {
	//	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, //0 - 9 keys
	//	0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, //A - J keys
	//	0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, //K - T keys
	//	0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0xBA, 0xBC, 0xBE, 0xBF, //U - Z keys, also ; , . /
	//	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, //0 - 9 Numpad keys
	//};

	std::array<char, 64> keyLetters = {
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z',
		'1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
		' ', '.'
	};

	std::map<char, int> mappedKeys;

	for (int i = 0; i < 64; i++)
	{
		mappedKeys.insert(std::pair<char, int>(keyLetters[i], keyIndexes[i]));
	}

	while (true)
	{
		char key = EchoKey();

		if (key == VK_ESCAPE)
		{
			break;
		}
		else
		{
			if (key == VK_RETURN)
			{
				std::cout << "\n\t";
				CURRENT_LINE_COUNT = 0;
			}
			else
			{
				std::cout << key;
				PlayNote(GetMappedNote(mappedKeys, key), false);
			}
			
		}
	}

	std::cout << "\n\nThank you for playing! Please make another selection\n" << std::endl;
}

int main()
{
	Helpers::DisplayTitle();
	Helpers::DisplayInstructions();

	while (true)
	{
		if (escapeFlag)
		{
			break;
		}

		std::cout << "\t";
		std::string inputSelection = "";
		std::cin >> inputSelection;

		input_code inputCode = TranslateInput(inputSelection);

		switch (inputCode)
		{
		case input_code::standard:
			std::cout << "This mode is not implemented yet (Sorry Im a shitter)" << std::endl;
			break;
		case input_code::random:
			//std::cout << "This mode is not implemented yet (Sorry Im a shitter)" << std::endl;
			RandoMode();
			break;
		case input_code::garbo:
			GarboMode();
			break;
		case input_code::exit:
			std::cout << "Exiting" << std::endl;
			escapeFlag = true;
		default:
			std::cout << "Please enter a valid selection" << std::endl;
			break;
		}
	}

	std::cout << "\n\nThanks for Playing!" << std::endl;

	std::cout << "\nPress ESC to close the program" << std::endl;
	std::cin.get();
}

#pragma region Reference Functions

//void PlayWavFile(const char* filename, bool complete)
//{
//	/*
//	SND_SYNC will not return until the sound completes.
//	SND_ASYNC will return immediately and play the sound
//	in the background.
//	*/
//	//PlaySound((LPCTSTR)filename, NULL, SND_FILENAME | (complete ? SND_SYNC : SND_ASYNC));
//	PlaySound((LPCWSTR)filename, NULL, SND_SYNC);
//}

#pragma endregion