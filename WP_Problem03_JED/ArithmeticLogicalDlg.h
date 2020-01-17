#pragma once


// CArithmeticLogicalDlg 대화 상자

class CArithmeticLogicalDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CArithmeticLogicalDlg)

public:
	CArithmeticLogicalDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CArithmeticLogicalDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ARITHMETIC_LOGICAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_comboImage1;
	CComboBox m_comboImage2;
	int m_nFunction2017136128;
	virtual BOOL OnInitDialog();
	void* m_pDoc1;
	void* m_pDoc2;
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit12017136128();
	CEdit id2017136128;
};
