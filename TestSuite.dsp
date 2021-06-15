# Microsoft Developer Studio Project File - Name="TestSuite" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=TestSuite - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TestSuite.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TestSuite.mak" CFG="TestSuite - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TestSuite - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "TestSuite - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TestSuite - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 dundas.lib gnu.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "TestSuite - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 dundas_debug.lib gnu_debug.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TestSuite - Win32 Release"
# Name "TestSuite - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CasePages.cpp
# End Source File
# Begin Source File

SOURCE=.\CaseSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\ComponentPages.cpp
# End Source File
# Begin Source File

SOURCE=.\ComponentSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsCommonGrid.cpp
# End Source File
# Begin Source File

SOURCE=.\OptionsIOGrid.cpp
# End Source File
# Begin Source File

SOURCE=.\OXCalendar.cpp
# End Source File
# Begin Source File

SOURCE=.\OXCalendarPopup.cpp
# End Source File
# Begin Source File

SOURCE=.\OXHookWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\OXItemTip.cpp
# End Source File
# Begin Source File

SOURCE=.\OXItemTipWnd.cpp
# End Source File
# Begin Source File

SOURCE=.\OXTreeCal.cpp
# End Source File
# Begin Source File

SOURCE=.\OXTreeCombo.cpp
# End Source File
# Begin Source File

SOURCE=.\OXTreeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\OXTreeEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\OXTreeHeader.cpp
# End Source File
# Begin Source File

SOURCE=.\OXTreeItem.cpp
# End Source File
# Begin Source File

SOURCE=.\ScriptPages.cpp
# End Source File
# Begin Source File

SOURCE=.\ScriptSheet.cpp
# End Source File
# Begin Source File

SOURCE=.\ScriptTree.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StepsGrid.cpp
# End Source File
# Begin Source File

SOURCE=.\SystemPropertiesDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TestSuite.cpp
# End Source File
# Begin Source File

SOURCE=.\TestSuite.rc
# End Source File
# Begin Source File

SOURCE=.\TestSuiteDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CasePages.h
# End Source File
# Begin Source File

SOURCE=.\CaseSheet.h
# End Source File
# Begin Source File

SOURCE=.\ComponentPages.h
# End Source File
# Begin Source File

SOURCE=.\ComponentSheet.h
# End Source File
# Begin Source File

SOURCE=.\OptionsCommonGrid.h
# End Source File
# Begin Source File

SOURCE=.\OptionsIOGrid.h
# End Source File
# Begin Source File

SOURCE=.\OXCalendar.h
# End Source File
# Begin Source File

SOURCE=.\OXCalendarPopup.h
# End Source File
# Begin Source File

SOURCE=.\OXDllExt.h
# End Source File
# Begin Source File

SOURCE=.\OXHookWnd.h
# End Source File
# Begin Source File

SOURCE=.\OXItemTip.h
# End Source File
# Begin Source File

SOURCE=.\OXItemTipWnd.h
# End Source File
# Begin Source File

SOURCE=.\OXMainRes.h
# End Source File
# Begin Source File

SOURCE=.\OXTreeCal.h
# End Source File
# Begin Source File

SOURCE=.\OXTreeCombo.h
# End Source File
# Begin Source File

SOURCE=.\OXTreeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\OXTreeEdit.h
# End Source File
# Begin Source File

SOURCE=.\OXTreeHeader.h
# End Source File
# Begin Source File

SOURCE=.\OXTreeItem.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ScriptPages.h
# End Source File
# Begin Source File

SOURCE=.\ScriptSheet.h
# End Source File
# Begin Source File

SOURCE=.\ScriptTree.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StepsGrid.h
# End Source File
# Begin Source File

SOURCE=.\SystemPropertiesDlg.h
# End Source File
# Begin Source File

SOURCE=.\TestSuite.h
# End Source File
# Begin Source File

SOURCE=.\TestSuiteDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\TestSuite.ico
# End Source File
# Begin Source File

SOURCE=.\res\TestSuite.rc2
# End Source File
# End Group
# End Target
# End Project
