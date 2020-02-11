using namespace GeFiCa;
// calculate and save fields of an Inverted Coaxial Point-Contact (ICPC) HPGe
void calculateFields(const char *output="ICPC.root")
{
   PointContact detector;
   detector.Bias[0]=-10.000*kV; // bias on point contact
   detector.Bias[1]=0; // ground outer contact

   detector.Radius=5.00*cm; detector.Height=5.4*cm;

   detector.PointContactR=5.0*mm; detector.PointContactH=0.1*mm;

   detector.TaperW=6*mm; detector.TaperH=6*mm;		//PC side
   detector.CornerW=6*mm; detector.CornerH=6*mm;	//Bore side

   detector.BoreH=3.5*cm; detector.BoreR=10*mm;
   detector.BoreTaperH=35*mm; detector.BoreTaperW=10*mm;

   detector.WrapAroundR=3.0*cm;
   detector.GrooveH=0*mm; detector.GrooveW=0*mm;

   detector.BottomImpurity=2.68e10/cm3; detector.TopImpurity=2.06e10/cm3;

   int nr=500*2; // no point on r=0, please
   int nz=500+1; // precision: 0.1 mm
   RhoZ grid(nr,nz);
   grid.SetupWith(detector);
   grid.RelaxationFactor=1.994;
   grid.SuccessiveOverRelax();

   //cout<<grid.GetC()/pF<<endl;
   
   TFile file(output,"recreate");
   detector.Write();
   grid.Write();
   file.Close();
}
