#include <MACE/MACE.h>
#include "Character.h"
#include "World.h"
#include "Boss.h"
#include "Main.h"

using namespace mc;

Character character = Character();
World world = World();
Boss boss = Boss();

void create(gfx::WindowModule& win) {
	win.getContext()->getRenderer()->setRefreshColor(Colors::LIGHT_BLUE);

	world.addChild(character);
	world.addChild(boss);
	win.addChild(world);
}

int main() {
	Instance instance = Instance();
	try {
		gfx::WindowModule::LaunchConfig config = gfx::WindowModule::LaunchConfig(600, 600, "Nick Sux");
		config.onCreate = &create;

		gfx::WindowModule module = gfx::WindowModule(config);
		instance.addModule(module);

		os::ErrorModule errModule = os::ErrorModule();
		instance.addModule(errModule);

		instance.start();
	} catch (const std::exception& e) {
		Error::handleError(e, instance);
		return -1;
	}
	return 0;
}

Boss & getBoss() {
	return boss;
}
