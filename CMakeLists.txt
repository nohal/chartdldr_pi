##---------------------------------------------------------------------------
## Author:      Pavel Kalian
## Copyright:   2014
## License:     GPLv2 License
##---------------------------------------------------------------------------

# define minimum cmake version
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.2)

PROJECT(chartdldr_pi)

SET(PACKAGE_NAME chartdldr_pi)
SET(VERBOSE_NAME ChartDownloader)
SET(TITLE_NAME ChartDownloader)
SET(CPACK_PACKAGE_CONTACT "Pavel Kalian")

SET(VERSION_MAJOR "0")
SET(VERSION_MINOR "5")

#SET(CMAKE_BUILD_TYPE Debug)

INCLUDE("cmake/PluginConfigure.cmake")

SET(SRC_CHARTDLDR
            src/chartdldr_pi.h
            src/chartdldr_pi.cpp
            src/icons.h
            src/icons.cpp
            src/chartdldrgui.h
            src/chartdldrgui.cpp
            src/checkedlistctrl.cpp
            src/checkedlistctrl.h
            src/base64.h
            src/chartcatalog.cpp
            src/chartcatalog.h

            src/wxcurl/base.cpp
            src/wxcurl/dav.cpp
            src/wxcurl/davtool.cpp
            src/wxcurl/dialog.cpp
            src/wxcurl/ftp.cpp
            src/wxcurl/ftpparse.cpp
            src/wxcurl/ftptool.cpp
            src/wxcurl/http.cpp
            src/wxcurl/panel.cpp
            src/wxcurl/telnet.cpp
            src/wxcurl/thread.cpp
            src/wxcurl/utils.cpp
        )

IF(UNIX)
 INCLUDE("cmake/FindTinyXML.cmake")
 FIND_PACKAGE(TinyXML QUIET)
ENDIF(UNIX)

IF(TINYXML_FOUND)
 message (STATUS "Building with system tinyxml")
 INCLUDE_DIRECTORIES(${TINYXML_INCLUDE_DIR})
 ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_CHARTDLDR})
 TARGET_LINK_LIBRARIES(${PACKAGE_NAME} ${TINYXML_LIBRARIES} )
ELSE(TINYXML_FOUND)
 message (STATUS "Building with embedded tinyxml")
 INCLUDE_DIRECTORIES(src/tinyxml/)
 SET(SRC_LTINYXML
            src/tinyxml/tinyxml.cpp
            src/tinyxml/tinyxmlparser.cpp
            src/tinyxml/tinyxmlerror.cpp
 )
 ADD_LIBRARY(${PACKAGE_NAME} SHARED ${SRC_CHARTDLDR} ${SRC_LTINYXML})
ENDIF(TINYXML_FOUND)
ADD_DEFINITIONS(-DTIXML_USE_STL)


INCLUDE("cmake/PluginInstall.cmake")
INCLUDE("cmake/PluginCurl.cmake")
INCLUDE("cmake/PluginLocalization.cmake")
INCLUDE("cmake/PluginPackage.cmake")
