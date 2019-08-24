/***************************************************************************** 
 * Project: RooFit                                                           * 
 *                                                                           * 
 * This code was autogenerated by RooClassFactory                            * 
 *****************************************************************************/ 

// Your description goes here... 
#include "Math/Interpolator.h"

#include "Riostream.h" 
#include "RooNumIntConfig.h"
#include "RooRealVar.h" 

#include "../interface/SplinePdf.h" 
#include "RooAbsReal.h" 
#include "RooAbsCategory.h" 
#include "RooRealIntegral.h" 
#include <math.h> 
#include "TMath.h" 
#include "RooListProxy.h" 
#include "RooHistFunc.h" 

ClassImp(SplinePdf) 

	SplinePdf::SplinePdf(const char *name, const char *title, 
			RooAbsReal& _x, RooAbsReal& _a, RooAbsReal& _b, TSpline3 _spl ) :
		RooAbsPdf(name,title), 
		x("x","x",this,_x),
		a("a","a",this,_a),
		b("b","b",this,_b)
{ 
	spl = _spl;

	this->defaultIntegratorConfig()->method1D().setLabel("RooAdaptiveGaussKronrodIntegrator1D");
	this->defaultIntegratorConfig()->getConfigSection("RooAdaptiveGaussKronrodIntegrator1D").setRealValue("maxSeg",100) ; ;
	this->defaultIntegratorConfig()->setEpsAbs(1e-4) ;
	this->defaultIntegratorConfig()->setEpsRel(1e-4) ;


} 


SplinePdf::SplinePdf(const SplinePdf& other, const char* name) :  
	RooAbsPdf(other,name), 
	x("x",this,other.x),
	a("a",this,other.a),
	b("b",this,other.b)
{ 
	spl=other.spl;
	this->defaultIntegratorConfig()->setEpsAbs(1e-4) ;
	this->defaultIntegratorConfig()->setEpsRel(1e-4) ;
	this->defaultIntegratorConfig()->method1D().setLabel("RooAdaptiveGaussKronrodIntegrator1D");
	this->defaultIntegratorConfig()->getConfigSection("RooAdaptiveGaussKronrodIntegrator1D").setRealValue("maxSeg",100) ; ;
} 



Double_t SplinePdf::evaluate() const 
{ 

	double cost = spl.Eval(x); 
	double prop = 1./(pow((x*x-a*a),2)+b*b*a*a);
	//double extfact=1;
	//if(x<180)
	//	extfact = -47.6817+x*1.21397-0.0113538*pow(x,2)+4.71652e-05*pow(x,3)-7.33857e-08*pow(x,4);
	////		extfact = -12.0136+x*0.242836-0.00151242*pow(x,2)+3.13356e-06*pow(x,3); 
	//return cost*prop*x*x*extfact;
	return cost*prop*x*x;
} 

