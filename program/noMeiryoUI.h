/*
noMeiryoUI (C) 2005,2012-2022 Tatsuhiko Shoji
The sources for noMeiryoUI are distributed under the MIT open source license
*/
#ifndef NOMEIRYOUI_H
#define NOMEIRYOUI_H

#include "DialogAppliBase.h"
#include "TwrMenu.h"

#define EXE_NAME _T("noMeiryoUI.exe")
#define INI_FILE _T("noMeiryoUI.ini")
#define CONFIG_SECTION _T("Settings")
#define UIFONT_KEY _T("UIFontName")
#define MULTI_RUN_KEY _T("RunMultiple")

void initializeLocale(void);
BOOL CALLBACK MonitorNearMouseCallback(
	HMONITOR hMonitor,
	HDC hdcMonitor,
	LPRECT lprcMonitor,
	LPARAM dwData
);
BOOL CALLBACK MonitorNearWindowCallback(
	HMONITOR hMonitor,
	HDC hdcMonitor,
	LPRECT lprcMonitor,
	LPARAM dwData
);
BOOL CALLBACK setWindowSize(HWND hWnd, LPARAM lparam);
void setResourceFileName(TCHAR* langFileName, TCHAR* helpFileName, char* localeName, TCHAR *iniPath);

void setLocationInternalCode(TCHAR  langWork[85]);

/** �t�H���g�̃|�C���g����ۑ�����\���� */
struct FontPoints {
	/** �^�C�g���o�[�t�H���g�T�C�Y(Point) */
	double title;

	/** �A�C�R���t�H���g�T�C�Y(Point) */
	double icon;

	/** �p���b�g�^�C�g���t�H���g�T�C�Y(Point) */
	double palette;

	/** �c�[���`�b�v�t�H���g�T�C�Y(Point) */
	double hint;

	/** ���b�Z�[�W�{�b�N�X�t�H���g�T�C�Y(Point) */
	double message;

	/** ���j���[�t�H���g�T�C�Y(Point) */
	double menu;
};

class NoMeiryoUI : public DialogAppliBase {
private:

	enum fontType {
		all,
		title,
		icon,
		palette,
		hint,
		message,
		menu
	};

	tstring allFontName;
	tstring titleFontName;
	tstring iconFontName;
	tstring paletteFontName;
	tstring hintFontName;
	tstring messageFontName;
	tstring menuFontName;

	NONCLIENTMETRICS metrics;
	LOGFONT iconFont;
	FontPoints fontPoints;

	NONCLIENTMETRICS metricsAll;
	LOGFONT iconFontAll;

	bool noMeiryoUI;
	bool noTahoma;
	TwrWnd *verInfo;

	TwrMenu *appMenu;

	HFONT displayFont;

	HFONT allFont;
	HFONT titleFont;
	HFONT iconFontHandle;
	HFONT paletteFont;
	HFONT hintFont;
	HFONT messageFont;
	HFONT menuFont;

	TwrWnd *allFontTextBox;
	TwrWnd *titleFontTextBox;
	TwrWnd *iconFontTextBox;
	TwrWnd *paletteFontTextBox;
	TwrWnd *hintFontTextBox;
	TwrWnd *messageFontTextBox;
	TwrWnd *menuFontTextBox;

	TwrWnd* titleFontButton;

	DWORD buildNumber;
	int compatLevel;

	TCHAR settingFile[MAX_PATH];
	bool setOnStart;
	bool firstShow;

	void OnLoad();
	BOOL loadFontInfo(TCHAR *filename);
	BOOL loadFont(TCHAR *filename, TCHAR *section, LOGFONT *font);
	void OnSave();
	BOOL startSaveFont(TCHAR *filename);
	BOOL saveFont(TCHAR *filename, TCHAR *section, LOGFONT *font, double point);
	void selectFont(enum fontType type);
	void updateDisplay(void);

	INT_PTR OnBnClickedOk();
	void OnBnClickedAll();
	void OnSet8();
	void OnSet10(void);
	void OnSet11(void);
	void OnChoiceAppFont();
	void set11TitlePreset(NONCLIENTMETRICS *metrics);
	void SetWinVer(void);
	void getWin10Ver(TCHAR *buf, DWORD major, DWORD minor);
	int getDPI(void);

	void setFont(
		NONCLIENTMETRICS *fontMetrics,
		LOGFONT *iconLogFont,
		bool fromGui
	);
	void showHelp(void);
	HFONT createFont(LOGFONT *font);
	void getActualFont(void);
	void getOption(TCHAR *lpCmdLine);
	void parseOption(TCHAR *param, int argCount);
	void applyResource();
	void applyDisplayText();
	void applyDisplayFont();
	tstring getLanguageFallbackForCountry(tstring &settingString);
	void showVersion(void);
	void adjustWindowSize(void);
	void saveConfig(void);
	void loadConfig(void);
	void toggleWin7aliculate();
	void toggleMultiRun();
	void handleMultipleRun(void);

protected:
	INT_PTR OnCommand(WPARAM wParam);


public:
	BaseDialog *createBaseDialog();
	int OnAppliStart(TCHAR *lpCmdLine);
	int OnWindowShow();
	INT_PTR OnWindowShown(WPARAM wParam, LPARAM lParam);
	INT_PTR OnWindowCreated(WPARAM wParam, LPARAM lParam);
	int OnAppliEnd();
	INT_PTR OnInitDialog();
	void UpdateData(bool toObj);

};

#endif
