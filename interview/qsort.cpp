#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

const int MAXN = 1000;

void qsort(int a[], int l, int r)
{
  int p = l, q = r;
  int mid = a[rand() % (r - l + 1) + l];

  do
  {
    while (a[p] < mid && p < q)  p ++;
    while (mid < a[q] && p < q)  q --;
    if (p <= q)
    {
      int tmp;
      tmp = a[p]; a[p] = a[q]; a[q] = tmp;
      p ++, q --;
    }
  }
  while (p < q);

  if (l < q)
    qsort(a, l, q);
  if (p < r)
    qsort(a, p, r);
}

int
main(int argc, char* argv[])
{
  int n;
  int a[MAXN];

  cin >> n;
  for (int i = 0; i < n; i ++)
    cin >> a[i];

  qsort(a, 0, n - 1);

  for (int i = 0; i < n; i ++)
    cout << a[i] << ' ';
  cout << endl;

  return 0;
}
