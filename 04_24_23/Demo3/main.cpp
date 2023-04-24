#include <CtrlLib/CtrlLib.h>

using namespace Upp;

struct MyAppWindow : TopWindow 
{
	Switch base;
	Switch size;
	Switch temp;
	DropList dairy;
	Option flavor[10];
	
	MyAppWindow()
	{
		Title("Drink Order").Zoomable().Sizeable();
		
		Add(base.LeftPos(170, MAXSIZE).TopPos(10));
		base.Add("Coffee");
		base.Add("Tea");
		base.Add("Cream");
		Add(size.LeftPos(170, MAXSIZE).TopPos(50));
		size.Add("Small");
		size.Add("Medium");
		size.Add("Large");
		Add(temp.LeftPos(170,MAXSIZE).TopPos(90));
		temp.Add("Hot");
		temp.Add("Iced");
		temp.Add("Blend");
		Add(dairy.LeftPos(170,200).TopPos(130));
		dairy.Add("None");
		dairy.Add("Skim Milk");
		dairy.Add("Whole Milk");
		dairy.Add("Oat Milk");
		dairy.Add("Cream");
		dairy.Add("Almond Milk");
		Add(flavor[0].LeftPos(170).TopPos(170));
		
		Add(flavor[1].LeftPos(flavor[0].GetSize().cx).TopPos(170));
		Add(flavor[2].LeftPos(flavor[1].GetSize().cx + 110).TopPos(170));
		Add(flavor[3].LeftPos(flavor[2].GetSize().cx + 250).TopPos(170));
		Add(flavor[4].LeftPos(flavor[3].GetSize().cx + 430).TopPos(170));
		Add(flavor[5].LeftPos(170).TopPos(210));
		Add(flavor[6].LeftPos(flavor[5].GetSize().cx + 70).TopPos(210));
		Add(flavor[7].LeftPos(480).TopPos(210));
		Add(flavor[8].LeftPos(650).TopPos(210));
		Add(flavor[9].LeftPos(800).TopPos(210));
		
		
	
		
		flavor[0].SetLabel("Almond");
		flavor[1].SetLabel("Apple");
		flavor[2].SetLabel("Blueberry");
		flavor[3].SetLabel("Butter Pecan");
		flavor[4].SetLabel("Caramel");
		flavor[5].SetLabel("French Vanilla");
		flavor[6].SetLabel("Peach");
		flavor[7].SetLabel("Peppermint");
		flavor[8].SetLabel("Raspberry");
		flavor[9].SetLabel("Strawberry");
		
		
		
	};
	virtual void Paint(Draw& w) override 
	{
		w.DrawRect(GetSize(), SWhite());
		w.DrawText(10,10, "Drink Base:");
		w.DrawText(10, 50, "Drink Size:");
		w.DrawText(10, 90, "Drink Temp:");
		w.DrawText(10, 130, "Drink Dairy:");
		w.DrawText(10, 170, "Drink Flavors:");
	};
};

GUI_APP_MAIN
{
	MyAppWindow app;
	app.Run();
}
