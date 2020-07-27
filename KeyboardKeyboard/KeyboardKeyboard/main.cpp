#include "Common.h"
#include "Key.h"
#include "Helpers.h"

#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>

const int LINE_NUM = 40;
bool escapeFlag = false;

enum class input_code
{
	invalid,
	standard,
	random,
	garbo,
	exit
};

std::wstring StringToWString(std::wstring& ws, const std::string& s)
{
	std::wstring wsTmp(s.begin(), s.end());
	ws = wsTmp;
	return ws;
}

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
	static int count = 0;

	char key = _getch();

	if (count == LINE_NUM)
	{
		std::cout << "\n\t";
		count = 0;
	}

	count++;
	return key;
}

std::wstring GetRandomNote()
{
	std::string filename = "";
	std::string path = "Notes/";

	filename = "note" + std::to_string((std::rand() % 64 + 1)) + ".wav";

	std::wstring wFilename;

	StringToWString(wFilename, path + filename);

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

		std::string inputSelection = "";
		std::cin >> inputSelection;

		input_code inputCode = TranslateInput(inputSelection);

		switch (inputCode)
		{
		case input_code::standard:
			std::cout << "This mode is not implemented yet (Sorry Im a shitter)" << std::endl;
			break;
		case input_code::random:
			std::cout << "This mode is not implemented yet (Sorry Im a shitter)" << std::endl;
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