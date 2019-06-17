#include "Application2D.h"
#include "ctime"
int main() {
	srand(unsigned int(time(NULL)));
	// allocation
	auto app = new Application2D();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}