VS Code in Linux with GCC Compiler : 
1) Install GCC(one of the compilers used in linux) - use command - sudo apt-get install build-essential 
2) To target C++ 20 - use latest version of gcc - use gcc 10 atleast . use command : sudo apt-get install gcc-10 g++-10 . 
    Here, G++ is for C++ , GCC will work only for C.
3) Install gdb debugger . Use command - sudo apt-get install gdb . 
4) Go to Terminal tab of VS-Code. Then Go to Configure Task. Select compilers, currently we are interested in g++10 or above so select that.  Edit taks.json. 
Use the following basic template to configure VS-Code for CPP20 -

{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: g++-11 build active file",
			"command": "/usr/bin/g++-11",
			"args": [
				"-fdiagnostics-color=always",
				"-g",
				"-std=c++20",
				"${file}",
				"-o",
				"${fileDirname}/${fileBasenameNoExtension}"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: /usr/bin/g++-11"
		}
	]
}

5) Also, Go to View tab of VS-Code . Select command-pallete. Select C/C++ Edit Configuration. Configure C++ Standard for C++20.

6) Now to run - Go to terminal of VS-Code. Select Run-Task. It generates binary file . Run binary file like - ./binary_file.

VS Code in Windows with MSVC Compiler Setup :

1)Open Developer Powershell in Windows . Type "code ." . This is going to open Visual Code in a mode where it knows the path of the compiler from Microsoft.
To verify it . Open Terminal in VS Code and type cl.exe. It will print few info about compiler.
Example -

PS C:\Users\mahxhm\source\repos> cl.exe
Microsoft (R) C/C++ Optimizing Compiler Version 19.29.30147 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

usage: cl [ option... ] filename... [ /link linkoption... ]

2)Select Configure Task from Terminal and Select C/C++ cl.exe build active. Update the tasks.json with -

{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "cppbuild",
      "label": "Build With MSVC Compiler",
      "command": "cl.exe",
      "args": [
        "/Zi",
        "/std:c++latest",
        "/EHsc",
        "/nologo",
        "/Fe${fileDirname}\\\\${fileBasenameNoExtension}.exe",
        "${file}"
      ],
      "options": {
        "cwd": "${fileDirname}"
      },
      "problemMatcher": [
        "$msCompile"
      ],
      "group": "build",
      "detail": "compiler: cl.exe"
    }
  ]
}

VS Code in Windows with GCC and Clang Compiler Setup :

1. Go to https://winlibs.com/
2. Go to Section UCRT runtime under Downloads and select latest archive with LLVM-Clang.
3. Extract the downloaded archive. Go to Ming64 bin folder. In bin folder we can find clang++ and g++ compiler present.
4. Now to make them available from any location in System , we need to add them in Environment Variable. So type Environment Variable in Task Bar Search. Open the Dialog.
Go to System Variable- Go to path Variable- Select Edit - Add the path to bin folder of mingw64.
5. To check whether clang compiler and g++ compiler working as it should open powershell and type - g++ --version .We can see the version.
Example -
g++.exe (MinGW-W64 x86_64-ucrt-mcf-seh, built by Brecht Sanders) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions. There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

6)Select Configure Task from Terminal and Select C/C++ cl.exe build active. Update the tasks.json with -
For GCC -
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "Build With G++ 11.2 Compiler to support CPP20",
			"command": "C:\\mingw64\\bin\\g++.exe",
			"args": [
				"-g",
				"-std=c++20",
				"${file}",
				"-o",
				"${fileDirname}\\${fileBasenameNoExtension}.exe"
			],
			"options": {
				"cwd": "C:\\mingw64\\bin"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: C:\\mingw64\\bin\\g++.exe"
		}
	]
}
For Clang -

{
			"type": "cppbuild",
			"label": "Build with Clang 12.01 Compiler",
			"command": "C:\\mingw64\\bin\\clang++.exe",
			"args": [
				"-g",
				"-std=c++20",
				"${file}",
				"-o",
				"${fileDirname}\\${fileBasenameNoExtension}.exe"
			],
			"options": {
				"cwd": "C:\\mingw64\\bin\\"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": "build",
			"detail": "compiler: C:\\mingw64\\bin\\clang++.exe"
		}

1. To run - Select Run Task from Terminal and Select Build With MSVC Compiler(basically the label name which we have given in tasks.json).
8)Also, to solve Intellisense related C++20 issue - Go to View - Select Command Pallete - Select C/C++ Configuration(UI)-Select C++ Standard to C++20.