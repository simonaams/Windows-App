#include <windows.h>
#include <string>
#include "dreptunghi.cpp"
#include <cstdlib>
#include "cerc.cpp"

using namespace std;
int a = 0;
HMENU hmenu; 

void IncarcaPoza();
void AddMenus(HWND); 
void AddControls(HWND hwnd); 


HWND button1;
HWND button2;
HWND button3;
HWND button4;
HWND button5;
HBITMAP hPozaLogo1, hPozaLogo2, hPozaBanner1, hPozaBanner2;
HICON hIcon;

HWND hDisplay1;
HWND hDisplay2;
HWND hEdit1;
HWND hEdit2;
HWND hEdit3;
HWND hEdit4;
HWND hEdit5;
HWND hEdit6;
HWND hLogo1;
HWND hLogo2;
HWND hBanner1;
HWND hBanner2;


dreptunghi figuraGeo;
cerc figuraGeo1;

char* concateneazaText(char *textIesire, char *textAdaugare);

// START FUNCTIE PRELUCRARE Mesaje - Pas 4
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_COMMAND:
		switch (wParam) {
		case 1:
			MessageBox(hwnd, "Ai apasat pe FILE", "mesaj catre utilizator", 4);
			break;
		case 2:
			MessageBox(hwnd, "Ai apasat pe EDIT", "mesaj catre utilizator", 4);
			break;
		case 3:
			MessageBox(hwnd, "Ai apasat pe VIEW", "mesaj catre utilizator", 4);
			break;
		case 4:
			MessageBox(hwnd, "Ai apasat pe HELP", "mesaj catre utilizator", 4);
			break;
		case 5:
			MessageBox(hwnd, "Ai apasat pe NEW", "mesaj catre utilizator", 4);
			break;
		case 6:
			MessageBox(hwnd, "Ai apasat pe OPEN", "mesaj catre utilizator", 4);
			break;
		case 7:
			MessageBox(hwnd, "Ai apasat pe SAVE", "mesaj catre utilizator", 4);
			break;
		case 8:
			DestroyWindow(hwnd);
			break;
		case 9:
			MessageBox(hwnd, "Ai apasat pe COPY", "mesaj catre utilizator", 4);
			break;
		case 10:
			MessageBox(hwnd, "Ai apasat pe PASTE", "mesaj catre utilizator", 4);
			break;
		case 11:
			MessageBox(hwnd, "Ai apasat pe CUT", "mesaj catre utilizator", 4);
			break;
		case 12:
			MessageBox(hwnd, "Ai apasat pe UNDO", "mesaj catre utilizator", 4);
			break;
		case 13:
			MessageBox(hwnd, "Ai apasat pe FULL SCREEN", "mesaj catre utilizator", 4);
			break;
		case 14:
			MessageBox(hwnd, "Ai apasat pe NOTIFICATIONS", "mesaj catre utilizator", 4);
			break;
		case 15:
			MessageBox(hwnd, "Ai apasat pe CALL CENTER", "mesaj catre utilizator", 4);
			break;
		case 16:
			MessageBox(hwnd, "Ai apasat pe Open TEXT", "mesaj catre utilizator", 4);
			break;
		case 17:
			MessageBox(hwnd, "Ai apasat pe Open JPEG", "mesaj catre utilizator", 4);
			break;
		case 18:
			MessageBox(hwnd, "Ai apasat pe Open PNG", "mesaj catre utilizator", 4);
			break;
		case 19:
			MessageBox(hwnd, "Ai apasat pe Open with", "mesaj catre utilizator", 4);
			break;
		case 20:
			MessageBox(hwnd, "Ai apasat pe Edit", "mesaj catre utilizator", 4);
			break;
		case 21:
			MessageBox(hwnd, "Ai apasat pe Run", "mesaj catre utilizator", 4);
			break;
		case 22:
			MessageBox(hwnd, "Ai apasat pe Open with", "mesaj catre utilizator", 4);
			break;
		case 23:
			MessageBox(hwnd, "Ai apasat pe Edit", "mesaj catre utilizator", 4);
			break;
		case 24:
			MessageBox(hwnd, "Ai apasat pe Run", "mesaj catre utilizator", 4);
			break;
		case 25:
			MessageBox(hwnd, "Ai apasat pe Open with", "mesaj catre utilizator", 4);
			break;
		case 26:
			MessageBox(hwnd, "Ai apasat pe Edit", "mesaj catre utilizator", 4);
			break;
		case 27:
			MessageBox(hwnd, "Ai apasat pe Run", "mesaj catre utilizator", 4);
			break;
		case 28:
			char bufferArie[10];
			int nr;
			wchar_t bufferText1[100];
			GetWindowText(hEdit1, (LPSTR)bufferText1, 100);
			wchar_t bufferText2[100];
			GetWindowText(hEdit2, (LPSTR)bufferText2, 100);
			//concateneazaText((char*)&bufferText1, (char*)&bufferText2);

			nr = MessageBox(hwnd, "Ati introdus corect datele?", "Mesaj pentru utilizator", MB_YESNO);
			if (nr == 6) {
				int latime = atoi((char*)bufferText1);
				int lungime = atoi((char*)bufferText2);
				figuraGeo.seteaza(latime, lungime);
				_itoa(figuraGeo.aria1(), bufferArie, 10);
				SetWindowText(hDisplay1, (LPSTR)bufferArie);
			}
			if (nr == 7) {
				SetWindowText(hDisplay1, (LPSTR)"Modifica latimea si lungimea");
			}
			break;
		case 29:
			if(hDisplay1 != NULL || hDisplay2 != NULL){
			SetWindowText(hDisplay1, "Arie Dreptunghi");
			SetWindowText(hDisplay2, "Arie Cerc");
			SetWindowText(hEdit1, "");
			SetWindowText(hEdit2, "");
			SetWindowText(hEdit3, "");
		}
			break;
		case 30:
			char bufferArie2[10];
			int no;
			wchar_t bufferText3[100];
			GetWindowText(hEdit3, (LPSTR)bufferText3, 100);

			no = MessageBox(hwnd, "Ati introdus corect datele?", "Mesaj pentru utilizator", MB_YESNO);
			if (no == 6) {
				int raza = atoi((char*)bufferText3);
				figuraGeo1.seteaza(raza);
				_itoa(figuraGeo1.aria1(), bufferArie2, 10);
				SetWindowText(hDisplay2, (LPSTR)bufferArie2);
			}
			if (no == 7) {
				SetWindowText(hDisplay2, (LPSTR)"Modifica raza");
			}
			break;
		}

	case WM_LBUTTONDOWN:

		break;

	case WM_MBUTTONDOWN: {
		a = a + 10;
		MessageBox(hwnd, "Ai apasat pe butonul din mijloc", "mesaj catre utilizator", 4);
		break;
	}
	case WM_RBUTTONDOWN: {
		a = a + 100;
		MessageBox(hwnd, "Ai apasat pe butonul din dreapta", "mesaj catre utilizator", MB_RETRYCANCEL);
		break;
	}
	case WM_CHAR:
	{
		if (wParam == VK_ESCAPE)
			SendMessage(hwnd, WM_CLOSE, 0, 0);
		return 0;
	}
	case WM_CREATE: {
		IncarcaPoza();
		AddMenus(hwnd);
		AddControls(hwnd);

		break;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hDC;
		char szBuffer[] = "Hello World!";
		strcpy(szBuffer, szBuffer + (char)a);
		hDC = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
		return 0;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:

			MessageBox(hwnd, "ai apasat tasta stanga", "mesaj utilizator", MB_YESNO);

			break;

		case VK_RIGHT:

			MessageBox(hwnd, "ai apasat tasta dreapta", "mesaj utilizator", MB_YESNOCANCEL);

			break;

		case VK_UP:

			MessageBox(hwnd, "ai apasat sageata sus", "mesaj utilizator", MB_YESNO);

			break;

		case VK_DOWN:

			MessageBox(hwnd, "ai apasat sageata jos", "mesaj utilizator", MB_YESNO);

			break;

		case VK_HOME:

			MessageBox(hwnd, "ai apasat tasta home", "mesaj utilizator", MB_YESNO);

			break;

		case VK_END:

			MessageBox(hwnd, "ai apasat tasta end", "mesaj utilizator", MB_CANCELTRYCONTINUE);

			break;

		case VK_INSERT:

			MessageBox(hwnd, "ai apasat tasta insert", "mesaj utilizator", MB_YESNO);

			break;

		case VK_DELETE:

			MessageBox(hwnd, "ai apasat tasta delete", "mesaj utilizator", MB_YESNO);

			break;

		case VK_F2:


			MessageBox(hwnd, "Ai apasat F2 : ", "Mesaj", MB_OKCANCEL);

			break;


			// Process other non-character keystrokes. 


		default:
			MessageBox(hwnd, "ati apasat orice alta tasta", "mesaj utilizator", MB_YESNO);
			break;
		}



	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}


