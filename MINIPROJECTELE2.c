#include <stdio.h>
#include <conio.h>
#include <math.h>

float ft = 0.9343;
float basereactive = 56.07;
float service,total_ele,vat,total,eleft;

int calreactivepower(float powre,float rp)
{
    float totalres ;
    
    totalres=sqrt(pow(powre,2)+pow(rp,2));
	totalres=powre/totalres;
	if (totalres < 0.85)
	{
		totalres = (rp-(powre*61.97/100))*56.07;
	}
	else
	{
		totalres = 0;
	}
    return(totalres);
}

int calculator(float ele,int x, float y)
{
    eleft = ele;
    if (x == 0)
    {
        total = ele * y;
    }
    
    else if (x == 1)
    {
        if (ele >= 0 && ele <= 15)
        {
            total = ele * 2.3488;
        }
        else if (ele >= 16 && ele <= 25)
        {
            total = 15 * 2.3488;
            ele = ele - 15;
            ele = ele * 2.9882;
            total = total + ele;
        }
        else if (ele >= 26 && ele <= 35)
        {
            total = 15 * 2.3488;
            ele = ele - 15;
            total = total+(10 * 2.9882);
            ele = ele - 10;
            ele = ele * 3.2405;
            total = total + ele; 
        }
        else if (ele >= 36 && ele <= 100) 
        {
            total = 15 * 2.3488;
            ele = ele - 15;
            total = total+(10 * 2.9882); 
            ele = ele - 10; 
            total = total+(10 * 3.2405);
            ele = ele - 10;
            ele = ele * 3.6237;
            total = total + ele;
        }

        else if (ele >= 101 && ele <= 150) 
        {                           
            total = 15 * 2.3488;
            ele = ele - 15;
            total = total+(10 * 2.9882); 
            ele = ele - 10; 
            total = total+(10 * 3.2405); 
            ele = ele - 10;      
            total = total+(65 * 3.6237); 
            ele = ele - 65;      
            ele = ele * 3.7171;      
            total = total + ele; 
        }
        else if (ele >= 151 && ele <= 400)
        {
            total = 15 * 2.3488;
            ele = ele - 15;
            total = total+(10 * 2.9882); 
            ele = ele - 10; 
            total = total+(10 * 3.2405); 
            ele = ele - 10;      
            total = total+(65 * 3.6237); 
            ele = ele - 65;
            total = total+(50 * 3.7171);
            ele = ele - 50;
            ele = ele * 4.2218;
            total = total + ele;
        }
        else
        {
            total = 15 * 2.3488;
            ele = ele - 15;
            total = total+(10 * 2.9882); 
            ele = ele - 10; 
            total = total+(10 * 3.2405); 
            ele = ele - 10;      
            total = total+(65 * 3.6237); 
            ele = ele - 65;
            total = total+(50 * 3.7171);
            ele = ele - 50;
            total = total+(250 * 4.2218);
            ele = ele - 250;
            ele = ele * 4.4217;
            total = total + ele;
        }
    }
    else if (x == 2)
    {
        if (ele >= 0 && ele <= 150)
        {
            total = ele * 3.2484;
        }
        else if (ele >= 151 && ele <= 400)
        {
            total = 150 * 3.2484;
            ele = ele - 150;
            ele = ele * 4.2218;
            total = total + ele;
        }
        else
        {
            total = 150 * 3.2484;
            ele = ele - 150;
            total = total+(250 * 4.2218);
            ele = ele - 250;
            ele = ele * 4.4217;
            total = total + ele; 
        }
    }
    

    total_ele = total+service;
    printf("\nElectic energe = %.2f",total);
    printf("\nService = %.2f",service);
    printf("\nTotal electic = %.2f",total_ele);
    ft =  eleft*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    vat = (total_ele+ft)*7/100;
    printf("\nVAT = %.2f",vat);
    total_ele = total_ele+ft+vat;
    printf("\nTotal electic = %.2f",total_ele);
}

