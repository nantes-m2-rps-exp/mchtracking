#ifdef __CLING__

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class o2::field::MagneticField + ;
#pragma link C++ class o2::field::MagneticWrapperChebyshev + ;
#pragma link C++ class o2::field::MagFieldParam + ;
#pragma link C++ class o2::field::MagFieldContFact + ;
#pragma link C++ class o2::field::MagFieldFact + ;
#pragma link C++ class o2::field::MagFieldFast + ;

#pragma link C++ class o2::math_utils::Chebyshev3D + ;
#pragma link C++ class o2::math_utils::Chebyshev3DCalc + ;

#endif
