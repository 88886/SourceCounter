#ifndef CUSTOMRULEDLG_H
#define CUSTOMRULEDLG_H

#ifndef WX_PRECOMP
//(*HeadersPCH(CustomRuleDlg)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dirdlg.h>
#include <wx/dialog.h>
//*)
#endif
//(*Headers(CustomRuleDlg)
//*)

#include "rule.h"
#include "ruleinfo.h"

class CustomRuleDlg: public wxDialog
{
public:

	enum RuleMode
	{
		RuleModeNew,
		RuleModeEdit,
	};

    CustomRuleDlg(wxWindow* parent, RuleMode nMode, wxWindowID id=wxID_ANY);
    virtual ~CustomRuleDlg();

    //(*Declarations(CustomRuleDlg)
    wxStaticText* StaticText2;
    wxRadioBox* m_rdbRuleType;
    wxStaticText* m_pLblCondition;
    wxButton* Button2;
    wxButton* m_btnOK;
    wxTextCtrl* m_txtDestPath;
    wxDirDialog* m_dirDlg;
    wxTextCtrl* m_txtCondition;
    wxButton* m_btnSelDir;
    //*)

    ///////////////////////////////////////////////////////////////////
	void SetRule(Rule* pRule)		{ m_pRule = pRule; }
	void GetRuleInfo(RuleInfo& info);

protected:

    //(*Identifiers(CustomRuleDlg)
    static const long ID_RADIOBOX2;
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTON3;
    //*)

private:

    //(*Handlers(CustomRuleDlg)
    void OnBtnOKClick(wxCommandEvent& event);
    void OnInit(wxInitDialogEvent& event);
    void OnBtnSelDirClick(wxCommandEvent& event);
    void OnRdbRuleTypeSelect(wxCommandEvent& event);
    //*)

    ///////////////////////////////////////////////////////////////////
	void initConditionLabel();

    ///////////////////////////////////////////////////////////////////
	RuleMode m_nMode;
	Rule* m_pRule;

	RuleInfo m_ruleInfo;

    ///////////////////////////////////////////////////////////////////


    DECLARE_EVENT_TABLE()
};

#endif