int calculatorTOU(float ele1,float peak,float ele2,float offpeak)
{
    total_ele = (ele1*peak)+(ele2*offpeak)+service;
    printf("\nElectic energe = %.2f",(ele1*peak)+(ele2*offpeak));
    printf("\nService = %.2f",service);
    printf("\nTotal electic = %.2f",total_ele);
    ft = (ele1+ele2)*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    vat = (total_ele+ft)*7/100;
    printf("\nVAT = %.2f",vat);
    total_ele = total_ele+ft+vat;
    printf("\nTotal electic = %.2f",total_ele);
}

int calculatorpowreq(float ele,float energe,float powre,float powreq,float rp)
{
    rp = calreactivepower(powre,rp);
    total_ele = (ele*energe)+(powre*powreq)+service;
    printf("\nElectic energe = %.2f",ele*energe);
    printf("\nService = %.2f",service);
    printf("\nReactive power = %.2f",rp);
    printf("\nTotal electic = %.2f",total_ele);
    ft = ele*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    vat = (total_ele+ft+rp)*7/100;
    printf("\nVAT = %.2f",vat);
    total_ele = total_ele+ft+rp+vat;
    printf("\nTotal electic = %.2f",total_ele);
}

int calculatorpowreqTOU(float peak,float peak2,float offpeak,float offpeak2,float powre,float powreq,float rp)
{
    rp = calreactivepower(powre,rp);
    total_ele = (peak*peak2)+(offpeak*offpeak2)+(powre*powreq)+service;
    printf("\nElectic energe = %.2f",(peak*peak2)+(offpeak*offpeak2)+(powre*powreq));
    printf("\nService = %.2f",service);
    printf("\nReactive power = %.2f",rp);
    printf("\nTotal electic = %.2f",total_ele);
    ft = (peak+offpeak)*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    vat = (total_ele+ft+rp)*7/100;
    printf("\nVAT = %.2f",vat);
    total_ele = total_ele+ft+rp+vat;
    printf("\nTotal electic = %.2f",total_ele);
}

int calculatorpowreqTOD(float peak,float peak2,float partial,float partial2,float ele,float ele2,float rp)
{
    float x;
    x = peak+partial;
    rp = calreactivepower(x,rp);
    total_ele = (peak*peak2)+(partial*partial2)+(ele*ele2)+service;
    printf("\nElectic energe = %.2f",(peak*peak2)+(partial*partial2)+(ele*ele2));
    printf("\nService = %.2f",service);
    printf("\nReactive power = %.2f",rp);
    printf("\nTotal electic = %.2f",total_ele);
    ft = (ele)*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    vat = (total_ele+ft+rp)*7/100;
    printf("\nVAT = %.2f",vat);
    total_ele = total_ele+ft+rp+vat;
    printf("\nTotal electic = %.2f",total_ele);
}

int calnonprofit(float ele, int x)
{
    eleft = ele;
    if (x == 1)
    {
        total = ele*3.4149;
    }
    else if (x == 2)
    {
        total = ele*3.5849;
    }
    else if (x == 3)
    {
        if (ele >= 0 && ele <= 10)
        {
            total = ele*2.8013;
        }
        else
        {
            total = 10*2.8013;
            ele = ele - 10;
            ele = ele*3.8919;
            total = total*ele;
        }
    }
    total_ele = total+service;
    printf("\nElectic energe = %.2f",total);
    printf("\nService = %.2f",service);
    printf("\nTotal electic = %.2f",total_ele);
    ft =  eleft*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    vat = (total_ele+ft)*7/100;
    printf("\nVAT = %.2f",vat);
    total_ele = total_ele+ft+vat;
    printf("\nTotal electic = %.2f",total_ele);
}

int personal(float ele,int x) //user personal
{
    if (x == 1) // user type use electic < 150
    {
        service = 8.19;
        calculator(ele,x,0);
    }
    else if (x == 2) // user type use electic > 150
    {
        service = 24.62;
        calculator(ele,x,0);
    }
    else
        printf("\nERROR");
}

