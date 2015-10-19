# Introduction #

Hikari is a small yet powerful library that makes it easy to use [Flash](http://en.wikipedia.org/wiki/Adobe_Flash) content in [Ogre3D](http://www.ogre3d.org/). The possible applications include:
  * Create the interface for your game in Flash
  * Play Flash movies as cut-scenes in your game
  * Embed Flash mini-games in your game
  * Combine Flash with 3D to make novel interfaces
  * Use Flash for animated decals on 3D models

And it doesn't stop there! I'm excited to see what other uses people will dream up.

## Using Hikari ##
The basic overview of using Hikari:
  1. Design your content in Flash
  1. Export to SWF files.
  1. Create the HikariManager.
  1. Create a FlashControl for each SWF using the HikariManager.
  1. Load the SWF files into each respective FlashControl.
  1. Bind callbacks in ActionScript and C++.
  1. Inject mouse input into the HikariManager.
  1. Call HikariManager::update from your update loop.

## Features ##
The major features of Hikari are:
  * Efficient updating with dirty-rectangling
  * Full transparency support
  * Load the Flash ActiveX control from the registry or a local file
  * Create a FlashControl as a movable overlay or pure material
  * Bind C++ functions to handle function calls from ActionScript
  * Call ActionScript callbacks from C++
  * Support for basic ActionScript types (null, boolean, number, string)
  * International string support
  * Minimal impact on application size

## License ##
Hikari is licensed under the Lesser GNU Public License ([LGPL](http://en.wikipedia.org/wiki/GNU_Lesser_General_Public_License)) with one stipulation: if you use it, tell me about it! (email me: ajs15822 at gmail dot com)

## Implementation Details ##
For the curious, when you create a FlashControl using the HikariManager, this is what happens:
  1. The Flash ActiveX control is loaded (either from Flash.ocx in the working directory or from the registry).
  1. It is embedded into a Windowless OLE site.
  1. An event handler is bound to the OLE object to handle various Flash events.
  1. Invalidations are caught, the dirty area is expanded.
  1. Mouse input is injected by translating it into native window messages which are then sent directly to the Windowless site.
  1. Keyboard input is handled by directing all keyboard messages (using a message hook) to the focused FlashControl. (To accommodate complex keyboard input)
  1. During a global update, if a FlashControl is dirty, the dirty area is rendered and merged with an internal buffer, which is then blit to a dynamic texture using Ogre3D's facilities.