// CatchColorDlg.h : header file
//

#if !defined(AFX_CATCHCOLORDLG_H__96CDD31D_59EB_42EA_AC17_0E2E11983885__INCLUDED_)
#define AFX_CATCHCOLORDLG_H__96CDD31D_59EB_42EA_AC17_0E2E11983885__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCatchColorDlg dialog

class CCatchColorDlg : public CDialog
{
// Construction
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CCatchColorDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data
	//{{AFX_DATA(CCatchColorDlg)
	enum { IDD = IDD_CATCHCOLOR_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatchColorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	CToolTipCtrl m_tooltip;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCatchColorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnAbout();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBtnColor();
	//}}AFX_MSG
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg LRESULT OnShowTask(WPARAM   wParam,LPARAM   lParam);
	DECLARE_MESSAGE_MAP()
private:
	HBRUSH m_Brush;
	int bValue;
	int gValue;
	int rValue;
	COLORREF m_color;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCHCOLORDLG_H__96CDD31D_59EB_42EA_AC17_0E2E11983885__INCLUDED_)
