#include <iostream>
#include <string>
#include <vector>
#include "Object.h"
#include "Item.h"

using namespace std;

int main() {
	Object cat("Cat", "A fluffy ginger cat named Vasya is lazily stretching on the floor.");
	Object note("Note", "You unfold the note and read: \"Dear roommate, I borrowed your sock for a art project. Check the balcony! - Cat Vasya\"");
	Object bed("Bed", "A neatly made single bed with a blue comforter. It looks comfortable and inviting.");
	Object nightstand("Nightstand", "A small wooden nightstand with a drawer. There's a lamp and an alarm clock on top.");
	Object wardrobe("Wardrobe", "A tall wooden wardrobe with two doors. It seems to contain your clothes and other personal items.");
	Object trashBin("Trash bin", "A plastic trash bin in the corner. It's mostly empty with just some crumpled papers inside.");
	Object sofa("Sofa", "A comfortable-looking sofa with soft cushions. Perfect for relaxing after a long day.");
	Object clothesline("Clothesline", "A drying clothesline stretched across the balcony. A single striped sock hangs from it, swaying gently in the breeze.");
	Object kitchenTable("Kitchen table", "A simple wooden kitchen table with a clean surface. A fruit bowl sits in the center.");
	Object sink("Sink", "A stainless steel kitchen sink. It's clean and dry, with a faucet that looks relatively new.");
	return 0;
}