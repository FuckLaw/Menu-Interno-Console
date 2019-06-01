enum Colors { BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, GREY, DARK_GREY, HGREY, HGREEN, HCYAN, HRED, HPURPLE, HYELLOW, WHITE };

void SetColor(int txcolor, int bgcolor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), txcolor + (bgcolor * 16));
}