int personalTOU(float peak,float offpeak,int x) //presonal tou user
{
    if (x == 1) //Voltage 22-33 kV
    {
        service = 312.24;
        calculatorTOU(peak,5.1135,offpeak,2.6037);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        service = 24.62;
        calculatorTOU(peak,5.7982,offpeak,2.6369);
    }
    else
        printf("\nERROR");
}

int smallbusiness(float ele,int x) //small business user
{
    if (x == 1) //Voltage 22-33 kV
    {
        service = 312.24;
        calculator(ele,0,3.9086);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        service = 33.29;
        calculator(ele,x,0);
    }
    else
        printf("\nERROR");
}

int smallbusinessTOU(float peak,float offpeak,int x) //small business tou user
{
    if (x == 1) //Voltage 22-33 kV
    {
        service = 312.24;
        calculatorTOU(peak,5.1135,offpeak,2.6037);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        service = 33.29;
        calculatorTOU(peak,5.7982,offpeak,2.6369);
    }
    else
        printf("\nERROR");
}

int mediumbusiness(float ele,float pr,float rp,int x)
{
    service = 312.24;
    if (x == 1) //Voltage 22-33 kV
    {
        calculatorpowreq(ele,3.1097,pr,175.70,rp);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        calculatorpowreq(ele,3.1471,pr,196.26,rp);
    }
    else if (x == 3)
    {
        calculatorpowreq(ele,3.1751,pr,221.50,rp);
    }
    
    else
        printf("\nERROR");
}

int mediumbusinessTOU(float peak,float offpeak,float pr,float rp,int x)
{
    service = 312.24;
    if (x == 1) //Voltage 22-33 kV
    {
        calculatorpowreqTOU(peak,4.1025,offpeak,2.5849,pr,74.14,rp);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        calculatorpowreqTOU(peak,4.1839,offpeak,2.6037,pr,132.93,rp);
    }
    else if (x == 3)
    {
        calculatorpowreqTOU(peak,4.3297,offpeak,2.6369,pr,210.00,rp);
    }
    else
        printf("\nERROR");
}

int bigbusiness(float peak,float partial,float ele,float rp,int x)
{
    service = 312.24;
    if (x == 1) //Voltage 22-33 kV
    {
        calculatorpowreqTOD(peak,224.30,partial,29.91,ele,3.1097,rp);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        calculatorpowreqTOD(peak,285.05,partial,58.88,ele,3.1471,rp);
    }
    else if (x == 3)
    {
        calculatorpowreqTOD(peak,332.71,partial,68.22,ele,3.1751,rp);
    }
    else
        printf("\nERROR");
}

int specificbusiness(float ele,float pr,float rp,int x)
{
    service = 312.24;
    if (x == 1) //Voltage 22-33 kV
    {
        calculatorpowreq(ele,3.1097,pr,220.56,rp);
    }
    else if (x == 2) //Voltage less than 22 kV
    {
        calculatorpowreq(ele,3.1471,pr,256.07,rp);
    }
    else if (x == 3)
    {
        calculatorpowreq(ele,3.1751,pr,276.64,rp);
    }
    
    else
        printf("\nERROR");
}

int nonprofit(float ele,int x)
{
    if(x == 1 || x == 2)
    {
        service = 312.24;
        calnonprofit(ele,x);
    }
    else if (x == 3)
    {
        service = 20;
        calnonprofit(ele,x);
    }
    
    else
        printf("\nERROR");
}

int pumpingwater(float ele)
{
    service = 115.16;
    eleft = ele;
    if (ele >= 0 && ele <= 100)
    {
        total = ele*2.0889;
    }
    else
    {
        total = 100*2.0889;
        ele = ele-100;
        ele = ele*3.2405;
        total = total+ele;
    }
    total_ele = total+service;
    printf("\nElectic energe = %.2f",total);
    printf("\nService = %.2f",service);
    printf("\nTotal electic = %.2f",total_ele);
    ft =  eleft*ft;
    printf("\nElectic energe * Ft = %.2f",ft);
    vat = (total_ele+ft)*7/100;
    printf("\nVAT = %.2f",vat);
    total_ele = total_ele+ft+vat;
    printf("\nTotal electic = %.2f",total_ele);
}

