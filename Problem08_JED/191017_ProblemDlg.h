
// 191017_ProblemDlg.h: 헤더 파일
//

#pragma once


// CMy191017ProblemDlg 대화 상자
class CMy191017ProblemDlg : public CDialogEx
{
// 생성입니다.
public:
	CMy191017ProblemDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY191017_PROBLEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedClear();
	afx_msg void OnClickedRegister();
	afx_msg void OnClickedSame();
	CEdit myEdit1;
	CEdit myEdit2;
	CEdit myEdit3;
	CEdit myEdit4;
	CEdit myEdit5;
	CEdit myEdit6;
	CEdit myEdit7;
	CButton checkBox;
};
