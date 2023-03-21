#ifndef SPBSPU_LABS_2022_AAP_904_A_MEMBER_OF_SERIES_H
#define SPBSPU_LABS_2022_AAP_904_A_MEMBER_OF_SERIES_H
class MemberOfSeries
{
public:
  explicit MemberOfSeries(double x);
  double operator()();
private:
  double x;
  unsigned long long factorial;
  unsigned number;
};
#endif
