void Hotkey()
{
	if (GetAsyncKeyState(VK_UP) & 1)
	{
		MenuFunctions.Blink = true;
		if (MenuFunctions.Index == 1)
		{
			MenuFunctions.Index = MenuFunctions.Items;
			return;
		}
		MenuFunctions.Index--;
	}

	if (GetAsyncKeyState(VK_DOWN) & 1)
	{
		MenuFunctions.Blink = true;
		if (MenuFunctions.Index == MenuFunctions.Items)
		{
			MenuFunctions.Index = 1;
			return;
		}
		MenuFunctions.Index++;
	}


	if (GetAsyncKeyState(VK_LEFT) & 1)
	{
		MenuFunctions.Blink = true;
		MenuFunctions.Variable[MenuFunctions.Index] = false;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 1)
	{
		MenuFunctions.Blink = true;
		MenuFunctions.Variable[MenuFunctions.Index] = true;
	}
}