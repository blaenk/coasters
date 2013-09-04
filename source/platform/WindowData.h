#ifndef WINDOW_DATA_H
#define WINDOW_DATA_H

struct WindowsData {
  HWND hWnd;
  HINSTANCE hInstance;
};

class WindowData {
public:
private:
  WindowsData *windowsData;
  LinuxData *linuxData;
  MacData *macData;
};

#endif