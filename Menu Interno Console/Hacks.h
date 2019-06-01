void Hacks()
{
	if (MenuFunctions.Variable[1])
	{
		*(DWORD*)(0x08129B2C) = 999;
	}
}