int WINAPI WinMain(HINSTANCE hIns, HINSTANCE hPrev, LPSTR lpszArgument, int nCmdShow)
{
	char szClassName[] = "Mami";
	WNDCLASSEX wc;
	MSG messages;
	HWND hwnd;

	wc.hInstance = hIns;
	wc.lpszClassName = szClassName, wc.lpfnWndProc = WndProc;
	wc.style = CS_DBLCLKS, wc.cbSize = sizeof(WNDCLASSEX);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION), wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW), wc.lpszMenuName = NULL;
	wc.cbClsExtra = 0, wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	RegisterClassEx(&wc);


	hwnd = CreateWindow(szClassName, szClassName, WS_OVERLAPPEDWINDOW, 200, 0, 1000, 750, HWND_DESKTOP, NULL, hIns, NULL);
	ShowWindow(hwnd, nCmdShow);


	while (GetMessage(&messages, NULL, 0, 0))
	{
		TranslateMessage(&messages);
		DispatchMessage(&messages);
	}


	return messages.wParam;
}

void AddMenus(HWND hwnd) {
	hmenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hEditMenu = CreateMenu();
	HMENU hViewMenu = CreateMenu();
	HMENU hHelpMenu = CreateMenu();
	HMENU hOpenMenu = CreateMenu();
	HMENU hOpenTextMenu = CreateMenu();
	HMENU hOpenJPEGMenu = CreateMenu();
	HMENU hOpenPNGMenu = CreateMenu();

	AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hEditMenu, "Edit");
	AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hViewMenu, "View");
	AppendMenu(hmenu, MF_POPUP, (UINT_PTR)hHelpMenu, "Help");

	AppendMenu(hFileMenu, MF_STRING, 5, "New");
	AppendMenu(hFileMenu, MF_POPUP, (UINT_PTR)hOpenMenu, "Open");
	AppendMenu(hFileMenu, MF_STRING, 7, "Save");
	AppendMenu(hFileMenu, MF_STRING, 8, "Close");

	AppendMenu(hEditMenu, MF_STRING, 9, "Copy");
	AppendMenu(hEditMenu, MF_STRING, 10, "Paste");
	AppendMenu(hEditMenu, MF_STRING, 11, "Cut");
	AppendMenu(hEditMenu, MF_STRING, 12, "Undo");

	AppendMenu(hViewMenu, MF_STRING, 13, "Full Screen");
	AppendMenu(hViewMenu, MF_STRING, 14, "Notifications");

	AppendMenu(hHelpMenu, MF_STRING, 15, "Call Center");


	AppendMenu(hOpenMenu, MF_POPUP, (UINT_PTR)hOpenTextMenu, "Open TEXT");
	AppendMenu(hOpenMenu, MF_POPUP, (UINT_PTR)hOpenJPEGMenu, "Open JPEG");
	AppendMenu(hOpenMenu, MF_POPUP, (UINT_PTR)hOpenPNGMenu, "Open PNG");

	AppendMenu(hOpenTextMenu, MF_STRING, 19, "Open with");
	AppendMenu(hOpenTextMenu, MF_STRING, 20, "Edit");
	AppendMenu(hOpenTextMenu, MF_STRING, 21, "Run");

	AppendMenu(hOpenJPEGMenu, MF_STRING, 22, "Open with");
	AppendMenu(hOpenJPEGMenu, MF_STRING, 23, "Edit");
	AppendMenu(hOpenJPEGMenu, MF_STRING, 24, "Run");

	AppendMenu(hOpenPNGMenu, MF_STRING, 25, "Open with");
	AppendMenu(hOpenPNGMenu, MF_STRING, 26, "Edit");
	AppendMenu(hOpenPNGMenu, MF_STRING, 27, "Run");


	SetMenu(hwnd, hmenu);
}

