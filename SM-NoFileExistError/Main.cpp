#include <Windows.h>

extern "C" __declspec(dllexport) int __stdcall DllMain(HINSTANCE, unsigned long reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        const DWORD64 baseAddress = *reinterpret_cast<DWORD64*>(__readgsqword(0x60) + 0xCE0);
        const LPVOID address = reinterpret_cast<LPVOID>(baseAddress + 0x540B5E);

        DWORD oldProtect;
        VirtualProtect(address, 27, PAGE_EXECUTE_READWRITE, &oldProtect);
        memset(address, 0x90, 27);
    }

    return 1;
}
