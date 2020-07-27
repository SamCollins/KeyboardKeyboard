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
		"           |___/                                        |___/                             \n\n"
	<< std::endl;
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