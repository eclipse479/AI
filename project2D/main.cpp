#include "Application2D.h"
#include "heap.h"
#include "ctime"
int main() {
	// allocation
	srand(unsigned int(time(NULL)));
	//auto [a_left, a_right] = h.childrenOf(10);


	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}