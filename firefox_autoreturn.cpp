#include <windows.h>
#include <stdio.h>
#include <string.h>

double getReloadButtonDiff(HWND hwnd, bool menu) {
	const int left = 77, top = 46 + (menu ? 28 : 0);
	const int width = 17, height = 16;
	const int colortable[] = {
		0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xEEEEEF, 0xA6A6A7, 0x717173, 0x525254, 0x525254, 0x7C7C7D, 0xB0B0B0, 0xEEEEEF, 0xF9F9FA, 0xF9F9FA, 0x707072, 0x717173, 0xF9F9FA,
		0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xC4C4C5, 0x5D5D5E, 0x525254, 0x525254, 0x525254, 0x525254, 0x525254, 0x525254, 0x5D5D5E, 0xC4C4C5, 0xF9F9FA, 0x525254, 0x525254, 0xF9F9FA,
		0xF9F9FA, 0xF9F9FA, 0xBABABB, 0x525254, 0x525254, 0x868687, 0xC4C4C5, 0xF9F9FA, 0xEEEEEF, 0xC4C4C5, 0x7C7C7D, 0x525254, 0x525254, 0xCFCFD0, 0x525254, 0x525254, 0xF9F9FA,
		0xF9F9FA, 0xEEEEEF, 0x5D5D5E, 0x525254, 0xBABABB, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0x919191, 0x525254, 0x5D5D5E, 0x525254, 0x525254, 0xF9F9FA,
		0xF9F9FA, 0xA5A5A6, 0x525254, 0x868687, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0x7C7C7D, 0x525254, 0x525254, 0x525254, 0xF9F9FA,
		0xF9F9FA, 0x707072, 0x525254, 0xD8D8D9, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0x707072, 0x525254, 0x525254, 0x525254, 0x525254, 0x525254, 0x525254, 0xF9F9FA,
		0xF9F9FA, 0x525254, 0x525254, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0x707072, 0x525254, 0x525254, 0x525254, 0x525254, 0x525254, 0x707072, 0xF9F9FA,
		0xF9F9FA, 0x525254, 0x525254, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0x707072, 0x525254, 0xD8D8D9, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0xA5A5A6, 0x525254, 0x868687, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0xEEEEEF, 0x5C5C5D, 0x525254, 0xBABABB, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xAFAFAF, 0x868687, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0xF9F9FA, 0xBABABB, 0x525254, 0x525254, 0x868687, 0xD8D8D9, 0xF9F9FA, 0xF9F9FA, 0xD8D8D9, 0x868687, 0x525254, 0x525254, 0xE3E3E4, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xBABABB, 0x5C5C5D, 0x525254, 0x525254, 0x525254, 0x525254, 0x525254, 0x525254, 0x5C5C5D, 0xC4C4C5, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xEEEEEF, 0xA5A5A6, 0x707072, 0x525254, 0x525254, 0x707072, 0xA5A5A6, 0xEEEEEF, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA,
		0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA, 0xF9F9FA
	};

	// DIBSection 用 BITMAPINFO 構造体作成
	LPBITMAPINFO lpDIB = (LPBITMAPINFO)GlobalAlloc(GPTR, sizeof(BITMAPINFO));
	lpDIB -> bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	lpDIB -> bmiHeader.biWidth = width;
	lpDIB -> bmiHeader.biHeight = height;
	lpDIB -> bmiHeader.biPlanes = 1;
	lpDIB -> bmiHeader.biBitCount = 32;
	lpDIB -> bmiHeader.biCompression = BI_RGB;
	lpDIB -> bmiHeader.biSizeImage = 0;
	lpDIB -> bmiHeader.biXPelsPerMeter = 0;
	lpDIB -> bmiHeader.biYPelsPerMeter = 0;
	lpDIB -> bmiHeader.biClrUsed = 0;
	lpDIB -> bmiHeader.biClrImportant = 0;

	// DIB と対象ウィンドウの DC から DIBSection を作成
	LPBYTE lpBMP;
	HDC hdc = GetDC(hwnd);
	HBITMAP hBMP = CreateDIBSection(hdc, lpDIB, DIB_RGB_COLORS, (void **)&lpBMP, (HANDLE)NULL, 0);

	HDC hdcMem = CreateCompatibleDC(hdc); // メモリ DC を作成
	SelectObject(hdcMem, hBMP); // メモリ DC に DIBSection を選択

	// リロードボタンの部分を DIBSection のビットマップにコピー
	BitBlt(hdcMem, 0, 0, width, height, hdc, left, top, SRCCOPY);

	// リロードボタンの状態をチェック
	int sum = 0;
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			int i = (width * 4) * (height - y - 1) + x * 4;
			BYTE b = lpBMP[i];
			BYTE g = lpBMP[i + 1];
			BYTE r = lpBMP[i + 2];

			int table = colortable[y * width + x];
			int tr = (table >> 16 & 0xFF);
			int tg = (table >>  8 & 0xFF);
			int tb = (table       & 0xFF);

			sum += abs(tr - r) + abs(tg - g) + abs(tb - b);
		}
	}

	DeleteDC(hdcMem);
	DeleteObject(hBMP);
	DeleteDC(hdc);
	GlobalFree(lpDIB);

	return (double)sum / (width * height);
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lparam) {
	if(IsWindowVisible(hwnd)) {
		char buf[1024];
		GetWindowText(hwnd, buf, 1024);
		if(buf[0] != '\0') {
			printf("[%d] %s\n", hwnd, buf);
		}
	}

	return true;
}

void sendKey(HWND hwnd, bool menu) {
	if(hwnd == NULL || !IsWindowVisible(hwnd)) {
		printf("Target window not found (hwnd = %d)\n", hwnd);
		return;
	}

	int count = 0;
	while(true) {
		double r = getReloadButtonDiff(hwnd, menu);
		if(r < 1.0) {
			PostMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0);
			count += 1;
		} else {
			count = 0;
		}
		if(count >= 10) { break; }

		Sleep(1000);
	}
	printf("end\n");
}

int main(int argc, char* argv[]) {
	if(argc <= 1) {
		// 引数無しのときはウィンドウ一覧を出すだけ
		printf("usage: firefox_autoreturn.exe [-m] hwnd\n");
		printf("    -m : Menu bar is visible\n");
		printf("\n");
		EnumWindows(&EnumWindowsProc, 0);
	} else {
		bool menu = false;
		HWND hwnd = NULL;
		// コマンドライン引数の解析
		for(int i = 1; i < argc; i++) {
			if(strcmp(argv[i], "-m") == 0) {
				// メニューが表示されているかどうか
				menu = true;
				i++;
			} else if(atol(argv[i]) > 0) {
				// HWND の値 (整数)
				hwnd = (HWND)atol(argv[i]);
			}
		}
		sendKey(hwnd, menu);
	}

	return 0;
}
