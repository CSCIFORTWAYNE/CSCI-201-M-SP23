#include <CtrlLib/CtrlLib.h>
#include <iomanip>
#include "drink.h"

using namespace Upp;

struct MyAppWindow : TopWindow 
{
	Switch base;
	Switch size;
	Switch temp;
	DropList dairy;
	Option flavor[10];
	Label baseLbl;
	Label sizeLbl;
	Label tempLbl;
	Label dairyLbl;
	Label flavLbl;
	Label priceLbl;
	EditString price;
	Button createBtn;
	ColumnList drinkList;
	Label listLbl;
	
	
	MyAppWindow()
	{
		Title("Drink Order").Zoomable().Sizeable();
		baseLbl.SetLabel("Drink Base:");
		sizeLbl.SetLabel("Drink Size:");
		tempLbl.SetLabel("Drink Temperature:");
		dairyLbl.SetLabel("Dairy Choice:");
		flavLbl.SetLabel("Flavors:");
		priceLbl.SetLabel("Price:");
		
		base.Add(COFFEE,"Coffee");
		base.Add(TEA,"Tea");
		base.Add(CREAM,"Cream");
		base.SetVertical();
		Add(baseLbl.LeftPosZ(10,104).TopPosZ(10));
		Add(base.LeftPosZ(124, 200).TopPosZ(10,48));
		
		
		size.Add(SMALL,"Small");
		size.Add(MED,"Medium");
		size.Add(LARGE,"Large");
		size.SetVertical();
		Add(sizeLbl.LeftPosZ(10,104).TopPosZ(78));
		Add(size.LeftPosZ(124, 200).TopPosZ(78, 48));
		
		
		
		temp.Add(HOT, "Hot");
		temp.Add(ICE,"Iced");
		temp.Add(BLEND,"Blend");
		temp.SetVertical();
		Add(tempLbl.LeftPosZ(10, 104).TopPosZ(146));
		Add(temp.LeftPosZ(124,200).TopPosZ(146,48));
		
		
		
		dairy.Add("None");
		dairy.Add("Skim Milk");
		dairy.Add("Whole Milk");
		dairy.Add("Oat Milk");
		dairy.Add("Cream");
		dairy.Add("Almond Milk");
		Add(dairyLbl.LeftPosZ(10, 104).TopPosZ(214));
		Add(dairy.LeftPosZ(124,200).TopPosZ(214,20));
		
		flavor[0].SetLabel("Almond");
		flavor[0].SetData(ALMOND);
		flavor[1].SetLabel("Apple");
		flavor[2].SetLabel("Blueberry");
		flavor[3].SetLabel("Butter Pecan");
		flavor[4].SetLabel("Caramel");
		flavor[5].SetLabel("French Vanilla");
		flavor[6].SetLabel("Peach");
		flavor[7].SetLabel("Peppermint");
		flavor[8].SetLabel("Raspberry");
		flavor[9].SetLabel("Strawberry");
		
		Add(flavLbl.LeftPosZ(10,104).TopPosZ(252));
		int top = 20;
		int x = 0;
		int left = 104;
		for(int i = 0; i < 10; i++)
		{
			Add(flavor[i].LeftPosZ(124 + left*(i%2),104).TopPosZ(252 + top*x));
			if(i % 2 == 1)
			{
				x++;
			}
			
		}
		x++;
		price.Disable();
		Add(priceLbl.LeftPosZ(10, 104).TopPosZ(252 + top *x));
		Add(price.LeftPosZ(124,200).TopPosZ(252 + top *x,20));	
		
		x++;
		x++;
		
		createBtn.SetLabel("Create Drink");
		Add(createBtn.LeftPosZ(10,324).TopPosZ(252 + top *x, 20));
		
		createBtn << [=] {
			std::string flav;
			for(int i = 0; i < 10; i++)
			{
				if(flavor[i].Get())
					flav += flavor[i].GetLabel() + " ";	
			}
			
			drink d(static_cast<baseType>((int)base.GetData()),
					static_cast<tempType>((int)temp.GetData()),
					static_cast<sizeType>((int)size.GetData()),
					dairy.GetData().ToStd());
			std::ostringstream priceStr;
			priceStr << std::setprecision(2) << std::fixed << std::showpoint;
			priceStr << "$" << d.getPrice();
			price.SetData(priceStr.str());
			std::ostringstream drinkStr;
			drinkStr << d;
			drinkList.Add(drinkStr.str(),false);
		};
		
		listLbl.SetLabel("Drinks Created:");
		drinkList.Disable();
		Add(listLbl.LeftPosZ(352,84).TopPosZ(10));
		Add(drinkList.LeftPosZ(352,400).TopPosZ(30,300));
		
		
		
		
		
	
		
		
		
		
	};

};

GUI_APP_MAIN
{
	MyAppWindow app;
	app.Run();
}
