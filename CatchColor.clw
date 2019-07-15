; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCatchColorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CatchColor.h"

ClassCount=3
Class1=CCatchColorApp
Class2=CCatchColorDlg

ResourceCount=3
Resource2=IDD_ABOUT
Resource1=IDR_MAINFRAME
Class3=CAboutDlg
Resource3=IDD_CATCHCOLOR_DIALOG

[CLS:CCatchColorApp]
Type=0
HeaderFile=CatchColor.h
ImplementationFile=CatchColor.cpp
Filter=N

[CLS:CCatchColorDlg]
Type=0
HeaderFile=CatchColorDlg.h
ImplementationFile=CatchColorDlg.cpp
Filter=D
LastObject=CCatchColorDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_CATCHCOLOR_DIALOG]
Type=1
Class=CCatchColorDlg
ControlCount=15
Control1=IDC_STATIC_TEXT1,static,1350697473
Control2=IDC_STATIC_TEXT2,static,1350697473
Control3=IDC_STATIC_TEXT3,static,1350697473
Control4=IDC_MAGNIFIER,static,1350565892
Control5=IDC_SHOW,static,1350697473
Control6=IDC_BTN_ABOUT,button,1342275584
Control7=IDC_R,edit,1350633601
Control8=IDC_G,edit,1350641793
Control9=IDC_B,edit,1350641793
Control10=IDC_BTN_COLOR,button,1342275584
Control11=IDC_STATIC_TEXT4,static,1350697473
Control12=IDC_STATIC_TEXT5,static,1350697473
Control13=IDC_WEBCOLOR,edit,1350633609
Control14=IDC_X,edit,1350641793
Control15=IDC_Y,edit,1350641793

[DLG:IDD_ABOUT]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308865
Control3=IDC_STATIC,static,1342308865
Control4=IDC_STATIC,static,1342308865
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865

[CLS:CAboutDlg]
Type=0
HeaderFile=AboutDlg.h
ImplementationFile=AboutDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CAboutDlg