int main()
{
    int type;
    float electic,electic2,powerre,reactivepower;
    printf("1.Personal\n2.Personal TOU\n3.Small Business\n4.Small Business TOU\n5.Middle Business\n6.Medium Business TOU\n7.Big Business TOD\n8.Big Business TOU\n9.Specific Business TOU\n10.Specific Business not have TOU meters installed\n11.Non-profit organization\n12.Non-profit organization TOU\n13.Pumping water for agriculture\n14.Pumping water for agriculture TOU\n15.Temporary electricity\n");
    printf("Enter type electic : ");
    scanf("%d",&type);
    switch (type)
    {
    case 1:
        printf("Personal\n");
        printf("1.Use electic less than 150\n2.Use electic more than 150\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electic : ");
        scanf("%f",&electic);
        personal(electic,type);
        break;

    case 2:
        printf("Personal TOU\n");
        printf("1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electic (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electic (Off Peak): ");
        scanf("%f",&electic2);
        personalTOU(electic,electic2,type);
        break;

    case 3:
        printf("Small Business\n");
        printf("1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electic : ");
        scanf("%f",&electic);
        smallbusiness(electic,type);
        break;

    case 4:
        printf("Small Business TOU\n");
        printf("1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electic (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electic (Off Peak): ");
        scanf("%f",&electic2);
        smallbusinessTOU(electic,electic2,type);
        break;

    case 5:
        printf("Middle Business\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge : ");
        scanf("%f",&powerre);
        
        
        printf("Enter amout of electic : ");
        scanf("%f",&electic);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusiness(electic,powerre,reactivepower,type);
        break; 

    case 6:
        printf("Medium Business TOU\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electic (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electic (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 7:
        printf("Big Business TOD\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter Demand charge Partial : ");
        scanf("%f",&electic);
        printf("Enter amout of electic : ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        bigbusiness(powerre,electic,electic2,reactivepower,type);
        break;

    case 8:
        printf("Big Business TOU\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electic (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electic (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 9:
        printf("Specific Business TOU\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electic (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electic (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 10:
        printf("Specific Business not have TOU meters installed\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge : ");
        scanf("%f",&powerre);
        printf("Enter amout of electic : ");
        scanf("%f",&electic);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        specificbusiness(electic,powerre,reactivepower,type);
        break;

    case 11:
        printf("Non-profit organization\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter amout of electic : ");
        scanf("%f",&electic);
        nonprofit(electic,type);
        break;

    case 12:
        printf("Non-profit organization TOU\n");
        printf("\n1.Voltage more than 69 kV\n2.Voltage 22-33 kV\n3.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electic (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electic (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 13:
        printf("Pumping water for agriculture \n");
        printf("\nEnter amout of electic : ");
        scanf("%f",&electic);
        pumpingwater(electic);
        break;

    case 14:
        printf("Pumping water for agriculture TOU\n");
        printf("\n1.Voltage 22-33 kV\n2.Voltage less than 22 kV\n");
        printf("Enter type user : ");
        scanf("%d",&type);
        printf("Enter Demand charge Peak : ");
        scanf("%f",&powerre);
        printf("Enter amout of electic (Peak): ");
        scanf("%f",&electic);
        printf("Enter amout of electic (Off Peak): ");
        scanf("%f",&electic2);
        printf("Enter Reactive power : ");
        scanf("%f",&reactivepower);
        ++type;
        mediumbusinessTOU(electic,electic2,powerre,reactivepower,type);
        break;

    case 15:
        printf("Temporary electricity \n");
        printf("\nEnter amout of electic : ");
        scanf("%f",&electic);
        calculator(electic,0,6.8025);
        break;
    default:
        break;
    }
}
