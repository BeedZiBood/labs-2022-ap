double calculationExp(double x, double absError, unsigned numberMax)
{
  double res = 1.0;
  unsigned members = 1;
  double sum = 0.0;
  double divicible = x * (-1);
  unsigned divider = 1;
  do
  {
    sum = divicible / divider;
    res += sum;
    members++;
    divicible *= x * (-1);
    divider *= members;
  }
  while (members < numberMax || sum > absError);
  return res;
}
