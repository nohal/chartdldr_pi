Chart downloader plugin Plugin for OpenCPN
==========================================

# This plugin is now included in the main OpenCPN source tree. The code archived here is not maintained anymore, please use https://github.com/OpenCPN/OpenCPN to get the latest code and file bugs.







Compiling
=========
You have to be able to compile OpenCPN itself - Get the info at http://opencpn.org/ocpn/developers_manual

* This plugin now builds out of the OpenCPN source tree
```
git clone git://github.com/nohal/chartdldr_pi.git
```

###Build:
```
mkdir chartdldr_pi/build
cd chartdldr_pi/build
cmake .. # To produce a binary compatible with Windows XP, you must set the respective toolset - use 'cmake -T v120_xp ..'
cmake --build .
```
Windows note: You must place opencpn.lib into your build directory to be able to link the plugin DLL. You can get this file from your local OpenCPN build, or

Debugging:
If you check out the plugin source into the plugins subdirectory of your OpenCPN source tree, you can build it as part of it.

Windows Specific Libraries
--------------------------

Under windows, you must find the file "opencpn.lib" (Visual Studio) or "libopencpn.dll.a" (mingw) which is built in the build directory after compiling opencp

There are also some libraries and an external program needed:
http://sourceforge.net/projects/opencpnplugins/files/opencpn_packaging_data/cURL-vc12.7z/download

On Windows, also the CA certificates bundle must be part of the package. Get it from http://sourceforge.net/projects/opencpnplugins/files/chartdldr_pi/curl-ca-bundle.crt/download and place into the buildwin directory

For Mingw, only a single file "libcurl.dll" is needed for libcurl, for visual studio, several files. For visual Studio put all the files in opencpn\build\plugins\buildwin. You may have to create the buildwin directory first.

###Build on Mac OS X:
Tools: Can be installed either manually or from Homebrew (http://brew.sh)
```
#brew install git #If I remember well, it is already available on the system
brew install cmake
brew install gettext
ln -s /usr/local/Cellar/gettext/0.19.2/bin/msgmerge /usr/local/bin/msgmerge
ln -s /usr/local/Cellar/gettext/0.19.2/bin/msgfmt /usr/local/bin/msgfmt
```

To target older OS X versions than the one you are running, you need the respective SDKs installed. The easiest way to achieve that is using https://github.com/devernay/xcodelegacy

####Building wxWidgets
(do not use wxmac from Homebrew, it is not compatible with OpenCPN)
Get wxWidgets 3.0.x source from http://wxwidgets.org
Configure, build and install
```
cd wxWidgets-3.0.2
./configure --enable-unicode --with-osx-cocoa --with-macosx-sdk=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk/ --with-macosx-version-min=10.7 --enable-aui --disable-debug --enable-opengl
make
sudo make install
```

####Building the plugin
Before running cmake, you must set the deployment target to OS X 10.7 to be compatible with the libraries used by core OpenCPN
```
export MACOSX_DEPLOYMENT_TARGET=10.7
```

####Packaging on OS X
Get and install the Packages application from http://s.sudre.free.fr/Software/Packages/about.html
```
make create-pkg
```

License
=======
The plugin code is licensed under the terms of the GPL v2 or, at your will, later.

Icons made by Freepik (http://www.freepik.com) and Google (http://www.google.com) from Flaticon (http://www.flaticon.com) and are licensed under Creative Commons BY 3.0

UnRAR source code by Alexander L. Roshal      
      UnRAR source code may be used in any software to handle
      RAR archives without limitations free of charge, but cannot be
      used to develop RAR (WinRAR) compatible archiver and to
      re-create RAR compression algorithm, which is proprietary.
      Distribution of modified UnRAR source code in separate form
      or as a part of other software is permitted, provided that
      full text of this paragraph, starting from "UnRAR source code"
      words, is included in license, or in documentation if license
      is not available, and in source code comments of resulting package.

wxCurl licensed under wxWidgets Licence - Copyright (c) 2004 Casey O'Donnell. All rights reserved.

tinyxml - licensed under zlib license, original code by Lee Thomason (www.grinninglizard.com)
