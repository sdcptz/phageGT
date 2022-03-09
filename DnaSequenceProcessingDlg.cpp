
// DnaSequenceProcessingDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DnaSequenceProcessing.h"
#include "DnaSequenceProcessingDlg.h"
#include "afxdialogex.h"
#include "resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//*******************************************

//#include "stdafx.h"
//#include "FastQ.h"
//#include "FastQDlg.h"

#include <vector>
#include <algorithm>
#include<iostream>
#include<cstdlib>
#include<ctime>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

using namespace std;
struct FQ
{
	CString strFq;
	int num;
};

//自定义排序中的“大于”
bool comp(const FQ& a, const FQ& b)
{
	return a.num > b.num;
}
//****************************************




// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDnaSequenceProcessingDlg 对话框



CDnaSequenceProcessingDlg::CDnaSequenceProcessingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DNASEQUENCEPROCESSING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDnaSequenceProcessingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDnaSequenceProcessingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDnaSequenceProcessingDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDnaSequenceProcessingDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CDnaSequenceProcessingDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDnaSequenceProcessingDlg::OnBnClickedButton2)
	ON_STN_CLICKED(IDC_BUTTON1, &CDnaSequenceProcessingDlg::OnStnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT2, &CDnaSequenceProcessingDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &CDnaSequenceProcessingDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDnaSequenceProcessingDlg 消息处理程序

BOOL CDnaSequenceProcessingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDnaSequenceProcessingDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDnaSequenceProcessingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
	//	dc.FillSolidRect(rect, RGB(248, 248, 255));
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
/*
		CBrush m_brBack;
		m_brBack.CreateSolidBrush(RGB(255,0,0));
		dc.FillRect(&rect, &m_brBack);
*/
/*
		CRect  m_rtThis;
		CRect rct;
		GetClientRect(&rct);
		CPaintDC dc(this);
		dc.SetBkMode(TRANSPARENT);
		dc.FillSolidRect(&m_rtThis, RGB(255, 0, 0));
*/	
/*
	//	CPaintDC dc(this);
		CRect rct;
		CBrush m_brBack;
		m_brBack.CreateSolidBrush(RGB(255,0,0));
			GetClientRect(&rct);
		dc.FillRect(&rct, &m_brBack);
*/

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDnaSequenceProcessingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CDnaSequenceProcessingDlg::OnBnClickedOk()
{

//	CString str;
	CString str;   //自定义序列数 第一个框
	GetDlgItemText(IDC_EDIT2, str); ///这儿就是取该输入框的值，并赋给str;
	int num = _ttoi(str);
//	MessageBox(str);//弹出对话框显示str的值。

	CString str2;   //基因组bp  第二个框
	GetDlgItemText(IDC_EDIT1, str2); ///这儿就是取该输入框的值，并赋给str;
	int num2 = _ttoi(str2);

//		MessageBox(str2);//弹出对话框显示str的值。



	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
//	SetDlgItemText(IDC_TEXT, "请导入文件");
	// TODO: Add extra validation here
//	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "序列文件(*.fq)|*.fq||", NULL);
//	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "数据文件(*.fq;*.txt)|*.fq;*.txt|All Files (*.*)|*.*||", NULL);
	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, "data files(*.fq;*.fastq;*.txt)|*.fq;*.fastq;*.txt|All Files (*.*)|*.*||", NULL);
	FileDlg.m_ofn.lpstrTitle = "Open data file";

	CString strfilename, strfilepath;
	long total = 0;
	clock_t start, end;
	if (IDOK == FileDlg.DoModal())
	{
		start = clock();	


//		SetDlgItemText(IDC_TEXT, "Data is being read, please wait patiently...");



		strfilepath = FileDlg.GetPathName();
		strfilename = FileDlg.GetFileName();

		SetDlgItemText(IDC_TEXT, strfilename+"is being read, please wait patiently...");


//		SetDlgItemText(IDC_TEXT, "Sorting data...");

	

	//	SetDlgItemText(IDC_TEXT, "Calculating R value...");

	//	SetDlgItemText(IDC_TEXT, "Data exporting...");


		vector<FQ> vData;
		vData.clear();

		CString str;
		FILE* fp = NULL;
		fp = fopen(strfilepath, "r");
		int i = 0;
		if (fp != NULL)
		{
			char ch, ch1[200];
		
			while (fread(&ch, 1, 1, fp)) //一直一个字符一个字符的连续读，直到读到空即文件末尾为止
			{
				if (ch == '/')    //如果连续读的时候碰到“/”符号则停下来  连续读两个字符以后就是序列  对于序列只读20个即可
				{                     
					total++;
					fread(&ch, 1, 1, fp); //读一个字符
					fread(&ch, 1, 1, fp);  //读一个字符

					memset(ch1, '\0', 199);  //清空ch1数组
				


					fread(ch1, 1, num, fp);    //对于序列读20个字符
				


					str.Format("%s", ch1);    //将str转换为和ch1一样的

					int size = vData.size();
					for (i=0; i < size; i++)    //遍历已经得到的不重复序列
					{
						if (str == vData[i].strFq) //若当前序列已存在，对其进行计数加一
						{
							vData[i].num++;
							break;
						}
					}
					if (i == size || size == 0) //若当前序列未找到，将其加入容器以便后续查找匹配
					{
						FQ fq;
						fq.strFq = str;
						fq.num = 1;
						vData.push_back(fq);
					}
				}
			}
		}
		fclose(fp);

		SetDlgItemText(IDC_TEXT, "Sorting data...");

		sort(vData.begin(), vData.end(), comp); //对所有序列进行排序，按出现的次数进行降序排列

		SetDlgItemText(IDC_TEXT, "Calculating R value...");
		
		//double big = vData[0].num; //最大次数
		//double avg = total/ vData.size();     //定义平均次数
		//double r = big / avg;      //定义r值
		double big = vData[0].num; //最高频率
//		num2 = num2 / 2;
		double avg = total/num2/2;     //平均频率
		double r = big / avg;      //定义r值


	    char str1[20];
		sprintf(str1, "%.1f", r);  //将r这个double类型的数据赋值给为str1这个char类型
		char str2[200] = "R value is:";
		strcat(str2, str1);
		char str3[50] = "   \r\nNo end";
		char str4[30] = "   \r\nThere are partial ends";
		char str5[30] = "   \r\nThere is a fixed end";
		char str6[44] = "   \r\nR is less than 0, the data is abnormal";
		if (r > 0 && r <= 30) 
		{
			strcat(str2, str3);
		}
		else if (r > 30 && r <= 100)
		{
			strcat(str2, str4);
		}
		else if (r > 100)
		{
			strcat(str2, str5);
		}
		else  
		{
			strcat(str2, str6);
		}

		SetDlgItemText(IDC_TEXT, "Data exporting...");

		CStdioFile file;
		CString strOutput;
		str = strfilename.Left(strfilename.GetLength() - 3);
		strOutput.Format("D:\\%s.txt", str);
		if (file.Open(strOutput, CFile::modeCreate | CFile::modeWrite))
		{
                                                                   //输出的序列文件的标题
			str.Format("%s  \n\n",str2);   //输出r值
			file.WriteString(str);

			str.Format("%s\n\n", "              sequence                          frequency           Percentage");   //输出的序列文件的标题
			file.WriteString(str);

			int size = vData.size();
			for (int i = 0; i < size; i++)
			{
//				str.Format("%s	%d	%4.4f\n\n", vData[i].strFq, vData[i].num, vData[i].num * 1.0 / total); //序列 次数 占比  //format   定义str的格式
				str.Format("%s	          %d	            %4.4f%s\n\n", vData[i].strFq, vData[i].num, vData[i].num * 1.0*100 / total,"%"); //序列 次数 占比  //format   定义str的格式
				file.WriteString(str);
			}
			file.Close();

			ShellExecute(NULL, "open", strOutput, NULL, NULL, SW_SHOWNORMAL);
		}
		end = clock();		//程序结束用时
		double endtime = (double)(end - start) / CLOCKS_PER_SEC;
		if (endtime < 60)   //秒 换算成分钟和小时
		{
			char a[200] = "  is exported to the root directory of Disk D";
			char b[5];
			char e[50] = "it takes time: ";
	//		char e[20]= "   \r\nNo end";
			sprintf(b, "%.1f", endtime);  //将endtime这个double类型的数据赋值给为b这个char类型
		//	strcat(a, b);      //b字符串接到a后边
	//		strcat(a, e);      //c字符串接到a后边
			char c[10] = " second";
			
			strcat(e, b);      //c字符串接到a后边
			strcat(e, c);      //c字符串接到a后边
	//		strcat(a, e);      //c字符串接到a后边

	
			SetDlgItemText(IDC_TEXT, strfilename + a);
			SetDlgItemText(IDC_STATIC5, e);
			SetDlgItemText(IDC_STATIC, str2);
			//SetDlgItemText(IDC_TEXT, "数据处理结束，文件导出至D盘根目录！");
		}

		else if (endtime >=60&&endtime<3600)
		{
			endtime = endtime / 60;
			char a[200] = "   is exported to the root directory of Disk D, and it takes time:";
			char b[5];
			char e[50] = "it takes time: ";
			sprintf(b, "%.1f", endtime);  //b将double类型转换为char类型
			strcat(a, b);      //b字符串接到a后边
			char c[7] = "minute";
			strcat(a, c);      //c字符串接到a后边
			
			strcat(e, b);      //c字符串接到a后边
			strcat(e, c);      //c字符串接到a后边

			SetDlgItemText(IDC_TEXT, strfilename + a); //更新上面的文本框
			SetDlgItemText(IDC_STATIC5, e);
			SetDlgItemText(IDC_STATIC, str2); //更新下面的文本框
			//SetDlgItemText(IDC_TEXT, "数据处理结束，文件导出至D盘根目录！");
		}
		else 
		{
			endtime = endtime / 3600;
			char a[200] = "   the file is exported to the root directory of Disk D, and it takes time:";
			char b[5];
			char e[50] = "it takes time: ";
			sprintf(b, "%.1f", endtime);  //b将double类型转换为char类型
			strcat(a, b);      //b字符串接到a后边
			char c[5] = "hour";
			strcat(a, c);      //c字符串接到a后边

			strcat(e, b);      //c字符串接到a后边
			strcat(e, c);      //c字符串接到a后边	

			SetDlgItemText(IDC_TEXT, strfilename + a);
			SetDlgItemText(IDC_STATIC5, e);
			SetDlgItemText(IDC_STATIC, str2);
			//SetDlgItemText(IDC_TEXT, "数据处理结束，文件导出至D盘根目录！");
		}


	}
	//CDialog::OnOK();
}


void CDnaSequenceProcessingDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CDnaSequenceProcessingDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//CAboutDlg Dlg;
	//Dlg.DoModal();
}


void CDnaSequenceProcessingDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CAboutDlg Dlg;
	Dlg.DoModal();
}


void CDnaSequenceProcessingDlg::OnStnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDnaSequenceProcessingDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CDnaSequenceProcessingDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
