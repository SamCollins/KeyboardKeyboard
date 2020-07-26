#pragma once

class Key
{
private:
	int m_KeyCode;
	std::string m_Value;
public:
	Key(int keyCode, std::string value);
	std::string Press();
};

