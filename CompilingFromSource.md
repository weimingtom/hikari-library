## Pre-Requisites ##

To compile Hikari from source, you will need the following:
  * The Hikari source _(see the Downloads tab)_
  * Microsoft Visual C++ 2005 _(if Express, you will need the Platform SDK too)_
  * The Ogre3D SDK
  * Flash Player 9

## Compiling ##

Open up the Hikari solution, select the build-mode from the drop-down (either `Debug` or `Release`) and select `Build -> Build Solution`.

If successful, you should find `Hikari.lib`/`Hikari.dll` (the release library) and `Hikari_d.lib`/`Hikari.dll` (the debug library) in the `Hikari\lib` directory. The demo should have also been built, the debug/release builds can be found in `HikariDemo\bin`.