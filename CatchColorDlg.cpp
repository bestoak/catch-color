// CatchColorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CatchColor.h"
#include "CatchColorDlg.h"

#include "AboutDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define UM_SHOWTASK WM_USER+1

/////////////////////////////////////////////////////////////////////////////
// CCatchColorDlg dialog

CCatchColorDlg::CCatchColorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCatchColorDlg::IDD, pParent)
{
	rValue=255;
	gValue=255;
	bValue=255;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCatchColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCatchColorDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_ABOUT, OnBtnAbout)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BTN_COLOR, OnBtnColor)
	ON_WM_SYSCOMMAND()
	ON_MESSAGE(UM_SHOWTASK,OnShowTask)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatchColorDlg message handlers

BOOL CCatchColorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	SetTimer(1,50,NULL);
	SetWindowPos(&this->wndTopMost,0,0,0,0,SWP_NOSIZE);

	// CG: The following block was added by the ToolTips component.
	{
		// Create the ToolTip control.
		m_tooltip.Create(this);
		m_tooltip.Activate(TRUE);

		m_tooltip.AddTool(GetDlgItem(IDC_BTN_COLOR), "Color Picker");
		m_tooltip.AddTool(GetDlgItem(IDC_BTN_ABOUT), "About Author");
	}


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCatchColorDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCatchColorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCatchColorDlg::OnBtnAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}



void CCatchColorDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	POINT colorPoint;
	::GetCursorPos(&colorPoint);
	CWindowDC dc(GetDesktopWindow());
	m_color   =   dc.GetPixel(colorPoint);
	rValue=GetRValue(m_color); 
    gValue=GetGValue(m_color); 
    bValue=GetBValue(m_color); 

	CString strR,strG,strB,x,y,webColor;
	strR="";
	strG="";
	strB="";
	x="";
	y="";
	webColor="";
	char webR[3],webG[3],webB[3];
	memset(webR,0,3);
	memset(webG,0,3);
	memset(webB,0,3);

	strR.Format("%d",rValue);
	strG.Format("%d",gValue);
	strB.Format("%d",bValue);

	x.Format("%d",colorPoint.x);
	y.Format("%d",colorPoint.y);

	_itoa(rValue,webR,16);
	_itoa(gValue,webG,16);
	_itoa(bValue,webB,16);


		if(rValue<=15 && gValue>15 && bValue>15)
		{
            webColor.Format("#0%s%s%s",&webR,&webG,&webB);
		}
		else if(gValue<=15 && rValue>15 && bValue>15)
		{
            webColor.Format("#%s0%s%s",&webR,&webG,&webB);
		}
		else if(bValue<=15 && gValue>15 && rValue>15)
		{
            webColor.Format("#%s%s0%s",&webR,&webG,&webB);
		}
		else if(rValue<=15 && gValue<=15 && bValue>15)
		{
            webColor.Format("#0%s0%s%s",&webR,&webG,&webB);
		}
		else if(rValue<=15 && gValue>15 && bValue<=15)
		{
            webColor.Format("#0%s%s0%s",&webR,&webG,&webB);
		}
		else if(gValue<=15 && rValue>15 && bValue<=15)
		{
            webColor.Format("#%s0%s0%s",&webR,&webG,&webB);
		}
		else if(gValue<=15 && bValue>15 && rValue<=15)
		{
            webColor.Format("#0%s0%s%s",&webR,&webG,&webB);
		}
		else if(bValue<=15 && gValue<=15 && rValue>15)
		{
            webColor.Format("#%s0%s0%s",&webR,&webG,&webB);
		}
		else if(bValue<=15 && gValue>15 && rValue<=15)
		{
            webColor.Format("#0%s%s0%s",&webR,&webG,&webB);
		}
		else if(bValue<=15 && gValue<=15 && rValue<=15)
		{
            webColor.Format("#0%s0%s0%s",&webR,&webG,&webB);
		}
		else if(bValue>15 && gValue>15 && rValue>15)
		{
		    webColor.Format("#%s%s%s",&webR,&webG,&webB);
		}


	GetDlgItem(IDC_R)->SetWindowText(strR);
	GetDlgItem(IDC_G)->SetWindowText(strG);
	GetDlgItem(IDC_B)->SetWindowText(strB);
	GetDlgItem(IDC_X)->SetWindowText(x);
	GetDlgItem(IDC_Y)->SetWindowText(y);
	GetDlgItem(IDC_WEBCOLOR)->SetWindowText(webColor);

	CStatic*  m_pStatic=(CStatic*)GetDlgItem(IDC_SHOW);   
    m_pStatic->RedrawWindow();   
	
	HDC  hdc;
	RECT rect;
	::GetClientRect(::GetDlgItem(m_hWnd,IDC_MAGNIFIER),&rect);
	hdc=::GetDC(::GetDlgItem(m_hWnd,IDC_MAGNIFIER));     
	::StretchBlt(hdc,0,0,rect.right,rect.bottom,dc,colorPoint.x-15,colorPoint.y-15,30,30,SRCCOPY);
	CPen pen(PS_INSIDEFRAME,1,RGB(255-rValue,255-gValue,255-bValue));
	CClientDC clidc(GetDlgItem(IDC_MAGNIFIER));
	clidc.SelectObject(&pen);
	clidc.MoveTo(rect.right/2-7,rect.bottom/2);
	clidc.LineTo(rect.right/2+7,rect.bottom/2);
	clidc.MoveTo(rect.right/2,rect.bottom/2-7);
	clidc.LineTo(rect.right/2,rect.bottom/2+7);

	CDialog::OnTimer(nIDEvent);
}

