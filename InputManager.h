#pragma once

class InputManager
{
private:
    static bool inputFlags[256];
public:

    static bool checkKeyFlag(const char& c)
    {
        return inputFlags[c];
    }

    static void registrateInput(const char& c)
    {
        inputFlags[c] = true;
    }

    static void unregistrateInput(const char& c)
    {
        inputFlags[c] = false;
    }
};


