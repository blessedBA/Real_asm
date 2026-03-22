
// GetProcAddress, (c) Ded, 2012

#include <windows.h>
#include <stdio.h>

int main (int argc, const char* argv[])
    {
    if (--argc < 2) return printf ("Usage: %s DLL Func\n", argv[0]), 1;

    HMODULE lib = LoadLibrary (argv[1]);
    if (!lib) return printf ("Error: Cannot load: \"%s\"\n", argv[1]);

    FARPROC addr = GetProcAddress (lib, argv[2]);
    if (!addr) return printf ("Error: Cannot find: \"%s\"\n", argv[2]);

    printf ("GetProcAddress %s %s %p\n", argv[1], argv[2], addr);

    return 0;
    }
