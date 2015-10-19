## FlashValue Basics ##

`Hikari::FlashValue` is essentially a variant class that represents an ActionScript value. It supports the basic types of: `null`, `boolean`, `number`, and `string`. You check its type using `FlashValue::getType` and then you retrieve its value using `FlashValue::getBool`, `getNumber`, or `getString`. When declaring a `FlashValue` in C++, its type is determined automatically by how you initialize it (see `FlashValue.h` for more info).

`Hikari::Arguments` is just a typedef for a vector of `FlashValue`'s.

## Communicating from Flash to C++ ##

First, define your callback function in C++, it can be either a member function or a static function, it just needs to have the same signature as the example below:

```
FlashValue onPlayerLogin(FlashControl* caller, const Arguments& args)
{
	String username = args.at(0).getString();
	String password = args.at(1).getString();
	
	bool success = netManager.login(username, password);
	
	if(success)
		return "Welcome to the world!";
	else
		return "Incorrect username/password.";
}
```

Next, bind your callback function to a certain name on the desired `FlashControl`.

```
myFlashControl->bind("playerLogin", &onPlayerLogin);
```

Please note that if your callback function is a member function of some class, you need to declare the `FlashDelegate` explicitly like this (see `FlashControl.h` for more details):

```
myFlashControl->bind("playerLogin", FlashDelegate(this, &MyClass::onPlayerLogin));
```

Now you can call the C++ function "playerLogin" from ActionScript using `ExternalInterface.call('functionName')`:

```
function loginClick(event:MouseEvent):void
{
	caption.text = ExternalInterface.call("playerLogin", username, password);
}
```

Note that we are taking the return value of the C++ function we defined earlier (we returned a string-type) and assigning it to the text of a caption (which is also a string-type). It is important to match up your variable types when communicating across both languages.

## Communicating from C++ to Flash ##

First, define your callback function in ActionScript.

```
function setHP(hp:Number):void
{
	hpBar.value = hp;
}
```

Then, still in ActionScript, bind the function to a name using `ExternalInterface.addCallback('functionName', function)`:

```
ExternalInterface.addCallback("setHP", setHP);
```

Now you can call this function from C++ using `FlashControl::callFunction`.

```
myFlashControl->callFunction("setHP", Args(hpValue));
```

Note that `Hikari::Args` is a helper class that can be used to quickly declare `Hikari::Arguments` inline. The syntax for using it is something like this:
```
Args(arg1)(arg2)(arg3)(arg4)...
```

Also note that `FlashControl::callFunction` returns a `FlashValue`-- if the function call was successful, this will hold the return value from the actual ActionScript function call.