void AddControls(HWND hwnd) {
	
	CreateWindowEx(0, "static", "Latime", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 200, 150, 20, hwnd, NULL, NULL, NULL);
	hEdit1 = CreateWindowEx(0, "EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 200, 150, 20, hwnd, NULL, NULL, NULL);
	CreateWindowEx(0, "static", "Lungime", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 230, 150, 20, hwnd, NULL, NULL, NULL);
	hEdit2 = CreateWindowEx(0, "EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 200, 230, 150, 20, hwnd, NULL, NULL, NULL);
	CreateWindowEx(0, "static", "Raza", WS_VISIBLE | WS_CHILD | WS_BORDER, 600, 200, 150, 20, hwnd, NULL, NULL, NULL);
	hEdit3 = CreateWindowEx(0, "EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 780, 200, 150, 20, hwnd, NULL, NULL, NULL);

	hLogo1 = CreateWindowExA(0, "static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,  20, 20, 150, 150, hwnd, NULL, NULL, NULL);
	SendMessage(hLogo1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hPozaLogo1);
	hLogo2 = CreateWindowExA(0, "static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 830, 20, 150, 150, hwnd, NULL, NULL, NULL);
	SendMessage(hLogo2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hPozaLogo2);

	hBanner1 = CreateWindowExA(0, "static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 220, 20, 560, 150, hwnd, NULL, NULL, NULL);
	SendMessage(hBanner1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hPozaBanner1);
	hBanner2 = CreateWindowExA(0, "static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP, 20, 510, 960, 150, hwnd, NULL, NULL, NULL);
	SendMessage(hBanner2, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hPozaBanner2);



	button1 = CreateWindow("button", "CALCULEAZA", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 115, 450, 100, 30, hwnd, (HMENU)28, NULL, NULL);
	button2 = CreateWindow("button", "RESET", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 435, 450, 100, 30, hwnd, (HMENU)29, NULL, NULL);
	button3 = CreateWindow("button", "CALCULEAZA", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 715, 450, 100, 30, hwnd, (HMENU)30, NULL, NULL);

	hDisplay1 = CreateWindowEx(0, "static", "Arie Dreptunghi", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 20, 270, 330, 150, hwnd, NULL, NULL, NULL);
	hDisplay2 = CreateWindowEx(0, "static", "Arie Cerc", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 600, 270, 330, 150, hwnd, NULL, NULL, NULL);

}
char* concateneazaText(char *textIesire, char *textAdaugare) {
	strcat(textIesire, " "); // Pentru spatiu dupa primul text
	strcat(textIesire, textAdaugare);
	return textIesire;
}

void IncarcaPoza() {
	hPozaLogo1 = (HBITMAP)LoadImageA(NULL, "logo1.bmp", IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
	hPozaLogo2 = (HBITMAP)LoadImageA(NULL, "logo2.bmp", IMAGE_BITMAP, 150, 150, LR_LOADFROMFILE);
	hPozaBanner1 = (HBITMAP)LoadImageA(NULL, "banner1.bmp", IMAGE_BITMAP, 560, 150, LR_LOADFROMFILE);
	hPozaBanner2 = (HBITMAP)LoadImageA(NULL, "banner2.bmp", IMAGE_BITMAP, 960, 150, LR_LOADFROMFILE);
	hIcon = (HICON)LoadImageA(NULL, "icon.bmp", IMAGE_ICON, 15, 15, LR_LOADFROMFILE);
}