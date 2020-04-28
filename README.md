# RuntimeBPs
This project allows for visual scripting in UE4 similar to Blueprints, but at runtime. The way this is set up does not make use of any UE4 boilerplate and could with a few adjustments be used in another engine.

Current engine version is 4.22

## How does it work?
I've tried to replicate UE4's Blueprint editor as close as possible for the end user. So for the end user, it should be very familiar to them if they've used UE4 Blueprints before.

Internally, each node is an UObject which contains its runtime data. Think of things like how many pins the node has, what pin is connected to what pin, and what the default value for each input pin is. These nodes then communicate and can be triggered by a starting node like Begin Play. When using multithreading, all execution is ran on one background thread, with the exception of code that is required to be run on the GameThread, like spawning an actor.

## Examples
**Mass spawning**

[![Mass spawning](https://img.youtube.com/vi/JL6fOXXktd4/0.jpg)](https://www.youtube.com/watch?v=JL6fOXXktd4)

**Grenade teleports**

[![Grenade teleports](https://img.youtube.com/vi/1zpZ1pBPDS0/0.jpg)](https://www.youtube.com/watch?v=1zpZ1pBPDS0)

## Features
- Functions exposed from C++
	- Latent functions
	- For Loops
	- Some common BP macros like FlipFlop & Sequence
	- Casts and support for inheritance (Can connect a child output to an input which wants a parent class)
- An extendable list of variable types
- Variables at runtime
	- Common variables like bool, int.
	- Structs like FVector, FTransform
	- Created object types like UObject, AActor
	- Asset files like UClass* & UStaticMesh*
	- Wildcards
- Support for arrays for both variables and functions
- Custom functions with local variables
- UEnum interpretation for C++ functions
- A basic editor based on the UE4 Blueprint editor
- Infinite loop checks
- Multithreading, enabled by default
- Saving & loading through Json
- A Python script allowing you to mass convert functions from existing function libraries to Runtime Blueprints function
- An example using a scriptable, throwable grenade.

## Things to note ##
- TLongUnion.h is generated based on Union.h in your engine source folder. You must have source files installed to generate this file.
- Instead of click, hold & drag for the connecting of nodes, you must click both input and output pins once in order to connect.
- A lot of code is pretty hacky. If you have some cleanup solutions and/or improvements, feel free to fork and make a PR.
- IntVector4D was added to make it a UStruct.
- Strings are not stored inside the union but are their separate variable, this because strings don't mix well with TUnion.
- Check out ExampleNodes.cpp & ExampleNodes.h 

## Frequently asked questions
**Q: Why isn't this a plugin?**

A: I have not made this a plugin because from my experience it is hard for a plugin to communicate with your project source code. I wanted to keep that flexibility in the case of adding a variable type that is defined in your project source and not the engine source.

**Q: Can I copy/paste Blueprints I've made in UE4?**

A: No. Not out of the box. UE4 blueprints store a lot more variables per node and some in a different way, one would need to make a conversion script to do so.

**Q: How performant is this compared to UE4 blueprints**

A: I've not tested this extensively, but the added overhead seems to be slightly worse than regular Blueprints. This is one of the reasons I've included multithread support.

**Q: Does this work in a networked game?**

A: The scripts are to be ran on the server only, with the intention that any replicated functions is merely called from the function and the game code does the rest.

**Q: Would you recommend using this for any game?**

A: With some pollish, and with the assumption you don't want to use a text-based scripting language, yes.

**Q: Why didn't you do it like X or Y?**

A: Probably because I didn't know about X or Y, if you have improvements to be made, feel free to fork and make a PR.

**Q: How can I contact you for questions and whatnot?**

A: I'm active in the Unreal Slackers Discord server (https://unrealslackers.org/). My tag is Moot#0021. Alternatively, you can ask questions on the UE4 forums. https://forums.unrealengine.com/community/community-content-tools-and-tutorials/1751725-runtime-blueprints-have-your-end-user-write-their-own-blueprint-scripts-to-use-in-your-game

**Q: Is replicating blueprint functionality legal?**

A: I've asked this question on the Answerhub a few years ago. I cannot guarantee you that using this is legal but according to the Answerhub there should be no issue: https://answers.unrealengine.com/questions/770458/view.html

**Q: What is the game in the last example?**

A: That's Contingency, a fan-made Halo game in UE4. I used to work with them so I used the game in that video to make a more practical example. Check them out at https://project-contingency.com/. The grenade teleport script is available in the source.

## Used resources
Multithreading: https://michaeljcole.github.io/wiki.unrealengine.com/Multi-Threading:_How_to_Create_Threads_in_UE4/

Wildcard structs: https://forums.unrealengine.com/community/community-content-tools-and-tutorials/27351-tutorial-how-to-accept-wildcard-structs-in-your-ufunctions

Barlow font: https://fonts.google.com/specimen/Barlow
