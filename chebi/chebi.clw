; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChebiDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Chebi.h"

ClassCount=3
Class1=CChebiApp
Class2=CChebiDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_CHEBI_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_CHEBI_DIALOG (English (U.S.))

[CLS:CChebiApp]
Type=0
HeaderFile=Chebi.h
ImplementationFile=Chebi.cpp
Filter=N

[CLS:CChebiDlg]
Type=0
HeaderFile=ChebiDlg.h
ImplementationFile=ChebiDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_BUTTON2

[CLS:CAboutDlg]
Type=0
HeaderFile=ChebiDlg.h
ImplementationFile=ChebiDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg


[DLG:IDD_CHEBI_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CChebiDlg

[DLG:IDD_CHEBI_DIALOG (English (U.S.))]
Type=1
Class=CChebiDlg
ControlCount=4
Control1=IDC_SELECT_BUTTON,button,1342242816
Control2=IDC_TEXT_EDIT,edit,1350631552
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_BUTTON3,button,1342242816

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

