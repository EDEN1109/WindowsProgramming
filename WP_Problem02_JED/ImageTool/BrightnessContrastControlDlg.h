#pragma once


// CBrightnessContrastControlDlg 대화 상자

class CBrightnessContrastControlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBrightnessContrastControlDlg)

public:
	CBrightnessContrastControlDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBrightnessContrastControlDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BRIGHTNESS_CONTRAST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_nBrightness;
	CSliderCtrl m_sliderBrightness;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeEditBrightness();
	CSliderCtrl m_sliderContrast_2017136128;
	afx_msg void OnChangeEditContrast2017136128();
	int m_nContrast_2017136128;
	CEdit mEdit;
	CEdit mEdit2;
};
