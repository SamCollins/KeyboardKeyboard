#pragma once

#include "Key.h";

class Keyboard
{
private:
	Key Keys;
public:
	Keyboard();
	Keyboard(const Keyboard& other);
	Keyboard(Keyboard&& other);
	void InitKeys();
	Keyboard GetKeyboard();
	void RandomizeKeys();
};