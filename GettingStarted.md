First [compile Hikari from source](CompilingFromSource.md).

Next, create a basic Ogre/OIS application (see the HikariDemo for an example).

For the debug build, you will need to link against the `Hikari_d.lib` you created earlier and copy `Hikari_d.dll` to the directory where you will run the executable.

Similarly, for the release build, you will need to link against the `Hikari.lib` you created earlier and copy `Hikari.dll` to the directory where you will run the executable.

In your application, add the `Hikari/include` path to your project's include directories. In your source, to include the entire Hikari API, simply declare:

```
#include "Hikari.h"
```

I highly recommend reading the documentation within `Hikari.h`, `FlashControl.h`, and `FlashValue.h`.


To instantiate the HikariManager singleton in your application, you will need to "new" it (similar to the Ogre Root singleton), specifying the directory that contains your flash movies/assets:

```
using namespace Hikari;

HikariManager* hikariMgr = new HikariManager("myFlashFiles");
```

If you specify a relative directory for your asset path, please remember to use a backslash instead of a forward slash in your path:

```
using namespace Hikari;

HikariManager* hikariMgr = new HikariManager("..\\media\\myFlashFiles");
```

Then, after you've created the HikariManager, Ogre::Root, camera, viewport, and scene-manager, you can create FlashControl overlays:

```
using namespace Hikari;

FlashControl* myControl = hikariMgr->createFlashOverlay("myControl", viewport, 300, 200, Position(Center), 0);

myControl->load("movie.swf");
```

Then, you need to update the HikariManager in your update loop:

```
hikariMgr->update();
```

And you also need to inject mouse input into the HikariManager, for example, this is how the HikariDemo does it:

```
bool HikariDemo::mouseMoved(const OIS::MouseEvent &arg)
{
	return hikariMgr->injectMouseMove(arg.state.X.abs, arg.state.Y.abs);
}

bool HikariDemo::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return hikariMgr->injectMouseDown(id);
}

bool HikariDemo::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return hikariMgr->injectMouseUp(id);
}
```

Finally, remember to delete the HikariManager singleton when your application shuts down.

```
~MyApplication
{
	if(hikariMgr)
		delete hikariMgr;
}
```