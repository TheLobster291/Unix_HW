#!/bin/bash

# define an abort function to call on error
abort_build()
{
    echo
    echo BUILD FAILED
    exit 1
}

# create obj and bin folders if non exiting, since
# the development tools will not create them themselves
mkdir -p obj
mkdir -p bin

echo
echo Compile the C code
echo --------------------------
compile HelloWorld.c -o obj/HelloWorld.asm || abort_build

echo
echo Assemble the ASM code
echo --------------------------
assemble obj/HelloWorld.asm -o obj/HelloWorld.vbin || abort_build

echo
echo Convert the PNG textures
echo --------------------------
png2vircon Texture-HelloWorld.png -o obj/Texture-HelloWorld.vtex || abort_build

echo
echo Convert the WAV sounds
echo --------------------------
wav2vircon Sound-HelloWorld.wav -o obj/Sound-HelloWorld.vsnd || abort_build

echo
echo Pack the ROM
echo --------------------------
packrom Tutorial01B-HelloWorldAdvanced.xml -o bin/Tutorial01B-HelloWorldAdvanced.v32 || abort_build

echo
echo BUILD SUCCESSFUL
