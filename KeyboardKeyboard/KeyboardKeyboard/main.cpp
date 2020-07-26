#include "Common.h"
#include "Key.h"

#include <Windows.h>
#include <mmsystem.h>
#include <conio.h>

//using namespace Key;

//void PlayWavFile(const char* filename, bool complete);

const int LINE_NUM = 10;
bool escapeFlag = false;

std::wstring StringToWString(std::wstring& ws, const std::string& s)
{
	std::wstring wsTmp(s.begin(), s.end());

	ws = wsTmp;

	return ws;
}

void PlayWavFile(const char* filename, bool complete)
{
	/*
	SND_SYNC will not return until the sound completes.
	SND_ASYNC will return immediately and play the sound
	in the background.
	*/
	//PlaySound((LPCTSTR)filename, NULL, SND_FILENAME | (complete ? SND_SYNC : SND_ASYNC));
	PlaySound((LPCWSTR)filename, NULL, SND_SYNC);
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

	//std::cout << key;

	if (count == LINE_NUM)
	{
		std::cout << "\n";
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

int main()
{
	std::cout << "Playing Sound\n" << std::endl;

	while (true)
	{
		/*if (ListenForKeypress(VK_ESCAPE))
		{
			escapeFlag = true;
		}

		if (escapeFlag)
		{
			break;
		}
		else
		{
			std::cout << EchoKey();
			PlayNote(GetRandomNote(), false);
		}*/

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

	//PlaySound(wide.c_str(), NULL, SND_SYNC);

	std::cout << "\n\nFinished Playing" << std::endl;

	std::cin.get();
}

