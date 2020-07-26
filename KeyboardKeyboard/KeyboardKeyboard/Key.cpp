#include "Common.h"
#include "Key.h"

Key::Key(int keyCode, std::string value)
	: m_KeyCode(keyCode), m_Value(value)
{};

std::string Key::Press()
{
	return m_Value;
}
