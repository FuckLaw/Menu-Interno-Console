string repeat_text(string s, int n)
{
	string s1 = s;

	for (int i = 1; i < n; i++)
		s += s1;

	return s;
}


void OpenConsole(string Title)
{
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	SetConsoleTitleA((LPCSTR)Title.c_str());
}


DWORD MyGetProcessId(LPCTSTR ProcessName) // non-conflicting function name
{
	PROCESSENTRY32 pt;
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pt.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hsnap, &pt)) { // must call this first
		do {
			if (!lstrcmpi(pt.szExeFile, ProcessName)) {
				CloseHandle(hsnap);
				return pt.th32ProcessID;
			}
		} while (Process32Next(hsnap, &pt));
	}
	CloseHandle(hsnap); // close handle on failure
	return 0;
}


void DrawMenu()
{
	//DWORD pid = MyGetProcessId(TEXT("D3D9Test.exe"));
	OpenConsole("MultiHack v1.0");
	ItemsMenu();
	while (true)
	{
		Hacks();
		Hotkey();
		if (MenuFunctions.Blink)
		{
			system("cls");
			cout << " "; // Começar Fora do canto da tela
			for (int i = 0; i < 30; i++)
			{
				cout << "_"; // Escrever 30 x '_'
			}
			cout << "\n"; // Pular linha para Terminar de desenhar a caixa


			for (int i = 1; i < MenuFunctions.Items + 1; i++) // Inicia o Desenho do Menu de acordo com o total de items
			{
				int Letter_counter = 0; // Conta quantas linhas obtem-se
				string str = MenuFunctions.Name[i]; // String atual do Menu
				for (int i = 0; str[i]; i++)
					Letter_counter++; // Somatória que resultará no Total de Letras abordado pela string
				if (MenuFunctions.Index == i) // Caso A Opção do Menu  esteja marcada Desenha-se uma Setinha
				{
					if (MenuFunctions.Variable[i] == true)
					{
						SetColor(GREEN, BLACK);
						cout << "| -> " << MenuFunctions.Name[i] << repeat_text(" ", (24 - Letter_counter)) << "ON|\n"; // Desenho da Seta
					}
					else
					{
						SetColor(RED, BLACK);
						cout << "| -> " << MenuFunctions.Name[i] << repeat_text(" ", (23 - Letter_counter)) << "OFF|\n"; // Desenho da Seta
					}
					cout << "\n";
				}
				else
				{
					if (MenuFunctions.Variable[i] == true)
					{
						SetColor(GREEN, BLACK);
						cout << "|    " << MenuFunctions.Name[i] << repeat_text(" ", (24 - Letter_counter)) << "ON|\n"; // Caso não Esteja marcado, não desenha a seta
					}
					else
					{
						SetColor(RED, BLACK);
						cout << "|    " << MenuFunctions.Name[i] << repeat_text(" ", (23 - Letter_counter)) << "OFF|\n"; // Caso não Esteja marcado, não desenha a seta
					}
					cout << "\n";
				}
			}

			cout << " "; //  Quebra linhas para desenhar o fundo do Menu
			for (int i = 0; i < 30; i++)
			{
				cout << "_"; // Escrever 30 x '_'
			}
			MenuFunctions.Blink = false;
			Sleep(30);
		}
	}
} 