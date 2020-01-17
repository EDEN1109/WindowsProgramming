
// mouseTrackingDlg.h: 헤더 파일
//

#pragma once
#include <queue>
using namespace std;

// CmouseTrackingDlg 대화 상자
class CmouseTrackingDlg : public CDialogEx
{
// 생성입니다.
public:
	CmouseTrackingDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOUSETRACKING_DIALOG };
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

private:
	CPoint absolute_point;
	bool is_tracking_mode = false;

	queue<LONG> x;
	queue<LONG> y;

	virtual BOOL PreTranslateMessage(MSG* pMsg);

public:
	// State of mouse tracking
	CStatic mState;
	// //ReplayBtn
	CButton mReplayBtn;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedReplay();
};