HBRUSH CCatchColorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if   (nCtlColor==CTLCOLOR_STATIC)   
	{   
		if   (pWnd->GetDlgCtrlID()==IDC_SHOW)   
		{   
			pDC->SetBkMode   (TRANSPARENT);   
			m_Brush   =   CreateSolidBrush   (RGB   (rValue,gValue,bValue));   
			return   m_Brush;
		}   
	}
	return hbr;
}

void CCatchColorDlg::OnBtnColor() 
{
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_FULLOPEN ;
	dlg.DoModal();
}

BOOL CCatchColorDlg::PreTranslateMessage(MSG* pMsg)
{
	// CG: The following block was added by the ToolTips component.
	{
		// Let the ToolTip process this message.
		m_tooltip.RelayEvent(pMsg);
	}
	return CDialog::PreTranslateMessage(pMsg);	// CG: This was added by the ToolTips component.
}

void CCatchColorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
    if(nID   ==   SC_MINIMIZE)
	{
		NOTIFYICONDATA   nid;   
		nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);   
		nid.hWnd=this->m_hWnd;   
		nid.uID=IDR_MAINFRAME;   
		nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP   ;   
		nid.uCallbackMessage=UM_SHOWTASK;
		nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));   
		strcpy(nid.szTip,"CatchColor");
		Shell_NotifyIcon(NIM_ADD,&nid);
		ShowWindow(SW_HIDE);
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

LRESULT   CCatchColorDlg::OnShowTask(WPARAM   wParam,LPARAM   lParam)   
{   
	if(wParam!=IDR_MAINFRAME)   
		return   1;   
	switch(lParam)   
	{   
	case   WM_RBUTTONUP:
		{   
			
			LPPOINT   lpoint=new   tagPOINT;   
			::GetCursorPos(lpoint);
			CMenu   menu;   
			menu.CreatePopupMenu();
		
			menu.AppendMenu(MF_STRING,ID_MENU_SHOW,"Show");
			menu.AppendMenu(MF_STRING,ID_MENU_QUIT,"Quit");    

			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);   

			HMENU   hmenu=menu.Detach();   
			menu.DestroyMenu();   
			delete   lpoint;   
		}   
		break;  
	case   WM_LBUTTONDOWN:
		{   

		  NOTIFYICONDATA   nid;   
          nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);   
          nid.hWnd=this->m_hWnd;   
          nid.uID=IDR_MAINFRAME;   
          nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP   ;   

          nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));   

          Shell_NotifyIcon(NIM_DELETE,&nid);
          ShowWindow(SW_SHOW);
		}   
		break;   
	}   
	return   0;   
}   

BOOL CCatchColorDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(ID_MENU_QUIT==LOWORD(wParam) && 0==HIWORD(wParam))
	{
	  	  NOTIFYICONDATA   nid;   
          nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);   
          nid.hWnd=this->m_hWnd;   
          nid.uID=IDR_MAINFRAME;   
          nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP   ;   

          nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));   

          Shell_NotifyIcon(NIM_DELETE,&nid);
          //ShowWindow(SW_SHOW);
		  SendMessage(WM_CLOSE,0,0);
	}

	if(ID_MENU_SHOW==LOWORD(wParam) && 0==HIWORD(wParam))
	{
		  NOTIFYICONDATA   nid;   
          nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);   
          nid.hWnd=this->m_hWnd;   
          nid.uID=IDR_MAINFRAME;   
          nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP   ;   
          
          nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));   
          
          Shell_NotifyIcon(NIM_DELETE,&nid);

          ShowWindow(SW_SHOW);
	}
	
	return CDialog::OnCommand(wParam, lParam);
}
