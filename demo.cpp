#include <wx/wx.h>
#include "VardineAtkarpa3D.h"
#include "VardinisKubas3D.h"
#include "VardinisTrikampis3D.h"
#include "VardineSfera3D.h"

class Window : public wxFrame {
    private:
        VardinisKubas3D cube;
        VardinisTrikampis3D triangle;
        VardineSfera3D sfera;
    public:
        Window(VardinisKubas3D *c, VardininisTrikampis3D *t, VardineSfera3D *s) : wxFrame(nullptr, exID_ANY, "Figuros") {
            cube = *c;
            triangle = *t;
            sfera = *s;

            auto table = new wxBoxSizer(wxVERTICAL);
            // -----------
            auto row1 = new wxBoxSizer(wxHORIZONTAL);
            row1->Add(new wxStaticText(this, wxID_ANY, "Koord >>>"));
            auto lX = new wxTextCtrl(this, wxID_ANY);
            auto lY = new wxTextCtrl(this, wxID_ANY);
            auto lZ = new wxTextCtrl(this, wxID_ANY);
        }
};

class Program : public wxApp {
    public:
        virtual bool onInit() override {
           VardinisTaskas3D *t1 = new VardinisTaskas3D("A", "Taskas1", 1, 1, 1);
           VardinisTaskas3D *t2 = new VardinisTaskas3D("A", "Taskas1", 1, 1, 1);
           VardinisTaskas3D *t3 = new VardinisTaskas3D("A", "Taskas1", 1, 1, 1);

           VardinisKubas3D *k = new VardinisKubas3D("Q", "Kubas", t1, 4);
           VardinisTrikampis3D *t = new VardinisTrikampis3D("X", "Trikampis", t1, t2, t3);
           VardineSfera3D *s = new VardineSfera3D("S", "Sfera", 3, t3); 
           new Window(&k, &t, &s);
           return true;
        }
};

wxIMPLEMENT_APP(Program);